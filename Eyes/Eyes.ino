/*
@author Ricardo Escandell (UPV)
*/
#include "LedControlMS.h"

#define NUM_MTRX 1 //Number of devices connected to the Arduino
#define DATAIN 7
#define CLK 2
#define LOAD 10 // CS pin

LedControl lc=LedControl(DATAIN,CLK,LOAD, NUM_MTRX);
unsigned long delayTime=500;

byte centered[8] = {B00000000,B00111100,B01111110,B01100110,B01100110,B01111110,B00111100,B00000000};
byte right[8] = {B00000000,B00111100,B01111110,B01110010,B01110010,B01111110,B00111100,B00000000};
byte left[8] = {B00000000,B00111100,B01111110,B01001110,B01001110,B01111110,B00111100,B00000000};
byte closed[8] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111100,B00000000};
byte dollar[8] = {B00011000,B00111110,B01100000,B00111100,B00000110,B01111100,B00011000,B00000000};

void setup() {
  Serial.begin (9600);
  Serial.println("Matrix setup done");
  for (int i=0; i < NUM_MTRX; i++){
    lc.shutdown(i,false); //It wakes up every device we have connected.
    lc.setIntensity(i,1);
    lc.clearDisplay(i);
  } // for

   start();
   
} // ()

 
void loop() { 
  
  normal();
  
} // ()

void start() {
 Serial.print("Waking up");
 for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,closed[i]);
  } // for
  delay(1000);
  for (int i = 8; i >= 0; i--) {
    lc.setRow(0,i,centered[i]);
    delay(50);
  } // for
} // ()

void closeEyes() {
  Serial.print("Closing eyes");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,closed[i]);
    delay(50);
  } // for
} // ()

void openEyes() {
  Serial.println("Opening eyes");
  for (int i = 8; i >= 0; i--) {
    lc.setRow(0,i,centered[i]);
    delay(50);
  } // for
} // ()

void normal() {
  Serial.println("Eyes centered");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,centered[i]);
  } // for
  delay(5000);
  robotBlink();
  robotBlink();
} // ()

void lookRight() {
  Serial.println("Eyes looking right");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,right[i]);
  } // for
} // ()

void lookLeft() {
  Serial.println("Eyes looking left");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,left[i]);
  } // for
} // ()

void robotBlink() {
  Serial.println("Robot blinking");
  closeEyes();
  delay(100);
  openEyes();
} // ()
