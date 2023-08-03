#include "Ultrasonic.h"
#include "Balance.h"
#include "Pins.h"
#include "LED.h"
#include "HCSR04.h"
#include <Arduino.h>

extern Balance balance;
extern Led led;
HCSR04 hc_sr04(TRIG_PIN,ECHO_PIN);

/*void Ultrasonic::Init() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}*/

double Ultrasonic::distance;

void Ultrasonic::Get_Distance() {
  /*digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  Ultrasonic::distance = duration * 0.0344 / 2;*/
  Ultrasonic::distance = hc_sr04.dist();
}

void Ultrasonic::ObjectIsDetected() {
  FOUND_OBJECT ? balance.Forward(40), led.Front(led.Color(0, 255, 0)) : balance.Stop();
}
