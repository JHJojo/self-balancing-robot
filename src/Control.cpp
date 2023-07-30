#include "Control.h"
#include <Arduino.h>

unsigned long button_time = 0;
int Control::button_value = 0;

void Control::Button_State() {
  if (millis() - button_time > 500) {
    button_time = millis();

    button_value++;

    if (button_value >= 3) {
      button_value = 0;
    }
  }
}

void Control::Button_Event_Handler() {
  switch (button_value) {
  case 1:
    function_state = FOLLOW;
    break;
  case 2:
    function_state = LED;
    break;

  default:
    function_state = IDLE;
    break;
  }
}