const int l_en = 2;
const int r_en = 3;
const int l_pwm = 5;
const int r_pwm = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(l_en, OUTPUT);
  pinMode(r_en, OUTPUT);
  pinMode(l_pwm, OUTPUT);
  pinMode(r_pwm, OUTPUT);
  digitalWrite(l_en, HIGH);
  digitalWrite(r_en, HIGH);

  analogWrite(l_pwm, 255);
  analogWrite(r_pwm, 00);
  delay(300);
  analogWrite(l_pwm, 0);
  analogWrite(r_pwm, 0);
}

void loop() {
  analogWrite(l_pwm, 200);
  analogWrite(r_pwm, 100);
}
