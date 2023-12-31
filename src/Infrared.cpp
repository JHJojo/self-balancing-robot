#include "Infrared.h"
#include "Balance.h"
#include "Pins.h"
#include "LED.h"
#include <Arduino.h>

// external instances of classes
extern Balance balance;
extern Led led;

void Infrared::Send() {
  static unsigned long ir_send_time;

  if (millis() - ir_send_time > 15) {
    for (int i = 0; i < 39; i++) {
      // send an infrared signal by modulating the IR_SEND_PIN
      digitalWrite(IR_SEND_PIN, LOW);
      delayMicroseconds(9);
      digitalWrite(IR_SEND_PIN, HIGH);
      delayMicroseconds(9);
    }
    ir_send_time = millis();
  }
}

int Infrared::left_is_obstacle;
int Infrared::right_is_obstacle;
void Infrared::Left_Receive() { left_is_obstacle = 1; }
void Infrared::Right_Receive() { right_is_obstacle = 2; }

void Infrared::ObjectIsDetectedFollow() {
  int motion = left_is_obstacle + right_is_obstacle;
  switch (motion) {
  case FOLLOW_LEFT:
    balance.Left(50);
    led.Left(led.Color(0, 255, 0));
    left_is_obstacle = 0;
    break;
  case FOLLOW_RIGHT:
    balance.Right(50);
    led.Right(led.Color(0, 255, 0));
    right_is_obstacle = 0;
    break;
  case FOLLOW_BACK:
    balance.Back(30);
    led.Back(led.Color(0, 255, 0));
    left_is_obstacle = 0;
    right_is_obstacle = 0;
    break;
  default:
    balance.Stop();
    left_is_obstacle = 0;
    right_is_obstacle = 0;
    break;
  }
}

void Infrared::ObjectIsDetectedObstacle() {
  int motion = left_is_obstacle + right_is_obstacle;
  switch (motion) {
  case FOLLOW_LEFT:
    balance.Right(75);
    led.Right(led.Color(0, 255, 0));
    left_is_obstacle = 0;
    break;
  case FOLLOW_RIGHT:
    balance.Left(75);
    led.Left(led.Color(0, 255, 0));
    right_is_obstacle = 0;
    break;
  case FOLLOW_BACK:
    balance.Back(30);
    led.Back(led.Color(0, 255, 0));
    left_is_obstacle = 0;
    right_is_obstacle = 0;
    break;
  }
}
