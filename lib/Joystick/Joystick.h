#pragma once
#include <Arduino.h>

class Joystick {
public:
    /**
     * Constructs a Joystick object with specified X and Y pin numbers.
     * @param xPin The analog pin number for the X-axis.
     * @param yPin The analog pin number for the Y-axis.
     */
    Joystick(uint8_t xPin, uint8_t yPin);

    /**
     * Reads the X-axis value of the joystick.
     * @return The X-axis value (0-4095).
     */
    int readX();

    /**
     * Reads the Y-axis value of the joystick.
     * @return The Y-axis value (0-4095).
     */
    int readY();

private:
    uint8_t _xPin;
    uint8_t _yPin;
};