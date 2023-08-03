#include "Follow.h"
#include "Infrared.h"
#include "Ultrasonic.h"
#include "Voltage.h"
#include <Arduino.h>

extern Ultrasonic ultrasonic;
extern Infrared infrared;
extern Voltage voltage;

void Follow::Follow_Mode() {
  infrared.Send();
  
  if (millis() - follow_prev_time >= 100) {
    ultrasonic.Get_Distance();
    /*Serial.print("check: ");
    Serial.println(millis());
    Serial.print("distance: ");
    Serial.println(ultrasonic.distance);*/
    IR_TRIGGERED ? infrared.ObjectIsDetected() : ultrasonic.ObjectIsDetected();

    follow_prev_time = millis();
  }
}