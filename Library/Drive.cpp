/*
  Drive.h - Library for driving motors forward, backwards, and brake.
  Created by Nicholas Randing, December 27, 2025.
*/

#include "Arduino.h"
#include "Drive.h"

Drive::Drive(int pinA1, int pinA2, int pinB1, int pinB2)
{
  _pinA1 = pinA1;
  _pinA2 = pinA2;
  _pinB1 = pinB1;
  _pinB2 = pinB2;
}

void Drive::begin()
{
  pinMode(_pinA1, OUTPUT);
  pinMode(_pinA2, OUTPUT);
  pinMode(_pinB1, OUTPUT);
  pinMode(_pinB2, OUTPUT);

  digitalWrite(_pinA1, LOW);
  digitalWrite(_pinB1, LOW);
  digitalWrite(_pinA2, LOW);
  digitalWrite(_pinB2, LOW);
}

void Drive::forward()
{
  digitalWrite(_pinA1, HIGH);
  digitalWrite(_pinB1, HIGH);

  digitalWrite(_pinA2, LOW);
  digitalWrite(_pinB2, LOW);

}

void Drive::backward()
{

  digitalWrite(_pinA1, LOW);
  digitalWrite(_pinB1, LOW);

  digitalWrite(_pinA2, HIGH);
  digitalWrite(_pinB2, HIGH);
  
}

void Drive::brake()
{
  digitalWrite(_pinA1, LOW);
  digitalWrite(_pinB1, LOW);
  digitalWrite(_pinA2, LOW);
  digitalWrite(_pinB2, LOW);
}