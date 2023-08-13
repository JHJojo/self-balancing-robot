#ifndef State_H
#define State_H

enum FUNCTION_STATE
{
  IDLE,
  FOLLOW,
  OBSTACLE,
  LED
};

enum MOTION_STATE
{
  STANDBY,
  FORWARD,
  BACKWARD,
  TURNLEFT,
  TURNRIGHT,
  STOP,
  START
};

#endif
