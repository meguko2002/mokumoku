/* 超音波センサを使って距離を表示する
    マイコンへの書き込み終了後、画面右上の虫眼鏡のマークを押すと、
    シリアルモニターが立ち上がって、センサが測定した距離が表示される

  超音波センサのピン：基板に指す箇所
    Vcc： 5V
    Trig: 3番
    Echo: 2番
    GND：　GND
*/

const int echo_pin = 2; // Echo Pin
const int trig_pin = 3; // Trigger Pin
double Duration = 0; // 受信した間隔
double Distance = 0; // 距離

void setup() {
  Serial.begin( 9600 );   // シリアルモニターを使えるようにする
  pinMode( echo_pin, INPUT );
  pinMode( trig_pin, OUTPUT );
}
void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite( trig_pin, HIGH ); //超音波を出力
  delayMicroseconds( 10 ); //
  digitalWrite( trig_pin, LOW );
  Duration = pulseIn( echo_pin, HIGH ); //センサからの入力
  if (Duration > 0) {
    Duration = Duration / 2; //往復距離を半分にする
    Distance = Duration * 340 * 100 / 1000000; // 音速を340m/sに設定
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println(" cm");
  }
  delay(500);
}
