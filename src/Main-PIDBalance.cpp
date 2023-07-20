#include "Balance.h"
#include "I2Cdev.h"
#include "MPU.h"
#include "Motor.h"
#include "Timer2.h"
#include "Wire.h"
#include "math.h"
#include <Arduino.h>

Timer2 timer2;
Mpu mpu;
Motor motor;
Balance balance;

void setup() {
  motor.Pin_init();
  motor.Encoder_init();
  timer2.init(timer2.time);
  mpu.init();
  Serial.begin(9600);
  delay(100);
}

void loop() { }