#define MOTOR_A_P 3
#define MOTOR_A_M 4
#define MOTOR_A_SPEED 5  // 速度制御(analogWrite)する際はPWMピン(基板に「〜」が書かれているピン)しか使えません
#define MOTOR_B_P 10
#define MOTOR_B_M 8
#define MOTOR_B_SPEED 9  // 速度制御(analogWrite)する際はPWMピン(基板に「〜」が書かれているピン)しか使えません
#define analogInPin A0

void setup() {
  pinMode(MOTOR_A_P, OUTPUT);
  pinMode(MOTOR_A_M, OUTPUT);
  pinMode(MOTOR_A_SPEED, OUTPUT);
  pinMode(MOTOR_B_P, OUTPUT);
  pinMode(MOTOR_B_M, OUTPUT);
  pinMode(MOTOR_B_SPEED, OUTPUT);
  digitalWrite(MOTOR_A_P, LOW);
  digitalWrite(MOTOR_A_M, HIGH);
  digitalWrite(MOTOR_B_P, HIGH);
  digitalWrite(MOTOR_B_M, LOW);
}

void loop() {
  for (int i = 0; i < 255; i++) {
    analogWrite(MOTOR_A_SPEED, i);
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(MOTOR_A_SPEED, i);
    delay(10);
  }
  for (int i = 0; i < 255; i++) {
    analogWrite(MOTOR_B_SPEED, i);
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(MOTOR_B_SPEED, i);
    delay(10);
  }
}
