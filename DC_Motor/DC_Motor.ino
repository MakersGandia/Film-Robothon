#define MOTORDC 5

void setup() {
  pinMode(MOTORDC, OUTPUT);

}

void loop() {
  analogWrite(MOTORDC, 255);
  delay(500);
  analogWrite(MOTORDC, 0);
  delay(500);
}
