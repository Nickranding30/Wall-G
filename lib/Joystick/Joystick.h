#pragma once
#include <Arduino.h>

class Joystick {
public:
    Joystick(uint8_t xPin, uint8_t yPin);

    int readX();
    int readY();

private:
    uint8_t _xPin;
    uint8_t _yPin;
};