#ifndef Timer2_H
#define Timer2_H

class Timer2 {
public:
  void Init(int time);
  // main interrupt which triggers the different PID functions
  static void interrupt();
  
  int time = 5; // every 5ms
};
#endif