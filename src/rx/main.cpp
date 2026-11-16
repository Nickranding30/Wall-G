#include <Arduino.h>
#include "Radio.h"
#include "Motor.h"
#include "protocol.h"
#include "board.h"

Radio radio(PIN_CE, PIN_CSN);
Motor motor_d1_a(PIN_PWMA_D1, PIN_AIN1_D1, PIN_AIN2_D1);
Motor motor_d1_b(PIN_PWMB_D1, PIN_BIN1_D1, PIN_BIN2_D1);
Motor motor_d2_a(PIN_PWMA_D2, PIN_AIN1_D2, PIN_AIN2_D2);
Motor motor_d2_b(PIN_PWMB_D2, PIN_BIN1_D2, PIN_BIN2_D2);

unsigned long lastPacketMs = 0;
const unsigned long TIMEOUT_MS = 500;

void setup() {
    Serial.begin(115200);
    motor_d1_a.init();
    motor_d1_b.init();
    motor_d2_a.init();
    motor_d2_b.init();
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
        motor_d1_a.setSpeed(packet.speed);
        motor_d1_b.setSpeed(packet.speed);
        motor_d2_a.setSpeed(packet.speed);
        motor_d2_b.setSpeed(packet.speed);

        Serial.print("speed=");
        Serial.println(packet.speed);
    }

    if (millis() - lastPacketMs > TIMEOUT_MS) {
        motor_d1_a.setSpeed(0);
        motor_d1_b.setSpeed(0);
        motor_d2_a.setSpeed(0);
        motor_d2_b.setSpeed(0);
    }
}