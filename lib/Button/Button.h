#pragma once
#include <Arduino.h>

class Button {
public:
    Button(uint8_t buttonPin);

    void init();
    bool isPressed();

private:
    uint8_t _pin;
};