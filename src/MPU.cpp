#include "MPU.h"
#include "MPU6050.h"

MPU6050 mpu6050;

void Mpu::Init() {
  Wire.begin();
  mpu6050.initialize();
  mpu6050.setXAccelOffset(-509);
  mpu6050.setYAccelOffset(-2474);
  mpu6050.setZAccelOffset(1644);
  mpu6050.setXGyroOffset(153);
  mpu6050.setYGyroOffset(70);
  mpu6050.setZGyroOffset(-9);
}

void Mpu::DataProcessing() {
  // read acceleration values ​​and gyro rates
  int16_t ax, ay, az, gx, gy, gz;
  mpu6050.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // convert raw acceleration values ​​into G-forces (+-2G sensitivity)
  // float accelX = ax / 16384.0;
  float accelY = ay / 16384.0;
  float accelZ = az / 16384.0;

  // roll angle calculation with accelerometer
  float accelRoll = atan2(accelY, accelZ) * RAD_TO_DEG;

  // roll angle calculation with gyroscope
  float gyroRoll = gx / 131.0;
  gyroZ = gz / 131.0;

  // final roll angle calculation with the complementary filter
  roll = alpha * (prevRoll + gyroRoll * dt) + (1 - alpha) * accelRoll;

  prevRoll = roll;
}