#include "Balance.h"
#include "MPU.h"
#include "Motor.h"
#include "Pins.h"
#include <Arduino.h>

extern Mpu mpu;
extern Motor motor;
extern Balance balance;
#define TARGETANGLE -2.5 //better value after attached fall support (without value should be 0)

Balance::Balance() {
  // initialize PID parameters
  kp_vertical = 40, kd_vertical = 0.8;
  kp_speed = 10, ki_speed = 0.26;
  kp_steering = 1, ki_steering = 0.1;
}

void Balance::Get_EncoderSpeed() {
  // Update encoder pulse counts into speed variables
  encoder_left_pulse_num_speed +=
      pwm_left < 0 ? (-Motor::encoder_count_left_a) : Motor::encoder_count_left_a;
  encoder_right_pulse_num_speed +=
      pwm_right < 0 ? (-Motor::encoder_count_right_a) : Motor::encoder_count_right_a;
  Motor::encoder_count_left_a = 0;
  Motor::encoder_count_right_a = 0;
}

void Balance::PID_Vertical() {
  // PD control for vertical balance (no I parameter at the moment could be added later, but is not mandatory)
  balance_control_output =
    kp_vertical * (mpu.roll - TARGETANGLE) + kd_vertical * (((mpu.roll - TARGETANGLE) - (mpu.prevRoll - TARGETANGLE)) / 5);
}

void Balance::PID_Steering() {
  steering_control_output = kp_steering * (mpu.gyroZ - setting_turn_speed) + ki_steering * steering_control_integral;
  steering_control_integral += (mpu.gyroZ - setting_turn_speed);
  // steering_control_integral += -setting_turn_speed;
}

void Balance::PID_Speed() {
  // get average speed
  double car_speed = (encoder_left_pulse_num_speed + encoder_right_pulse_num_speed) / 2;
  encoder_left_pulse_num_speed = 0;
  encoder_right_pulse_num_speed = 0;

  // lowpass speed filter to attenuated short-tern changes in velocity
  speed_filter = speed_filter_old * 0.7 + car_speed * 0.3;
  speed_filter_old = speed_filter;

  // calculate speed integral and limit it to a certain range
  car_speed_integeral += speed_filter;
  car_speed_integeral += -setting_car_speed;
  car_speed_integeral = constrain(car_speed_integeral, -3000, 3000);

  // PI control for horizontal position (no D parameter at the moment could be added later, but is not mandatory)
  speed_control_output = -kp_speed * speed_filter - ki_speed * car_speed_integeral;
}

void Balance::Total_Control() {
  // calculate PWM values for the motors
  pwm_left = balance_control_output - speed_control_output + steering_control_integral;
  pwm_right = balance_control_output - speed_control_output - steering_control_integral;

  // limit PWM values to the range [-255, 255]
  pwm_left = constrain(pwm_left, -255, 255);
  pwm_right = constrain(pwm_right, -255, 255);

  unsigned long time;

  // stop motors when the robot falls
  while (mpu.roll > 27 || mpu.roll < -27) {
    mpu.DataProcessing();
    motor.Stop();
    speed_control_output = 0;
    balance_control_output = 0;
    speed_filter = 0;
    car_speed_integeral = 0;
    speed_filter_old = 0;
    steering_control_integral = 0;
    steering_control_output = 0;
    if (millis() - time >= 5000) {
      motor.Forward(250);
      delay(45);
      time = millis();
      if (first_start == false)
      {
        encoder_left_pulse_num_speed = 200;
        encoder_right_pulse_num_speed = 200;
        first_start = true;
      }
    }
  }

  // control motors (forward or backward) based on PWM values
  /*if (pwm_left < 0)
  {
    motor.Back(-pwm_left);
  }else
  {
    motor.Forward(pwm_left);
  }*/

  // cleaner implementation to include rotation later
    (pwm_left < 0) ? (motor.Control(AIN1, 1, PWMA_LEFT, -pwm_left))
                   : (motor.Control(AIN1, 0, PWMA_LEFT, pwm_left));

    (pwm_right < 0) ? (motor.Control(BIN1, 1, PWMB_RIGHT, -pwm_right))
                    : (motor.Control(BIN1, 0, PWMB_RIGHT, pwm_right));
}

void Balance::Stop() {
  setting_car_speed = 0;
  setting_turn_speed = 0;
}

void Balance::Forward(int car_speed) {
  setting_car_speed = car_speed;
  setting_turn_speed = 0;
}

void Balance::Back(int car_speed) {
  setting_car_speed = -car_speed;
  setting_turn_speed = 0;
}

void Balance::Left(int turn_speed) {
  setting_car_speed = 0;
  setting_turn_speed = turn_speed;
}

void Balance::Right(int turn_speed) {
  setting_car_speed = 0;
  setting_turn_speed = -turn_speed;
}
