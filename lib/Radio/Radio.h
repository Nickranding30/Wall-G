/**
 * @file Radio.h
 * @brief Radio class for handling RF24 radio communication
 */

#pragma once
#include <RF24.h>
#include "protocol.h"

class Radio {
public:
    /**
     * Constructs a Radio object with specified CE and CSN pin numbers.
     * @param cePin The pin number for the CE signal.
     */
    Radio(uint8_t cePin, uint8_t csnPin);

    /**
     * Initializes the radio module.
     * @param asTransmitter Set to true if the radio is used as a transmitter, false if used as a receiver.
     * @return True if initialization was successful, false otherwise.
     */
    bool init(bool asTransmitter);

    /**
     * Sends a data packet.
     * @param packet The packet to send.
     * @return True if the packet was sent successfully, false otherwise.
     */
    bool send(const Packet &packet);
    /**
     * Receives a data packet.
     * @param packet The packet to receive.
     * @return True if a packet was received successfully, false otherwise.
     */
    bool receive(Packet &packet);

private:
    RF24 _radio;
};