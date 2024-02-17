const int l_en = 2;
const int r_en = 3;
const int l_pwm = 5;
const int r_pwm = 6;
char msg;
void setup() {
  // put your setup code here, to run once:
  pinMode(l_en, OUTPUT);
  pinMode(r_en, OUTPUT);
  pinMode(l_pwm, OUTPUT);
  pinMode(r_pwm, OUTPUT);
  digitalWrite(l_en, HIGH);
  digitalWrite(r_en, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
      
    }
}
