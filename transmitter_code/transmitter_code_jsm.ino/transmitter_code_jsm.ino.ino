//Transmitter Code
//Nick

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//////////////////////////////////////////////
// Defines and Constants
//////////////////////////////////////////////

//RADIO
const int CE_Pin = 8;
const int CSN_Pin = 7;

const byte address_1[6] = address_byte_1;
const byte address_2[6] = address_byte_2;

#define address_byte_1 "00001"
#define address_byte_2 "00002"

//Joystick
#define joystick_x A7 // x-axis
#define joystick_y A6 // y-axis


RF24 radio(CE_Pin, CSN_Pin); // CE, CSN

//////////////////////////////////////////////
// MAIN SETUP
//////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address_1);
  radio.openReadingPipe(1, address_2);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

//////////////////////////////////////////////
// MAIN LOOP
//////////////////////////////////////////////

void loop() {
  const char text[] = "monkey";
  radio.write(&text, sizeof(text));
  Serial.print ("Sent\n");
  delay(1000);
}