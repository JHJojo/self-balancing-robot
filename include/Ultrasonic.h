#ifndef Ultrasonic_H
#define Ultrasonic_H

class Ultrasonic {
public:
  void Init();
  void Get_Distance();
  void ObjectIsDetected();

  static double distance;

private:
  double duration;
  
  #define DISTANCE_MIN 3
  #define DISTANCE_MAX 30
  #define FOUND_OBJECT (distance > DISTANCE_MIN && distance < DISTANCE_MAX)
};
#endif