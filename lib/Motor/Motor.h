/**
 * @file Motor.h
 * @brief Motor class for controlling a motor using PWM and direction pins
 */

#pragma once
#include <Arduino.h>

class Motor {
public:
    /**
     * Constructs a Motor object with the specified PWM and direction pin numbers.
     * @param pwmPin The pin number for the PWM signal.
     * @param in1Pin The pin number for the first direction signal.
     * @param in2Pin The pin number for the second direction signal.
     */
    Motor(uint8_t pwmPin, uint8_t in1Pin, uint8_t in2Pin);

    /**
     * Initializes the motor pins as outputs.
     */
    void init();

    /**
     * Sets the speed of the motor.
     * @param speed The speed value (-255 to 255). Positive -> forward, negative -> reverse, zero -> stop.
     */
    void setSpeed(int speed);

private:
    uint8_t _pwmPin;
    uint8_t _in1Pin;
    uint8_t _in2Pin;
};