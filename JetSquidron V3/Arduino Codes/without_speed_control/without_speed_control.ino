const int l_en = 3;
const int r_en = 4;
const int l_pwm = 5;
const int r_pwm = 6;
char msg;
void setup() {
  pinMode(l_en, OUTPUT);
  pinMode(r_en, OUTPUT);
  pinMode(l_pwm, OUTPUT);
  pinMode(r_pwm, OUTPUT);
                                                 
  digitalWrite(l_pwm, LOW);
  digitalWrite(r_pwm, HIGH);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    msg = Serial.read();
    if (msg != 'S')
      Serial.println(msg);
    if (msg == 'F') {
      digitalWrite(l_en, HIGH);
      digitalWrite(r_en, HIGH);
    }
    if (msg == 'B') {
      digitalWrite(l_en, LOW);
      digitalWrite(r_en, LOW);
    }
  }
}
