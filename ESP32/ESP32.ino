#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;
 
void setup() {
  Serial.begin(115200);
 
  if(!SerialBT.begin("ESP32")){
    Serial.println("An error occurred initializing Bluetooth");
  } // if
} // ()
 
void loop() {
 
  while(SerialBT.available()){
    Serial.write(SerialBT.read());
  }
 
  delay(50);
} // ()
