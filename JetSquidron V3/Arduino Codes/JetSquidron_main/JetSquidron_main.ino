const int l_en = 2;
const int r_en = 3;
const int l_pwm = 5;
const int r_pwm = 6;
int speed = 0;
char msg;
void setup() {
  pinMode(l_en, OUTPUT);
  pinMode(r_en, OUTPUT);
  pinMode(l_pwm, OUTPUT);
  pinMode(r_pwm, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    msg = Serial.read();
    if (msg != 'S')
      Serial.println(msg);
    if (msg == 'F')
      forward();
    if (msg == 'B')
      backward();
  }
}




void forward() {
  analogWrite(l_pwm, speed);
  analogWrite(r_pwm, 0);
}
void backward() {
  analogWrite(l_pwm, 0);
  analogWrite(r_pwm, speed);
}
void stop() {
  analogWrite(l_pwm, 0);
  analogWrite(r_pwm, 0);
}
void speedSet() {
  if (msg == '0')
    speed = 0;
  else if (msg == '1')
    speed = 25;
  else if (msg == '2')
    speed = 50;
  else if (msg == '3')
    speed = 75;
  else if (msg == '4')
    speed = 100;
  else if (msg == '6')
    speed = 125;
  else if (msg == '7')
    speed = 150;
  else if (msg == '8')
    speed = 200;
  else if (msg == '9')
    speed = 255;
}
