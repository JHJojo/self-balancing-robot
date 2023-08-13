#include "Control.h"
#include <Arduino.h>

unsigned long button_time = 0;
int Control::button_value = 0;

void Control::Button_State() {
  if (millis() - button_time > 500) {
    button_time = millis();

    button_value++;

    if (button_value >= 4) {
      button_value = 0;
    }
  }
}

void Control::Button_Event_Handler() {
  // handle different button values by assigning corresponding function states
  switch (button_value) {
  case 1:
    function_state = FOLLOW;
    break;
  case 2:
    function_state = OBSTACLE;
    break;
  case 3:
    function_state = LED;
    break;
  default:
    function_state = IDLE;
    break;
  }
}