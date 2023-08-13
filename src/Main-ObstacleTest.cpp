#include "Balance.h"
#include "Follow.h"
#include "I2Cdev.h"
#include "Infrared.h"
#include "LED.h"
#include "MPU.h"
#include "Motor.h"
#include "Timer2.h"
#include "Ultrasonic.h"
#include "Wire.h"
#include "Obstacle.h"
#include <Arduino.h>


Ultrasonic ultrasonic;
Timer2 timer2;
Mpu mpu;
Motor motor;
Balance balance;
Infrared infrared;
Obstacle obstacle;
Led led;

unsigned int follow_prev_time = 0;

void setup() {
  mpu.Init();
  //ultrasonic.Init();
  infrared.Init();
  motor.Pin_init();
  motor.Encoder_init();
  timer2.Init(timer2.time);
  led.Init();
  Serial.begin(9600);
  delay(100);
}

void loop() {
  obstacle.Obstacle_Mode();
}