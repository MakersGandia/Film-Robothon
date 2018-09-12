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
  delay(delayTime);
  lookRight();
  delay(delayTime);
  start();
  delay(delayTime);
  lookLeft();
  delay(delayTime);
  
  /*while (a < 8) {
    lc.setRow(0,0,frames[a][0]);
    lc.setRow(0,1,frames[a][1]);
    lc.setRow(0,2,frames[a][2]);
    lc.setRow(0,3,frames[a][3]);
    lc.setRow(0,4,frames[a][4]);
    lc.setRow(0,5,frames[a][5]);
    lc.setRow(0,6,frames[a][6]);
    lc.setRow(0,7,frames[a][7]);
    lc.setRow(0,8,frames[a][8]);
    a++;
    delay(delayTime);
  } // while
    a = 0;*/
} // ()

void start() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,centred[i]);
  } // for
} // ()

void lookRight() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,right[i]);
  } // for
} // ()

void lookLeft() {
    for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,left[i]);
  } // for
} // ()
