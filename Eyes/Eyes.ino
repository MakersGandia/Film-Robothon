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
unsigned long previousMillis = 0;
const byte CENTERED[8] =  {B00000000,B00111100,B01111110,B01100110,B01100110,B01111110,B00111100,B00000000};
const byte RIGHT[8] =     {B00000000,B00111100,B01111110,B01110010,B01110010,B01111110,B00111100,B00000000};
const byte LEFT[8] =      {B00000000,B00111100,B01111110,B01001110,B01001110,B01111110,B00111100,B00000000};
const byte CLOSED[8] =    {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111100,B00000000};
const byte DOLLAR[8] =    {B00011000,B00111110,B01100000,B00111100,B00000110,B01111100,B00011000,B00000000};
const byte DOLLAR_DOWN[8] = {B0000000,B00011000,B00111110,B01100000,B00111100,B00000110,B01111100,B00011000};
const byte HAPPY[8] =     {B00000000,B00011000,B00111100,B01100110,B11000011,B00000000,B00000000,B00000000};
const byte SAD_DOWN[8] =  {B00000000,B00000000,B00111100,B01111110,B01111110,B01100110,B01100110,B00111100};
const byte SAD_RIGHT[8] = {B00000000,B00000000,B00111100,B01111110,B01111110,B01110010,B01110010,B00111100};
const byte SAD_LEFT[8] =  {B00000000,B00000000,B00111100,B01111110,B01111110,B01001110,B01001110,B00111100};

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
  

  cash();
  
} // ()

void start() {
 Serial.print("Waking up");
 for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,CLOSED[i]);
  } // for
  delay(1000);
  for (int i = 8; i >= 0; i--) {
    lc.setRow(0,i,CENTERED[i]);
    delay(50);
  } // for
} // ()

void defaultEye() {
  Serial.println("Eyes centered");
  lc.clearDisplay(0);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,CENTERED[i]);
  } // for
  delay(5000);
  robotBlink();
  robotBlink();
} // ()

void closeEyes() {
  Serial.print("Closing eyes");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,CLOSED[i]);
    delay(50);
  } // for
} // ()

void openEyes() {
  Serial.println("Opening eyes");
  for (int i = 8; i > 0; i--) {
    lc.setRow(0,i,CENTERED[i]);
    delay(50);
  } // for
} // ()



void lookRight() { // while turning right
  Serial.println("Eyes looking right");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,RIGHT[i]);
  } // for
} // ()

void lookLeft() { // while turning left
  Serial.println("Eyes looking left");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,LEFT[i]);
  } // for
} // ()

void robotBlink() {
  Serial.println("Robot blinking");
  closeEyes();
  delay(100);
  openEyes();
} // ()

void smile() { // TODO for 4 seconds with millis() and while
  Serial.println("Robot happy!");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,HAPPY[i]);
  } // for
  delay(200);
  for (int i = 1; i < 8; i++) {
    lc.setRow(0,i-1,HAPPY[i]);
  } // for
  delay(200);
} // ()

void sad() { // TODO for 4 seconds with millis() and while
  Serial.println("Robot sad...");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,SAD_DOWN[i]);
  } // for
  delay(200);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,SAD_LEFT[i]);
  } // for
  delay(200);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,SAD_DOWN[i]);
  } // for
  delay(200);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,SAD_RIGHT[i]);
  } // for
  delay(200);
} // ()

void cash() { // ISSUE IN THE SECOND MATRIX, LAST LINE DOESN'T WORK PROPERLY
  Serial.print("Cash cash cash!! $$$$$");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,DOLLAR[i]);
  } // for
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,DOLLAR_DOWN[i]);
  } // for
  delay(500);
  
} // ()
