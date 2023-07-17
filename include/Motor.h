#ifndef Motor_H
#define Motor_H

class Motor {
public:
  Motor();
  void Pin_init();
  void Encoder_init();

  // getting right wheel speed.
  static void EncoderCountRightA();
  // getting left wheel speed.
  static void EncoderCountLeftA();

  // functions to control movement of the motors
  void (Motor::*MOVE[4])(int speed);
  void Stop();
  void Forward(int speed);
  void Back(int speed);
  void Left(int speed);
  void Right(int speed);

  // control motor individually
  void Control(int AIN1_value, int BIN1_value, int PWM_pin, int speed);

public:
  static unsigned long encoder_count_right_a;
  static unsigned long encoder_count_left_a;
};
#endif
