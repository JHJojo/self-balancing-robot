#include "Balance.h"
#include "Control.h"
#include "Follow.h"
#include "I2Cdev.h"
#include "Infrared.h"
#include "LED.h"
#include "MPU.h"
#include "Motor.h"
#include "State.h"
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
Led led;
Control control;

unsigned int follow_prev_time = 0;

void setup() {
  voltage.Init();
  mpu.Init();
  ultrasonic.Init();
  infrared.Init();
  motor.Pin_init();
  motor.Encoder_init();
  timer2.Init(timer2.time);
  led.Init();
  control.Init();
  Serial.begin(9600);
  delay(100);
}

void loop() {
  voltage.VoltageMeasure();
  control.Button_Event_Handler();
  if (control.function_state == IDLE) {
    balance.setting_car_speed = 0;
    balance.setting_turn_speed = 0;
  } else if (control.function_state == FOLLOW) {
    follow.Follow_Mode();
  } else if (control.function_state == LED) {
    balance.setting_car_speed = 0;
    balance.setting_turn_speed = 0;
    led.ColorWipe(led.Color(0, 0, 255), 1000);
    led.Off();
  }
}