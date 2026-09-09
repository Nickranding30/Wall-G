#include "Joystick.h"

Joystick::Joystick(uint8_t xPin, uint8_t yPin) {
    _xPin = xPin;
    _yPin = yPin;
}

int Joystick::readX() {
    return analogRead(_xPin);
}

int Joystick::readY() {
    return analogRead(_yPin);
}