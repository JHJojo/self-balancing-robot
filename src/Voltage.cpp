#include "Voltage.h"
#include "Pins.h"
#include <Arduino.h>

void Voltage::Init() { analogReference(INTERNAL); }

void Voltage::VoltageMeasure() {
  if (millis() - vol_measure_time > 1000) {
    vol_measure_time = millis();
    // calculate voltage based on voltage divider
    voltage = (analogRead(VOL_MEASURE_PIN) * 1.1 / 1024) * ((10 + 1.5) / 1.5);

    if (voltage > 7.8) {
      if (low_voltage_flag == 1) {
        //TODO: enum which acts as a state machine 
        digitalWrite(STBY_PIN, HIGH);
      }
      low_voltage_flag = 0;
    } 
    else {
      if (voltage < 7.0) // battery is low in power and needs to be charged.
      {
        //TODO: enum which acts as a state machine 
        digitalWrite(STBY_PIN, LOW);
      }
      low_voltage_flag = 1;
    }
  }
}