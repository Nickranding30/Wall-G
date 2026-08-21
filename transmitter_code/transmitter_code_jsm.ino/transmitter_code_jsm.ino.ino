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

#define address_byte_1 "00001"
#define address_byte_2 "00002"

const byte address_1[6] = address_byte_1;
const byte address_2[6] = address_byte_2;

//uint8_t data[3];
int data[3];

RF24 radio(CE_Pin, CSN_Pin); // CE, CSN

//JOYSTICK
const int joystick_x = A7; // x-axis
const int joystick_y = A6; // y-axis
const int joystick_btn = A5; // button

int xvalue;
int yvalue;

//////////////////////////////////////////////
// MAIN SETUP
//////////////////////////////////////////////

void setup() {
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
  pinMode(joystick_btn, INPUT_PULLUP);
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
  int xvalue = analogRead(joystick_x);
  int yvalue = analogRead(joystick_y);
  int button = digitalRead(button);

/*
  // Map Values
  int r_xvalue = map(xvalue, 0, 1023, 0, 255);
  int r_yvalue = map(yvalue, 0, 1023, 0, 255);
*/

  // Payload
  //data[0] = r_xvalue;
  //data[1] = r_yvalue;
  data[0] = xvalue;
  data[1] = yvalue;
  data[2] = button;


  Serial.print ("x value: ");
  Serial.print (xvalue);
  Serial.print (" | y value: ");
  Serial.print (yvalue);
  Serial.print (" | button: ");
  Serial.println (button);

  radio.write(&data, sizeof(data));
  delay(100);

}