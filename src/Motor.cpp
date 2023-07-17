#include "Motor.h"
#include "PinChangeInt.h"
#include "Pins.h"
#include <Arduino.h>

void Motor::Pin_init() {
  pinMode(AIN1, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(PWMA_LEFT, OUTPUT);
  pinMode(PWMB_RIGHT, OUTPUT);
  pinMode(STBY_PIN, OUTPUT);
  digitalWrite(STBY_PIN, HIGH);
}

Motor::Motor() {
  MOVE[0] = &Motor::Forward;
  MOVE[1] = &Motor::Back;
  MOVE[2] = &Motor::Left;
  MOVE[3] = &Motor::Right;
}

void Motor::Stop() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(BIN1, HIGH);
  analogWrite(PWMA_LEFT, 0);
  analogWrite(PWMB_RIGHT, 0);
}

void Motor::Forward(int speed) {
  digitalWrite(AIN1, 0);
  digitalWrite(BIN1, 0);
  analogWrite(PWMA_LEFT, speed);
  analogWrite(PWMB_RIGHT, speed);
}

void Motor::Back(int speed) {
  digitalWrite(AIN1, 1);
  digitalWrite(BIN1, 1);
  analogWrite(PWMA_LEFT, speed);
  analogWrite(PWMB_RIGHT, speed);
}

void Motor::Left(int speed) {
  digitalWrite(AIN1, 1);
  digitalWrite(BIN1, 1);
  analogWrite(PWMA_LEFT, speed);
  analogWrite(PWMB_RIGHT, 0);
}

void Motor::Right(int speed) {
  digitalWrite(AIN1, 1);
  digitalWrite(BIN1, 1);
  analogWrite(PWMA_LEFT, 0);
  analogWrite(PWMB_RIGHT, speed);
}

void Motor::Control(int PIN, int PIN_value, int PWM_pin, int speed) {
  digitalWrite(PIN, PIN_value);
  analogWrite(PWM_pin, speed);
}

void Motor::Encoder_init() {
  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT_A_PIN), EncoderCountLeftA, CHANGE);
  // Arduino Nano only has two hardware interrupt pins -> use PCI on pin 4 to gain a third interrupt pin
  attachPinChangeInterrupt(ENCODER_RIGHT_A_PIN, EncoderCountRightA, CHANGE);
}

unsigned long Motor::encoder_count_right_a;
void Motor::EncoderCountRightA() { Motor::encoder_count_right_a++; }

unsigned long Motor::encoder_count_left_a;
void Motor::EncoderCountLeftA() { Motor::encoder_count_left_a++; }
