#include <Arduino.h>
#include "Radio.h"
#include "Motor.h"
#include "protocol.h"
#include "board.h"

Radio radio(PIN_CE, PIN_CSN);
Motor motor(PIN_PWMA, PIN_AIN1, PIN_AIN2);

unsigned long lastPacketMs = 0;
const unsigned long TIMEOUT_MS = 500;

void setup() {
    Serial.begin(115200);
    motor.init();

    if (!radio.init(false)) {
        Serial.println("radio failed");
        while (1) delay(1000);
    }
    Serial.println("role: RX");
}

void loop() {
    Packet packet;

    if (radio.receive(packet)) {
        lastPacketMs = millis();
        motor.setSpeed(packet.speed);

        Serial.print("speed=");
        Serial.println(packet.speed);
    }

    if (millis() - lastPacketMs > TIMEOUT_MS) {
        motor.setSpeed(0);
    }
}