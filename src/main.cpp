#include <Arduino.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "math.h"

MPU6050 mpu;

//constants for the complementary filter
const float alpha = 0.98;  //weighting factor for the gyroscope
const float dt = 0.01;     //sampling time in seconds

float roll;
float prevRoll = 0;

void setup() {
  Wire.begin();
  mpu.initialize();

  //set offset values ​​for the MPU
  mpu.setXAccelOffset(-509);
  mpu.setYAccelOffset(-2474);
  mpu.setZAccelOffset(1644);
  mpu.setXGyroOffset(153);
  mpu.setYGyroOffset(70);
  mpu.setZGyroOffset(-9);

  Serial.begin(9600);
}

void loop() {
  //read acceleration values ​​and gyro rates
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  //convert raw acceleration values ​​into G-forces (+-2G sensitivity)
  float accelX = ax / 16384.0;
  float accelY = ay / 16384.0;
  float accelZ = az / 16384.0;

  //roll angle calculation with accelerometer
  float accelRoll = atan2(accelY, accelZ) * RAD_TO_DEG;

  //roll angle calculation with gyroscope
  float gyroRoll = gx / 131.0;

  //final roll angle calculation with the complementary filter
  roll = alpha * (prevRoll + gyroRoll * dt) + (1 - alpha) * accelRoll;

  Serial.print("Roll: ");
  Serial.print(roll);

  prevRoll = roll;

  delay(10);
}