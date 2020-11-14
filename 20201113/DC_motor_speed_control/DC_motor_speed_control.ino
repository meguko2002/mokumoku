#define PIN_A 3
#define PIN_B 5  // 速度制御(analogWrite)する際はPWMピン(基板に「〜」が書かれているピン)しか使えません
#define analogInPin A0

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogInPin);            //アナログ入力ピンの0～5Vを0～1023の整数値に変換してsensorValueに代入
  int outputValue = map(sensorValue, 0, 1023, 0, 255);  //sensorValueの0～1023の整数値を0～255の整数値に変換してoutputValueに代入
  digitalWrite(PIN_A, LOW);
  analogWrite(PIN_B, outputValue);  //analogWriteによりPIN_Bには0vと5vが細かい時間間隔で交互に出力される（PWM制御）。
                                    //outputValueの値が大きいと（最大255）5vの時間比率が0vの時間比率よりも長くなる
}
