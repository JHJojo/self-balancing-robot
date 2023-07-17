#include "Motor.h"
#include <Arduino.h>

Motor motor;

#define SPEED 150

char strbuf[][50] = {"Forward:encoder_count_right_a:", "Forward:encoder_count_left_a:",
                     "Back:encoder_count_right_a:",    "Back:encoder_count_left_a:",
                     "Left:encoder_count_right_a:",    "Left:encoder_count_left_a:",
                     "Right:encoder_count_right_a:",   "Right:encoder_count_left_a:"};

void setup() {
  motor.Pin_init();
  motor.Encoder_init();
  Serial.begin(9600);
}

void loop() {
  for (int i = 0, j = 0; i < 4, j < 8; i++) {
    (motor.*(motor.MOVE[i]))(SPEED);
    delay(2000);
    Serial.print(strbuf[j++]);
    Serial.println(motor.encoder_count_right_a);
    Serial.print(strbuf[j++]);
    Serial.println(motor.encoder_count_left_a);
    motor.encoder_count_right_a = 0;
    motor.encoder_count_left_a = 0;
  }
}