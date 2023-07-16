#include "Motor.h"
#include "PinChangeInt.h"
#include "Pins.h"

void Motor::Encoder_init()
{
  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT_A_PIN), EncoderCountLeftA, CHANGE);
  attachPinChangeInterrupt(ENCODER_RIGHT_A_PIN, EncoderCountRightA, CHANGE);
}

unsigned long Motor::encoder_count_right_a;
// getting right wheel speed.
void Motor::EncoderCountRightA()
{
  Motor::encoder_count_right_a++;
}

unsigned long Motor::encoder_count_left_a;
// getting left wheel speed.
void Motor::EncoderCountLeftA()
{
  Motor::encoder_count_left_a++;
}
