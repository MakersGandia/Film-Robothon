/*
@author Ricardo Escandell (UPV)
*/
#include "LedControlMS.h"

#define NUM_MTRX 1 //Number of devices connected to the Arduino
#define DATAIN 12
#define CLK 11
#define LOAD 10 // CS pin

LedControl lc=LedControl(DATAIN,CLK,LOAD, NUM_MTRX);
unsigned long delayTime=500;
unsigned long previousMillis = 0;

// Defining the sprite variables
const byte EMPTY[8] =         {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
const byte CENTERED[8] =      {B00000000,B00111100,B01111110,B01100110,B01100110,B01111110,B00111100,B00000000};
const byte RIGHT[8] =         {B00000000,B00111100,B01111110,B01110010,B01110010,B01111110,B00111100,B00000000};
const byte LEFT[8] =          {B00000000,B00111100,B01111110,B01001110,B01001110,B01111110,B00111100,B00000000};
const byte CLOSED[8] =        {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00111100,B00000000};
const byte DOLLAR[8] =        {B00011000,B00111110,B01100000,B00111100,B00000110,B01111100,B00011000,B00000000};
const byte DOLLAR_DOWN[8] =   {B0000000,B00011000,B00111110,B01100000,B00111100,B00000110,B01111100,B00011000};
const byte HAPPY[8] =         {B00000000,B00011000,B00111100,B01100110,B11000011,B00000000,B00000000,B00000000};
const byte SAD_DOWN[8] =      {B00000000,B00000000,B00111100,B01111110,B01111110,B01100110,B01100110,B00111100};
const byte SAD_RIGHT[8] =     {B00000000,B00000000,B00111100,B01111110,B01111110,B01110010,B01110010,B00111100};
const byte SAD_LEFT[8] =      {B00000000,B00000000,B00111100,B01111110,B01111110,B01001110,B01001110,B00111100};

const byte ANGRY_1[8] =       {B00000000,B00000000,B00111100,B01111110,B01111110,B01100110,B01100110,B00111100};
const byte ANGRY_2[8] =        {B00000000,B00111100,B01111110,B01111110,B01100110,B01100110,B00111100,B00000000};

const byte HEART_0[8] =     {B00000000,B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000};
const byte HEART_1[8] =     {B00000000,B00000000,B00000000,B00011000,B00111100,B00111100,B00011000,B00000000};
const byte HEART_2[8] =     {B00000000,B00000000,B01100110,B11111111,B11111111,B01111111,B00111100,B00011000};
const byte HEART_3[8] =     {B00000000,B01100110,B11111111,B11111111,B01111110,B00111100,B00011000,B00000000};
const byte HEART_4[8] =     {B01100110,B11111111,B11111111,B01111110,B00111100,B00011000,B00000000,B00000000};
const byte LOADING_1[8] =   {B00000000,B00011000,B00011000,B01100110,B01100110,B00011000,B00011000,B00000000};
const byte LOADING_2[8] =   {B00000000,B00110000,B00110110,B00000110,B01100000,B01101100,B00001100,B00000000};


void setup() {
  Serial.begin (9600); // Just to check in the console if the methods are executed properly
  for (int i=0; i < NUM_MTRX; i++){
    lc.shutdown(i,false); //It wakes up every device we have connected.
    lc.setIntensity(i,8);
    lc.clearDisplay(i);
  } // for
  Serial.println("Matrix setup done");

   //start();
   
} // ()

void loop() { 
  

  /*defaultEye();
  smile();
  smile();
  delay(1000);
  sad();
  delay(100);
  sad();
  delay(1000);
  love();
  delay(200);
  love();
  delay(1000);
  newLife();
  delay(100);
  angry();
  delay(100);*/
  
  
  /*loading();
  delay(100);
  loading();
  delay(100);
  loading();
  delay(100);
  loading();
  delay(100);
  loading();
  delay(100);
  loading();
  delay(100);*/

  defaultEye();
  delay(200);
  loading();
  delay(100);
  loading();
  delay(100);
  loading();
  delay(100);
  loading();
  delay(100);
  shutDown();
  delay(30000);
  
} // ()

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

} // ()

void newLife() {
  int x = 0;
  lc.setIntensity(0,x);
  for (int i = 0; i < 8; i ++) {
      lc.setRow(0,i,EMPTY[i]);
    } // for
    delay(500);
  while (x < 8) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0,i,CENTERED[i]);
    } // for
  lc.setIntensity(0,x);
  delay(500);
  x++;
  } // while
} // ()

void angry() {
  
 for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,ANGRY_1[i]);
  } // for
  delay(50);
  lc.clearDisplay(0);
  delay(10);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,ANGRY_2[i]);
  } // for
  delay(100);
} // ()

void loading() {
  for (int i = 0; i<8; i++) {
    lc.setRow(0,i,LOADING_1[i]);
  } // for
  delay(500);
  for (int i = 0; i<8; i++) {
    lc.setRow(0,i,LOADING_2[i]);
  } // for
  delay(500);
} // ()

void shutDown() {
  lc.setIntensity(0,8);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,CENTERED[i]);
  } // for
  for(int i = 8; i > 0; i--) {
    lc.setIntensity(0,i);
    delay(250);
  } // for
  closeEyes();
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,EMPTY[i]);
  } // for
  
} // ()
