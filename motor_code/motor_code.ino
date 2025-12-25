//motor test code using PWM
//Nick

const int IN1 = 14;
const int IN2 = 15;
const int IN3 = 16;
const int IN4 = 17;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

}

void loop() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}
