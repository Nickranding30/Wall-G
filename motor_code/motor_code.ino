#include <Drive.h>

//motor test code using PWM
//Nick

Drive drive(14,15,16,17);
const int ENA = 5; //PWM enable
const int ENB = 6; //PWM enable

void setup() {
  
  drive.begin();
  analogWrite (ENA, 255);
  analogWrite (ENB, 255);


}

void loop() {

  drive.forward();
  delay(2000);
  drive.brake();
  delay(2000);
  drive.backward();
  delay(2000);
  drive.brake();
  delay(2000);
 
}