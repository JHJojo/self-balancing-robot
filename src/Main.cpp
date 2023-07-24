#include "Balance.h"
#include "Follow.h"
#include "I2Cdev.h"
#include "Infrared.h"
#include "MPU.h"
#include "Motor.h"
#include "Timer2.h"
#include "Ultrasonic.h"
#include "Voltage.h"
#include "Wire.h"
#include "math.h"
#include <Arduino.h>


Ultrasonic ultrasonic;
Timer2 timer2;
Mpu mpu;
Motor motor;
Balance balance;
Voltage voltage;
Infrared infrared;
Follow follow;

int follow_prev_time = 0;

void setup() {
  voltage.Init();
  motor.Pin_init();
  motor.Encoder_init();
  timer2.Init(timer2.time);
  mpu.Init();
  ultrasonic.Init();
  infrared.Init();
  Serial.begin(9600);
  delay(100);
}

void loop() {
  voltage.VoltageMeasure();
  follow.Follow_Mode();
}
