#ifndef Obstacle_H
#define Obstacle_H

#define Obstacle_MIN 40

class Obstacle {
public:
  void Obstacle_Mode();

private:
  unsigned long follow_prev_time;
  unsigned long obstacle_time;
  unsigned long go_back_time;
  unsigned long turning_time;
  int turn_flag = 1;
};
#endif