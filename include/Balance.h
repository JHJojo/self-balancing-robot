#ifndef Balance_H
#define Balance_H

class Balance {
public:
  Balance();
  // get speed of each wheel
  void Get_EncoderSpeed();
  // function to keep the robot in a stable vertical position
  void PID_Vertical();
  // function to stabilize the z-axis of the robot
  void PID_Steering();
  // function to stabilize the horizontal position of the robot
  void PID_Speed();

  // function to set motor speed based on PID controllers
  void Total_Control();

  // speed values
  double pwm_left;
  double pwm_right;
  int encoder_left_pulse_num_speed;
  int encoder_right_pulse_num_speed;

  int interrupt_cnt;

  // PID parameter
  double kp_balance, kd_balance;
  double kp_speed, ki_speed;
  double kd_turn;

  double speed_filter;
  double speed_filter_old;
  double car_speed_integeral;
  double balance_control_output;
  double rotation_control_output;
  double speed_control_output;
  double setting_turn_speed = 0;
  double setting_car_speed = 0;
};
#endif
