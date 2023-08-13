#include "Voltage.h"
#include "LED.h"
#include <Arduino.h>

Voltage voltage;
Led led;

void setup() {
  led.Init();
  Serial.begin(9600);
  voltage.Init();
}

void loop() {
  voltage.VoltageMeasure();
  Serial.print("Voltage: ");
  Serial.println(voltage.voltage);
}
