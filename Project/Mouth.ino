/*
@author Ricardo Escandell (UPV)
*/

// Defining the 74HC595 pins connected to the Arduino
const int latchPin = 5;  // Pin conectado al Pin 12 del 74HC595 (Latch)
const int dataPin  = 6;  // Pin conectado al Pin 14 del 74HC595 (Data)
const int clockPin = 7; // Pin conectado al Pin 11 del 74HC595 (Clock)

// Defining a random number to make the mouth's movement more realistic
int randomDelay = random(50,400);
                      
// Defining the sprites to be shown in the 7-segment display
const byte closedMouth = B00111010;
const byte openedMouth = B11111100;

void setup() { 
  Serial.begin(9600); // Just to check in the console if the methods are executed properly

  // Setting the 74HC595 pins (the ones which are connected to the Arduino) as outputs
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); 
} // ()

void loop() {
  closeMouth();
  delay(randomDelay);
  randomDelay = random(100,300);
  openMouth();
  delay(randomDelay);
} // ()

// Method that displays the closedMouth sprite in the display
void closeMouth() {
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,closedMouth);
  digitalWrite(latchPin,HIGH);
} // ()

// Method that displays the openedMouth sprite in the display
void openMouth() {
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,openedMouth);
  digitalWrite(latchPin,HIGH);
} // ()
