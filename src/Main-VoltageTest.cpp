#include <Arduino.h>
#include "Voltage.h"

Voltage voltage;

void setup() {
  Serial.begin(9600);
  voltage.Init();
}

void loop() 
{
    voltage.VoltageMeasure();
    Serial.print("Voltage: ");
    Serial.println(voltage.voltage);
}


