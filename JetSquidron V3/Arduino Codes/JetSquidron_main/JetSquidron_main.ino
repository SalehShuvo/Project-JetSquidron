const int l_en = 2;
const int r_en = 3;
const int l_pwm = 5;
const int r_pwm = 6;
int speed = 255;
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
    SpeedSet();
    if (msg != 'S')
      Serial.println(msg);
    if (msg == 'w') {
      while (msg != 'W') {
        msg = Serial.read();
        SpeedSet();
        if (msg == 'F')
          Forward();
      }
    }
    if (msg == 'W') {
      while (msg != 'w') {
        msg = Serial.read();
        SpeedSet();
        if (msg == 'F')
          Forward();
        if (msg == 'S')
          Stop();
        if (msg == 'B')
          Backward();
      }
    }
  }
}


void Forward() {
  analogWrite(l_pwm, speed);
  analogWrite(r_pwm, 0);
  Serial.println("Forward");
  Serial.print("Speed: ");
  Serial.println(speed);
}
void Backward() {
  analogWrite(l_pwm, 0);
  analogWrite(r_pwm, speed);
  Serial.println("Backward");
  Serial.print("Speed: ");
  Serial.println(speed);
}
void Stop() {
  analogWrite(l_pwm, 0);
  analogWrite(r_pwm, 0);
}
void SpeedSet() {
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
