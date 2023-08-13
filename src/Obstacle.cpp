#include "Obstacle.h"
#include "Balance.h"
#include "Infrared.h"
#include "LED.h"
#include "Ultrasonic.h"
#include <Arduino.h>

// external instances of classes
extern Ultrasonic ultrasonic;
extern Infrared infrared;
extern Balance balance;
extern Led led;

void Obstacle::Obstacle_Mode() {
  infrared.Send();

  if (millis() - follow_prev_time >= 100) {
    Serial.println(millis());
    ultrasonic.Get_Distance();
    follow_prev_time = millis();
    balance.Forward(25);
    led.Front(led.Color(0, 255, 0));

    // make small corrections when obstacle is close and ultrasonic sensor is not recognizing it
    infrared.Send();
    infrared.ObjectIsDetectedObstacle();
    delay(100);

    // handle obstacle avoidance behavior
    while (ultrasonic.distance < Obstacle_MIN) {
      balance.Stop();

      if (millis() - obstacle_time > 4000) {
        obstacle_time = millis();
        go_back_time = millis();
        // Serial.println("Here: 1");

        while (millis() - go_back_time < 500) {
          balance.Back(25);
          led.Back(led.Color(0, 255, 0));
          // Serial.println("Here: 2");
        }
      }

      turning_time = millis();
      while (millis() - turning_time < 750) {
        // Serial.println("Here: 3");
        infrared.Send();
        if (turn_flag) {
          turn_flag = 0;
          infrared.ObjectIsDetectedObstacle();
          delay(300);
          // Serial.println("Here: 4");
        }
        turn_flag = 1;
      }
      // Serial.println("Here: 5");
      ultrasonic.Get_Distance();
    }
  }
  obstacle_time = millis();
}