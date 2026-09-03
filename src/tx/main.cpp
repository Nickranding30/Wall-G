#include <Arduino.h>
#include "Radio.h"
#include "Joystick.h"
#include "protocol.h"
#include "board.h"

Radio radio(PIN_CE, PIN_CSN);
Joystick joystick(PIN_JOY_X, PIN_JOY_Y);

void setup() {
    Serial.begin(115200);

    if (!radio.init(true)) {
        Serial.println("radio failed");
        while (1) delay(1000);
    }
    Serial.println("role: TX");
}

void loop() {
    int raw = joystick.readY();
    int offset = raw - 2048;

    if (abs(offset) < 400) {
        offset = 0;
    }

    Packet packet;
    packet.speed = constrain(map(offset, -2048, 2048, -255, 255), -255, 255);

    radio.send(packet);

    Serial.print("raw=");
    Serial.print(raw);
    Serial.print("  speed=");
    Serial.println(packet.speed);

    delay(50);
}