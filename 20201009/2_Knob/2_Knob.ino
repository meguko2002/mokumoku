/*ボリュームを回してサーボモータのアーム角度を操作する

  モータの線色：基板に指す箇所
    茶：　GND
    赤：　5V
    黄：　9番（注意）基板の番号の前に"～"の記号が付いているピンでないとだめ。例）3,5,6,9,10,11はOK
 
  ボリューム（可変抵抗）のピン配置。"10Ｋ"という表示を正面にして
    左ピン　：　GND
    中央ピン：　A0　（アナログピン）
    右ピン　：　5V
*/

#include <Servo.h>
const int servo_pin = 9;      // サーボモータの信号線（黄色）を9番のピンに設定
const int volume_pin = A0;    // ボリューム（の中央の足）をA0ピンに設定 

Servo myservo;

void setup() {
  myservo.attach(servo_pin); 
}

void loop() {
  int val = analogRead(volume_pin);    // ボリュームの角度によってアナログピンA0には0v～5vが印加される。
                                       // ピンA0の電圧に応じた0～1023の整数値が変数valに代入される
  val = map(val, 0, 1023, 0, 180);     // （右辺の)valの範囲0～1023を0～180に変換して、（左辺の）valに代入する
  myservo.write(val);                  // サーボに回転角度（val: 0～180度）を指定して回転させる
  delay(15);                           // 15ミリ秒そのまま待つ
}
