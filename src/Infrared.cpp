#include "Infrared.h"
#include "Balance.h"
#include "Pins.h"
#include <Arduino.h>

extern Balance balance;

void Infrared::Send() {
  static unsigned long ir_send_time;

  if (millis() - ir_send_time > 15) {
    for (int i = 0; i < 39; i++) {
      digitalWrite(IR_SEND_PIN, LOW);
      delayMicroseconds(9);
      digitalWrite(IR_SEND_PIN, HIGH);
      delayMicroseconds(9);
    }
    ir_send_time = millis();
  }
}

int Infrared::left_is_obstacle;
int Infrared::right_is_obstacle;
unsigned int Infrared::left_count;
unsigned int Infrared::right_count;
void Infrared::Left_Receive()
{ 
   left_is_obstacle=1;
}
void Infrared::Right_Receive()
{ 
   right_is_obstacle=2;
}

void Infrared::Check() {
  int motion = left_is_obstacle + right_is_obstacle;
  switch (motion) {
  case FOLLOW_LEFT:
    balance.setting_turn_speed = 50;
    balance.setting_car_speed = 0;
    left_is_obstacle = 0;
    break;
  case FOLLOW_RIGHT:
    balance.setting_turn_speed = -50;
    balance.setting_car_speed = 0;
    right_is_obstacle = 0;
    break;
  case FOLLOW_BACK:
    balance.setting_car_speed = -10;
    balance.setting_turn_speed = 0;
    left_is_obstacle = 0;
    right_is_obstacle = 0;
    break;
  default:
    balance.setting_car_speed =  0;
    balance.setting_turn_speed = 0;
    left_is_obstacle = 0;
    right_is_obstacle = 0;
    break;
  }
}


