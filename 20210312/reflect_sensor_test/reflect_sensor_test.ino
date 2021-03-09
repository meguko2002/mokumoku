#define SENSOR_L A0
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(SENSOR_L);
  // 回路の例では、反射が強い（対象が白）と小さく、反射が弱い（対象が黒）と大きい値になる(0-1023)
  Serial.println(sensorValue);
  delay(100);
}
