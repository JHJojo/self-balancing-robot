#ifndef Control_H
#define Control_H

#include "State.h"

class Control{
public:
    
    void Init();
    static void Button_State();

    void Button_Event_Handler();
    
    static int button_value;
    FUNCTION_STATE function_state;

};

#endif