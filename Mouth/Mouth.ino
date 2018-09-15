const int latchPin = 5;  // Pin conectado al Pin 12 del 74HC595 (Latch)
const int dataPin  = 6;  // Pin conectado al Pin 14 del 74HC595 (Data)
const int clockPin = 7; // Pin conectado al Pin 11 del 74HC595 (Clock)
int i =0;
                      
//const byte numeros[8] = {B10000000,B01000000,B00100000,B00010000,B00001000,B00000100,B00000010,B00000001};
const byte closedMouth = B00111010;
const byte openedMouth = B11111100;

                      
void setup() { 
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
}

void loop() {
    delay(1000);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, closedMouth);
    digitalWrite(latchPin, HIGH);
} // ()
