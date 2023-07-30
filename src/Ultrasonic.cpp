#include "Ultrasonic.h"
#include "Balance.h"
#include "Pins.h"
#include "LED.h"
#include <Arduino.h>

extern Balance balance;
extern Led led;

void Ultrasonic::Init() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

double Ultrasonic::distance;

void Ultrasonic::Get_Distance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  Ultrasonic::distance = duration * 0.0344 / 2;
}

void Ultrasonic::ObjectIsDetected() {
  FOUND_OBJECT ? balance.Forward(40), led.Front(led.Color(0, 255, 0)) : balance.Stop();
}
