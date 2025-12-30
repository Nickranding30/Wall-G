/*
  Drive.h - Library for driving motors forward, backwards, and brake.
  Created by Nicholas Randing, December 27, 2025.
*/

#ifndef Drive_h
#define Drive_h

#include "Arduino.h"

class Drive
{
  public:
    Drive(int pinA1, int pinA2, int pinB1, int pinB2);
    void begin();
    void forward();
    void backward();
    void brake();
  private:
    int _pinA1;
    int _pinA2;
    int _pinB1;
    int _pinB2;

};

#endif