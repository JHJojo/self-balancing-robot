#ifndef Mpu_H
#define Mpu_H

class Mpu {
public:
  void Init();
  // calculates angle of robot
  void DataProcessing();

  float roll;
  float prevRoll = 0;
  float gyroZ;

private:
  // constants for the complementary filter
  const float alpha = 0.98; // weighting factor for the gyroscope
  const float dt = 0.01;    // sampling time in seconds
};
#endif