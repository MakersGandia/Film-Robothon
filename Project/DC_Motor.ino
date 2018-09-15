/*
@author Ricardo Escandell (UPV)
*/

// Defining the Arduino pin where the motor is connected (It has to be an PWM pin)
// Note that PWM pins have ~ simbol next to the pin number in the Arduino board
#define MOTORDC 5

void setup() {
  // Setting the motor pin as an output
  pinMode(MOTORDC, OUTPUT);

} // ()

void loop() {
  analogWrite(MOTORDC, 255);
  delay(500);
  analogWrite(MOTORDC, 0);
  delay(500);
} // ()
