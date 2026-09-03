#pragma once
#include <Arduino.h>

class Led {
public:
    Led(uint8_t ledPin);

    void init();
    void on();
    void off();

private:
    uint8_t _pin;
};