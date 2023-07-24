#ifndef Infrared_H
#define Infrared_H

class Infrared {
public:
  void Init();
  void Check();
  void Send();
  void Filter();
  static void Left_Receive();
  static void Right_Receive();

  static unsigned char left_receive_flag;
  static unsigned int left_count;

  static unsigned char right_receive_flag;
  static unsigned int right_count;

  unsigned long left_count_time = 0;
  static int left_is_obstacle;
  static int right_is_obstacle;

private:
  double duration;

#define IR_TRIGGERED (Infrared.left_is_obstacle || Infrared.right_is_obstacle)
};

enum FOLLOW_MOTION
{
  NOTHING,
  FOLLOW_LEFT,
  FOLLOW_RIGHT,
  FOLLOW_BACK,
};

#endif