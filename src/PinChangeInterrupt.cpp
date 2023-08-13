#include "Motor.h"
#include "PinChangeInt.h"
#include "Infrared.h"
#include "Pins.h"
#include "Control.h"

// initialize encoder interrupts for left and right wheel
void Motor::Encoder_init() {
  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT_A_PIN), EncoderCountLeftA, CHANGE);
  // Arduino Nano only has two hardware interrupt pins -> use PCI on pin 4 to gain a third interrupt pin
  attachPinChangeInterrupt(ENCODER_RIGHT_A_PIN, EncoderCountRightA, CHANGE);
}

// initialize infrared sensor pins and attach pin change interrupts for IR receiving
void Infrared::Init() {
  // set left and right receive pins as input with internal pull-up resistors
  pinMode(LEFT_RECEIVE_PIN, INPUT_PULLUP);
  pinMode(RIGHT_RECEIVE_PIN, INPUT_PULLUP);

  pinMode(IR_SEND_PIN, OUTPUT);

  // attach pin change interrupts to handle IR sensor input changes
  attachPinChangeInterrupt(LEFT_RECEIVE_PIN, Left_Receive, FALLING);
  attachPinChangeInterrupt(RIGHT_RECEIVE_PIN, Right_Receive, FALLING);
}

// initialize the control button pin and attach a pin change interrupt to handle button events
void Control::Init(){
  // set button pin as input with internal pull-up resistor
  pinMode(BUTTON, INPUT_PULLUP);
  // attach pin change interrupt to handle button press events
  attachPinChangeInterrupt(BUTTON, Button_State, FALLING);
}