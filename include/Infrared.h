#ifndef Infrared_H
#define Infrared_H

class Infrared {
public:
  void Init();
  // handle follow mode object detection
  void ObjectIsDetectedFollow();
  // handle obstacle mode object detection
  void ObjectIsDetectedObstacle();
  // send infrared signal
  void Send();
  static void Left_Receive();
  static void Right_Receive();

  static unsigned char left_receive_flag;

  static unsigned char right_receive_flag;

  static int left_is_obstacle;
  static int right_is_obstacle;

private:
  double duration;

#define IR_TRIGGERED (infrared.left_is_obstacle || infrared.right_is_obstacle)
};

enum FOLLOW_MOTION
{
  FOLLOW_LEFT = 1,
  FOLLOW_RIGHT,
  FOLLOW_BACK,
};

#endif