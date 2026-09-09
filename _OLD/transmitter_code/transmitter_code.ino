//Transmitter Code
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
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "monkey";
  radio.write(&text, sizeof(text));
  Serial.print ("Sent\n");
  delay(1000);
}