#include "Motor.h"

Motor::Motor(uint8_t pwmPin, uint8_t in1Pin, uint8_t in2Pin) {
    _pwmPin = pwmPin;
    _in1Pin = in1Pin;
    _in2Pin = in2Pin;
}

void Motor::init() {
    pinMode(_pwmPin, OUTPUT);
    pinMode(_in1Pin, OUTPUT);
    pinMode(_in2Pin, OUTPUT);
}

void Motor::setSpeed(int speed) {
    speed = constrain(speed, -255, 255);

    if (speed > 0) {
        digitalWrite(_in1Pin, HIGH);
        digitalWrite(_in2Pin, LOW);
    } else if (speed < 0) {
        digitalWrite(_in1Pin, LOW);
        digitalWrite(_in2Pin, HIGH);
    } else {
        digitalWrite(_in1Pin, LOW);
        digitalWrite(_in2Pin, LOW);
    }

    analogWrite(_pwmPin, abs(speed));
}