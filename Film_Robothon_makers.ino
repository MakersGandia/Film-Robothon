/*Pinout
   Led Matrix = 8,9,10
   Lcd Display = 2,3,4,5,6,7
   Servo = 11
   Hopter = 12
*/

//include
#include <Thread.h>
#include <StaticThreadController.h>
#include <ThreadController.h>
#include <Servo.h>
//end include

//var

//threadVar
ThreadController controll = ThreadController();

Thread* myThread = new Thread();

Thread anotherThread = Thread();

//end threadVar

Servo myservo;  // create servo object to control a servo

//end var

//methods

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

    myservo.write(0);                  // sets the servo position according to the scaled value
    delay(10);                           // waits for the servo to get there
    myservo.write(180);                  // sets the servo position according to the scaled value
    delay(10);

  }
}
//end Thread methods

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
