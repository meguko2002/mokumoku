#define PIN_A 3  // 速度制御(analogWrite)する際はPWMピン(基板に「〜」が書かれているピン)しか使えません
#define PIN_B 5  

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //シリアルモニターに入力した文字に応じてモータを制御
  if (Serial.available()>0) {
    char sign = Serial.read();
    motor(sign);
  }
}

void motor(char dir) {
  Serial.println(dir);
  switch (dir) {
    case 'L':
      digitalWrite(PIN_A,LOW);
      analogWrite(PIN_B, 255);
      break;
    case 'l':
      digitalWrite(PIN_A, LOW);
      analogWrite(PIN_B, 127);
      break;
    case 'R':
      analogWrite(PIN_A, 255);
      digitalWrite(PIN_B, LOW);
      break;
    case 'r':
      analogWrite(PIN_A, 127);
      digitalWrite(PIN_B, LOW);
      break;
    case 's':
      digitalWrite(PIN_A, LOW);
      digitalWrite(PIN_B, LOW);
      break;
    default:
      Serial.println("wrong input");
      break;
  }
  /* switch以下をif文で書いても同じ*/
  //  if (dir == 'L') {
  //    digitalWrite(PIN_A, LOW);
  //    analogWrite(PIN_B, 255);
  //  }
  //  if (dir == 'l') {
  //    digitalWrite(PIN_A, LOW);
  //    analogWrite(PIN_B, 127);
  //  }
  //  else if (dir == 'R') {
  //    analogWrite(PIN_A, 255);
  //    digitalWrite(PIN_B, LOW);
  //  }
  //  else if (dir == 'r') {
  //    analogWrite(PIN_A, 127);
  //    digitalWrite(PIN_B, LOW);
  //  }
  //  else if (dir == 's') {
  //    digitalWrite(PIN_A, LOW);
  //    digitalWrite(PIN_B, LOW);
  //  }
  //  else {
  //    Serial.println("wrong input");
  //  }
}
