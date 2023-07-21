#include "Timer2.h"
#include "Balance.h"
#include "MPU.h"
#include "MsTimer2.h"

extern Mpu mpu;
extern Balance balance;

void Timer2::Init(int time) {
  MsTimer2::set(time, interrupt);
  MsTimer2::start();
}

void Timer2::interrupt() {
  sei(); // enable the global interrupt
  balance.Get_EncoderSpeed();
  mpu.DataProcessing();
  balance.PID_Vertical();
  balance.interrupt_cnt++;
  // call PID_Speed() every 8 interrupt cycles (currently every 40 ms)
  if (balance.interrupt_cnt > 8) {
    balance.interrupt_cnt = 0;
    balance.PID_Speed();
    balance.PID_Steering();
  }
  balance.Total_Control();
}