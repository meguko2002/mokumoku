/* 超音波センサがセンシングした距離に応じてサーボモータの角度が変わる

  超音波センサのピン：基板に指す箇所
    Vcc： 5V
    Trig: 3番
    Echo: 2番
    GND：　GND

  サーボモータの線色：基板に指す箇所
    茶：　GND
    赤：　5V
    黄：　9番（注意）基板の番号の前に"～"の記号が付いているピンでないとだめ。例）3,5,6,9,10,11はOK
*/

#include <Servo.h>
const int servo_pin = 9;      // サーボモータの信号線（黄色）を9番のピンに設定
const int echo_pin = 2; // Echo Pin
const int trig_pin = 3; // Trigger Pin
double Duration = 0; // 受信した間隔
double Distance = 0; // 距離

Servo myservo;

void setup() {
  Serial.begin( 9600 );
  pinMode( echo_pin, INPUT );
  pinMode( trig_pin, OUTPUT );
  myservo.attach(servo_pin);
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
    Serial.print("cm, ");
    int angle = map(int(Distance), 10, 60, 0, 180);    // Distanceが10cmから60cmのときにサーボを0から180度の角度に回す
    angle = constrain(angle, 0, 180);   // angleの上下限をそれぞれ0,180に範囲限定する
    Serial.print(angle);
    Serial.println("°");
    myservo.write(angle);
    delay(500);
  }
}
