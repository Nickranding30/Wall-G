#pragma once
#include <Arduino.h>

class Motor {
public:
    Motor(uint8_t pwmPin, uint8_t in1Pin, uint8_t in2Pin);

    void init();
    void setSpeed(int speed);

private:
    uint8_t _pwmPin;
    uint8_t _in1Pin;
    uint8_t _in2Pin;
};