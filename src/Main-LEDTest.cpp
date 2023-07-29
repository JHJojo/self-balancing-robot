#include "LED.h"
#include <Arduino.h>

Led led;

void setup() {
  led.Init();
  Serial.begin(9600);
  delay(100);
}

void loop() {
  led.ColorWipe(led.Color(0,0,255),1000);
  delay(100);
  led.Rainbow(50);
}
