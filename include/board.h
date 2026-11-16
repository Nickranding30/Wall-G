#pragma once
#include <stdint.h>

// Leds
const uint8_t PIN_LED  = 2;

// Joystick
const uint8_t PIN_JOY_X = 34;
const uint8_t PIN_JOY_Y = 35;

// RF Transceivers
const uint8_t PIN_CE   = 4;
const uint8_t PIN_CSN  = 5;

// Motor driver 1 (TB6612FNG, channel A)
const uint8_t PIN_PWMA_D1 = 13;
const uint8_t PIN_AIN1_D1 = 12;
const uint8_t PIN_AIN2_D1 = 14;

// Motor driver 1 (TB6612FNG, channel B)
const uint8_t PIN_PWMB_D1 = 25;
const uint8_t PIN_BIN1_D1 = 26;
const uint8_t PIN_BIN2_D1 = 27;

// Motor driver 2 (TB6612FNG, channel A)
const uint8_t PIN_PWMA_D2 = 21;
const uint8_t PIN_AIN1_D2 = 15;
const uint8_t PIN_AIN2_D2 = 33;

// Motor driver 2 (TB6612FNG, channel B)
const uint8_t PIN_PWMB_D2 = 17;
const uint8_t PIN_BIN1_D2 = 32;
const uint8_t PIN_BIN2_D2 = 22;