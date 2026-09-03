/**
 * @file protocol.h
 * @brief Defines the radio communication protocol for sending motor speed commands.
 */

#pragma once
#include <stdint.h>

const byte RADIO_ADDRESS[6] = "NODE1";
const uint8_t RADIO_CHANNEL = 76;

/**
 * @struct Packet
 * @brief Represents a data packet for radio communication.
 */
struct Packet {
    int16_t speed;   // -255..255, negative = reverse
};