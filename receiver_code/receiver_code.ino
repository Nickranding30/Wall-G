//Receiver Code
//Nick

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int CE_Pin = 8;
const int CSN_Pin = 7;
#define address_byte "00001"

RF24 radio(CE_Pin, CSN_Pin); // CE, CSN

const byte address[6] = address_byte;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}