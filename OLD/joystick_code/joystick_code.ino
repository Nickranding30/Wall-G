/*
Test code for using joysticks
*/

#define joystick_x A7
#define joystick_y A6

void setup() {
  Serial.begin(9600);
}

void loop() {

  int xvalue = analogRead(joystick_x);
  int yvalue = analogRead(joystick_y);

  Serial.print("X: "); Serial.print(xvalue); Serial.print("\t");

  Serial.print("Y: "); Serial.print(yvalue); Serial.print("\n");

  delay(100);

}
