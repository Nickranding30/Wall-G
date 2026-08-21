//Receiver Code
//Nick

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <Drive.h>

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

//Motor
int motor1_a = 14;
int motor1_b = 15;
int motor2_a = 16;
int motor2_b = 17;
const int ENA = 5; //PWM enable
const int ENB = 6; //PWM enable

//Other
int xvalue;
int yvalue;
int m_xvalue;
int m_yvalue;

RF24 radio(CE_Pin, CSN_Pin); // CE, CSN

//////////////////////////////////////////////
// MAIN SETUP
//////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address_2);
  radio.openReadingPipe(1, address_1);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  

  // Motor Set up
  pinMode(motor1_a, OUTPUT);
  pinMode(motor1_b, OUTPUT);
  pinMode(motor2_a, OUTPUT);
  pinMode(motor2_b, OUTPUT);

  analogWrite (ENA, 0);
  analogWrite (ENB, 0);

}

void loop() {
  

  //Start Value at middle position
    xvalue = 520;
    yvalue = 520;

  if (radio.available()) {
    radio.read(&data, sizeof(data));
    xvalue = data[0];
    yvalue = data[1];
  }  

  Serial.print ("x value: ");
  Serial.print (xvalue);
  Serial.print (" | y value: ");
  Serial.print (yvalue);
  Serial.print (" | button: ");
  Serial.print (data[2]);
  

//                UP (0)
//   LEFT (0)    neutral (518 ----- 526)     RIGHT (1023)
//                DOWN (1023)


int m_yvalue = map(yvalue, 512, 0, 0, 255);
  // Forward
  if (yvalue < 518) {
    int m_yvalue = map(yvalue, 512, 0, 70, 255);
    digitalWrite(motor1_a, HIGH);
    digitalWrite(motor1_b, LOW);
    analogWrite(ENA, m_yvalue);

    digitalWrite(motor2_a, HIGH);
    digitalWrite(motor2_b, LOW);
    analogWrite(ENB, m_yvalue);
  }

  // Backward
  if (yvalue > 526) {
    int m_yvalue = map(yvalue, 1023, 512, 70, 255);
    digitalWrite(motor1_a, LOW);
    digitalWrite(motor1_b, HIGH);
    analogWrite(ENA, m_yvalue);

    digitalWrite(motor2_a, LOW);
    digitalWrite(motor2_b, HIGH);
    analogWrite(ENB, m_yvalue);
  }

/*
  // Left
  if (xvalue < 518) {
    int m_xvalue = map(xvalue, 512, 0, 0, 255);
    digitalWrite(motor1_a, LOW);
    digitalWrite(motor1_b, LOW);
    analogWrite(ENA, (255 - m_xvalue));

    digitalWrite(motor2_a, HIGH);
    digitalWrite(motor2_b, LOW);
    analogWrite(ENB, m_xvalue);
  }

  // Right
  if (xvalue > 526) {
    int m_xvalue = map(xvalue, 512, 1023, 0, 255);
    digitalWrite(motor1_a, HIGH);
    digitalWrite(motor1_b, LOW);
    analogWrite(ENA, m_xvalue);

    digitalWrite(motor2_a, LOW);
    digitalWrite(motor2_b, LOW);
    analogWrite(ENB, (255 - m_xvalue));
  }

  */

  Serial.print (" x mapped value: ");
  Serial.print (m_xvalue);
  Serial.print (" | y mapped value: ");
  Serial.println (m_yvalue);

  if (xvalue > 518 && xvalue < 526 && xvalue > 518 && yvalue < 526){
    digitalWrite(motor1_a, LOW);
    digitalWrite(motor1_b, LOW);
    digitalWrite(motor2_a, LOW);
    digitalWrite(motor2_b, LOW);
  }

  delay(100);
}
