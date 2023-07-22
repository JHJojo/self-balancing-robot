#ifndef Voltage_H
#define Voltage_H

class Voltage {
public:
  void Init();

  void VoltageMeasure();

  double voltage;

private:
  unsigned long vol_measure_time = 0;
  int low_voltage_flag = 1;
};
#endif