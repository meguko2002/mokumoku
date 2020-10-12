/* サーボモータのアームを180度行ったり来たりスイープさせる

  モータの線色：基板に指す箇所
    茶：　GND
    赤：　5V
    黄：　9番（注意）基板のピン番号の前に"～"の記号が付いているピンでないとだめ。例）3,5,6,9,10,11はOK
*/

#include <Servo.h>
const int servo_pin = 9;// サーボモータの信号線（黄色）を9番のピンに設定

Servo myservo;

void setup() {
  myservo.attach(servo_pin);      
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15); 
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos); 
    delay(15); 
  }
}
