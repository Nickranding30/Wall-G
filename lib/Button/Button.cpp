#include "Button.h"

Button::Button(uint8_t buttonPin) {
    _pin = buttonPin;
}

void Button::init() {
    pinMode(_pin, INPUT_PULLUP);
}

bool Button::isPressed() {
    return digitalRead(_pin) == LOW;
}