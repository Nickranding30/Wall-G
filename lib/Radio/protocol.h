#pragma once
#include <stdint.h>

const byte RADIO_ADDRESS[6] = "NODE1";
const uint8_t RADIO_CHANNEL = 76;

struct Packet {
    int16_t speed;   // -255..255, negative = reverse
};