/**
 * @file Button.h
 * @brief Button class for handling button input
 */


#pragma once
#include <Arduino.h>

class Button {
public:
    Button(uint8_t buttonPin);

    // Initializes button pin as input
    void init();

    // Returns true if button is pressed (active low)
    bool isPressed();

private:
    uint8_t _pin;
};