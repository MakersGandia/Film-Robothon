#include <BluetoothSerial.h>

BluetoothSerial SerialBT;



void setup() {
  SerialBT.begin("115200");
  if(!SerialBT.begin("ESP32")){
    Serial.println("An error occurred initializing Bluetooth");
  } // if
} // ()

void loop() {
  while(SerialBT.available()){
    Serial.println(SerialBT.read());
  } // while
} // ()
