#include "Motor.h"
#include "PinChangeInt.h"
#include "Infrared.h"
#include "Pins.h"
#include "Control.h"

void Motor::Encoder_init() {
  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT_A_PIN), EncoderCountLeftA, CHANGE);
  // Arduino Nano only has two hardware interrupt pins -> use PCI on pin 4 to gain a third interrupt pin
  attachPinChangeInterrupt(ENCODER_RIGHT_A_PIN, EncoderCountRightA, CHANGE);
}

void Infrared::Init() {
  pinMode(LEFT_RECEIVE_PIN, INPUT_PULLUP);
  pinMode(RIGHT_RECEIVE_PIN, INPUT_PULLUP);
  pinMode(IR_SEND_PIN, OUTPUT);
  attachPinChangeInterrupt(LEFT_RECEIVE_PIN, Left_Receive, FALLING);
  attachPinChangeInterrupt(RIGHT_RECEIVE_PIN, Right_Receive, FALLING);
}

void Control::Init(){
  pinMode(BUTTON, INPUT_PULLUP);
  attachPinChangeInterrupt(BUTTON, Button_State, FALLING);
}