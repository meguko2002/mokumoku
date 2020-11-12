#define CW 3  // 速度制御する際はPWMピン(基板に「〜」が書かれているピン)に挿す
#define CCW 5

void setup() {
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //シリアルモニター入力した文字に応じてモータを制御
  if (Serial.available()) {
    char sign = Serial.read();
    motor(sign);
  }
}

void motor(char dir) {
  Serial.println(dir);    //なくて良い
  switch (dir) {
    case 'L':
      digitalWrite(CW, LOW);
      analogWrite(CCW, 255);
      break;
    case 'l':
      digitalWrite(CW, LOW);
      analogWrite(CCW, 127);
      break;
    case 'R':
      analogWrite(CW, 255);
      digitalWrite(CCW, LOW);
      break;
    case 'r':
      analogWrite(CW, 127);
      digitalWrite(CCW, LOW);
      break;
    case 's':
      digitalWrite(CW, LOW);
      digitalWrite(CCW, LOW);
      break;
    default:
      Serial.println("wrong input");
      break;
  }
  /* if文で書いても良い*/
  //  if (dir == 'L') {
  //    digitalWrite(CW, LOW);
  //    analogWrite(CCW, 255);
  //  }
  //  if (dir == 'l') {
  //    digitalWrite(CW, LOW);
  //    analogWrite(CCW, 127);
  //  }
  //  else if (dir == 'R') {
  //    analogWrite(CW, 255);
  //    digitalWrite(CCW, LOW);
  //  }
  //  else if (dir == 'r') {
  //    analogWrite(CW, 127);
  //    digitalWrite(CCW, LOW);
  //  }
  //  else if (dir == 's') {
  //    digitalWrite(CW, LOW);
  //    digitalWrite(CCW, LOW);
  //  }
  //  else {
  //    Serial.println("wrong input");
  //  }
}
