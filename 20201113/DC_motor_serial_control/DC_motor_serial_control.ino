/*  
 *   シリアルモニターからl,L,r,R,sのいずれかの文字を入力してDCモータを制御するプログラム
 *     注意）シリアルモニター右下の”CRおよび..."のところは"改行なし"を選んでください
*/

#define PIN_A 3  // 注意）速度制御(analogWrite)する際はPWMピン(基板に「〜」が書かれているピン)しか使えません
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
      analogWrite(PIN_B, 255);  //速度を0から255の範囲で設定
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
}
