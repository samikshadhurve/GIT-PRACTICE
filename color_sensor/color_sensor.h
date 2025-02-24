#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
#include"arduino.h"

class color_sensor{
  private:
  int data = 0; 
  #define s0 10       
  #define s1 9
  #define s2 13
  #define s3 11
  #define out 8
  public:
  color_sensor();
  void get_redvalue();
  void get_bluevalue();
  void get_greenvalue();
  void get_data();
  void get_20_frequency();
  void get_2_frequency();
  
  };

#endif
  
