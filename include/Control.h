#ifndef Control_H
#define Control_H

#include "State.h"

class Control {
public:
  void Init();
  // button state control function
  static void Button_State();
  // handle button events
  void Button_Event_Handler();

  static int button_value;
  FUNCTION_STATE function_state;
};

#endif