
//include
#include <Thread.h>
#include <StaticThreadController.h>
#include <ThreadController.h>
#include <Servo.h>
#include <AFMotor.h>
//end include


/*Pinout
   Led Matrix = 8,9,10
   Lcd Display = 2,3,4,5,6,7
   Servo = 11
   Hopter = 12
*/


//var

//Motor Var



//end Motor Var

//thread Var
ThreadController controll = ThreadController();

Thread* myThread = new Thread();

Thread anotherThread = Thread();

//end threadVar

Servo myservo;  // create servo object to control a servo

//end var

//methods

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
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
