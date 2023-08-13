#include "Balance.h"
#include "I2Cdev.h"
#include "MPU.h"
#include "Motor.h"
#include "Timer2.h"
#include "Infrared.h"
#include "Wire.h"
#include "LED.h"	
#include <Arduino.h>

Infrared infrared;
Timer2 timer2;
Mpu mpu;
Motor motor;
Balance balance;
Led led;

unsigned long follow_prev_time = 0;

void setup() {
  led.Init();
  motor.Pin_init();
  motor.Encoder_init();
  timer2.Init(timer2.time);
  mpu.Init();
  infrared.Init();
  Serial.begin(9600);
  delay(100);
}

void loop() {
  infrared.Send();

  if (millis() - follow_prev_time >= 100) {
    Serial.println(follow_prev_time);
    infrared.ObjectIsDetectedFollow();
    follow_prev_time = millis();
  }
}
