#pragma once
#include <RF24.h>
#include "protocol.h"

class Radio {
public:
    Radio(uint8_t cePin, uint8_t csnPin);

    bool init(bool asTransmitter);
    bool send(const Packet &packet);
    bool receive(Packet &packet);

private:
    RF24 _radio;
};