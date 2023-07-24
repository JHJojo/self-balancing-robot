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
  ultrasonic.Get_Distance();

  if (millis() - follow_prev_time >= 100) {
    IR_TRIGGERED ? infrared.ObjectIsDetected() : ultrasonic.ObjectIsDetected();

    follow_prev_time = millis();
  }
}