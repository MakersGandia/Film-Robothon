
//include
#include <Thread.h>
#include <StaticThreadController.h>
#include <ThreadController.h>
#include <Servo.h>
#include "LedControlMS.h"

//end include

//define

#define NUM_MTRX 1 //Number of devices connected to the Arduino
#define DATAIN 12
#define CLK 11
#define LOAD 10 // CS pin

//end define


/*Pinout
   Led Matrix = 8,9,10
   Lcd Display = 2,3,4,5,6,7
   Servo = 11
   Hopter = 12
*/


//eyes var

LedControl lc = LedControl(DATAIN, CLK, LOAD, NUM_MTRX);

unsigned long delayTime = 500;
unsigned long previousMillis = 0;
const byte CENTERED[8] =  {B00000000, B00111100, B01111110, B01100110, B01100110, B01111110, B00111100, B00000000};
const byte RIGHT[8] =     {B00000000, B00111100, B01111110, B01110010, B01110010, B01111110, B00111100, B00000000};
const byte LEFT[8] =      {B00000000, B00111100, B01111110, B01001110, B01001110, B01111110, B00111100, B00000000};
const byte CLOSED[8] =    {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00111100, B00000000};
const byte DOLLAR[8] =    {B00011000, B00111110, B01100000, B00111100, B00000110, B01111100, B00011000, B00000000};
const byte DOLLAR_DOWN[8] = {B0000000, B00011000, B00111110, B01100000, B00111100, B00000110, B01111100, B00011000};
const byte HAPPY[8] =     {B00000000, B00011000, B00111100, B01100110, B11000011, B00000000, B00000000, B00000000};
const byte SAD_DOWN[8] =  {B00000000, B00000000, B00111100, B01111110, B01111110, B01100110, B01100110, B00111100};
const byte SAD_RIGHT[8] = {B00000000, B00000000, B00111100, B01111110, B01111110, B01110010, B01110010, B00111100};
const byte SAD_LEFT[8] =  {B00000000, B00000000, B00111100, B01111110, B01111110, B01001110, B01001110, B00111100};


const byte HEART_0[8] = {B00000000, B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000};
const byte HEART_1[8] = {B00000000, B00000000, B00000000, B00011000, B00111100, B00111100, B00011000, B00000000};
const byte HEART_2[8] = {B00000000, B00000000, B01100110, B11111111, B11111111, B01111111, B00111100, B00011000};
const byte HEART_3[8] = {B00000000, B01100110, B11111111, B11111111, B01111110, B00111100, B00011000, B00000000};
const byte HEART_4[8] = {B01100110, B11111111, B11111111, B01111110, B00111100, B00011000, B00000000, B00000000};

//end eyes bar




//Motor Var

Servo myservo;  // create servo object to control a servo

//end Motor Var

//thread Var
ThreadController controll = ThreadController();

Thread* myThread = new Thread();

Thread anotherThread = Thread();

//end threadVar



//end var

//methods

//eyes methods
void start() {
 Serial.println("Waking up");
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
  delay(3000);
  robotBlink();
  robotBlink();
} // ()

void closeEyes() {
  Serial.println("Closing eyes");
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
  delay(100);
} // ()

void smile() { // TODO for 4 seconds with millis() and while
  Serial.println("Robot happy!");
  int times = 0;
  while(times < 4) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,HAPPY[i]);
  } // for
  delay(200);
  for (int i = 1; i < 8; i++) {
    lc.setRow(0,i-1,HAPPY[i]);
  } // for
  delay(200);
  times++;
  } // while
} // ()

void sad() { // TODO for 4 seconds with millis() and while
  int times = 0;
  while(times < 4) {
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
  times++;
  } // while
} // ()

void cash() { // ISSUE IN THE SECOND MATRIX, LAST LINE DOESN'T WORK PROPERLY
  Serial.println("Cash cash cash!! $$$$$");
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,DOLLAR[i]);
  } // for
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,DOLLAR_DOWN[i]);
  } // for
  delay(500);
  
} // ()

void love() {
  Serial.println("LOOOOVE");
   for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,HEART_0[i]);
  } // for
  delay(50);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,HEART_1[i]);
  } // for
  delay(50);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,HEART_2[i]);
  } // for
  delay(50);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,HEART_3[i]);
  } // for
  delay(50);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,HEART_4[i]);
  } // for
  delay(50);

}
//end eyes methods

//Motor methods



//end Motor methods

//Thread methods
void niceCallback() {
  for (int i = 0; i < 4; i++)
  {

    //matrix things

  }
}

void anotherNiceCallback() {
  for (int i = 0; i < 4; i++)
  {

    //other things

  }
}
//end Thread methods

void setup() {
  Serial.begin (9600);
  Serial.println("Matrix setup done");
  for (int i = 0; i < NUM_MTRX; i++) {
    lc.shutdown(i, false); //It wakes up every device we have connected.
    lc.setIntensity(i, 1);
    lc.clearDisplay(i);
  } // for

  start();

}

void loop() {
  // put your main code here, to run repeatedly:

}
