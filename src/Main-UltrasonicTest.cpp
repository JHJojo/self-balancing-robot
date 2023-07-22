#include "Balance.h"
#include "I2Cdev.h"
#include "MPU.h"
#include "Motor.h"
#include "Timer2.h"
#include "Ultrasonic.h"
#include "Wire.h"
#include "math.h"
#include <Arduino.h>

Ultrasonic ultrasonic;
Timer2 timer2;
Mpu mpu;
Motor motor;
Balance balance;

int follow_prev_time = 0;

void setup() {
  motor.Pin_init();
  motor.Encoder_init();
  timer2.Init(timer2.time);
  mpu.Init();
  ultrasonic.Init();
  Serial.begin(9600);
  delay(100);
}

void loop() {
  ultrasonic.Get_Distance();

  if (millis() - follow_prev_time >= 100) {
    ultrasonic.ObjectIsDetected();
    follow_prev_time = millis();
  }
}
