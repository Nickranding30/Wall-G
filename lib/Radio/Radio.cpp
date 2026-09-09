#include "Radio.h"
#include "protocol.h"

Radio::Radio(uint8_t cePin, uint8_t csnPin) : _radio(cePin, csnPin) {}

bool Radio::init(bool asTransmitter) {
    if (!_radio.begin()) return false;

    _radio.setPALevel(RF24_PA_LOW);
    _radio.setDataRate(RF24_250KBPS);
    _radio.setChannel(RADIO_CHANNEL);

    if (asTransmitter) {
        _radio.openWritingPipe(RADIO_ADDRESS);
        _radio.stopListening();
    } else {
        _radio.openReadingPipe(0, RADIO_ADDRESS);
        _radio.startListening();
    }
    return true;
}

bool Radio::send(const Packet &packet) {
    return _radio.write(&packet, sizeof(packet));
}

bool Radio::receive(Packet &packet) {
    if (!_radio.available()) return false;
    _radio.read(&packet, sizeof(packet));
    return true;
}