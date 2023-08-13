#include "Follow.h"
#include "Infrared.h"
#include "Ultrasonic.h"
#include "Voltage.h"
#include <Arduino.h>

// external instances of classes
extern Ultrasonic ultrasonic;
extern Infrared infrared;
extern Voltage voltage;

void Follow::Follow_Mode() {
  infrared.Send();
  
  if (millis() - follow_prev_time >= 100) {
    ultrasonic.Get_Distance();
    
    //DEBUG
    /*Serial.print("check: ");
    Serial.println(millis());
    Serial.print("distance: ");
    Serial.println(ultrasonic.distance);*/

    // check if an object is detected (either using infrared or ultrasonic)
    // call corresponding detection functions from Infrared or Ultrasonic classes
    IR_TRIGGERED ? infrared.ObjectIsDetectedFollow() : ultrasonic.ObjectIsDetected();

    follow_prev_time = millis();
  }
}