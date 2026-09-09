/**
 * @file Led.h
 * @brief Led class for controlling an LED
 */

#pragma once
#include <Arduino.h>

class Led {
public:
    /**
     * Constructs a Led object with the specified pin number.
     * @param ledPin The pin number to which the LED is connected.
     */
    Led(uint8_t ledPin);


    /**
     * Initializes the LED pin as output.
     */
    void init();
    
    /**
     * Turns the LED on.
     */
    void on();
    
    /**
     * Turns the LED off.
     */
    void off();

private:
    uint8_t _pin;
};