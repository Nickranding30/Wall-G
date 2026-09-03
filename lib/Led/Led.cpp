#include "Led.h"

Led::Led(uint8_t ledPin) {
    _pin = ledPin;
}

void Led::init() {
    pinMode(_pin, OUTPUT);
}

void Led::on() {
    digitalWrite(_pin, HIGH);
}

void Led::off() {
    digitalWrite(_pin, LOW);
}