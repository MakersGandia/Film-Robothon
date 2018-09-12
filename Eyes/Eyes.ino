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
int a = 0;
byte frames[] [8] = {
{B00000000,B00111100,B01111110,B01100110,B01100110,B01111110,B00111100,B00000000}, // centred
{B00000000,B00111100,B01110010,B01110010,B01111110,B01111110,B00111100,B00000000},
{B00000000,B00111100,B01111110,B01110010,B01110010,B01111110,B00111100,B00000000},
{B00000000,B00111100,B01111110,B01111110,B01110010,B01110010,B00111100,B00000000}, // right
{B00000000,B00111100,B01111110,B01111110,B01100110,B01100110,B00111100,B00000000},
{B00000000,B00111100,B01111110,B01111110,B01001110,B01001110,B00111100,B00000000},
{B00000000,B00111100,B01111110,B01001110,B01001110,B01111110,B00111100,B00000000},
{B00000000,B00111100,B01001110,B01001110,B01111110,B01111110,B00111100,B00000000},
{B00000000,B00111100,B01100110,B01100110,B01111110,B01111110,B00111100,B00000000},
{B00000000,B00111100,B01110010,B01110010,B01111110,B01111110,B00111100,B00000000},
}; // byte

byte centred[8] = {B00000000,B00111100,B01111110,B01100110,B01100110,B01111110,B00111100,B00000000};
byte right[8] = {B00000000,B00111100,B01111110,B01110010,B01110010,B01111110,B00111100,B00000000};
byte left[8] = {B00000000,B00111100,B01111110,B01001110,B01001110,B01111110,B00111100,B00000000};
byte closed[8] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111100,B00000000};

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
  start();
  delay(10000);
  robotBlink();
  
  
} // ()

void start() {
  Serial.println("Eyes centered");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,centred[i]);
  } // for
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
  for (int i = 0; i < 7; i++) {
    lc.setRow(0,i,B00000000);
    delay(50);
  } // for
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,closed[i]);
  } // for
  delay(100);
  for (int i = 8; i > 0; i--) {
    lc.setRow(0,i,centred[i]);
    delay(50);
  } // for
    
} // ()
