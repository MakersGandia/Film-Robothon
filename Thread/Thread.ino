#include <Thread.h>
#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>
#include <Servo.h>
Thread myThread = Thread();
Servo myservo;  // create servo object to control a servo

#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11


int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

// callback for myThread
void niceCallback() {
  for (int i = 0; i < 4; i++)
  {

    digitalWrite(IN1, paso[i][0]);
    digitalWrite(IN2, paso[i][1]);
    digitalWrite(IN3, paso[i][2]);
    digitalWrite(IN4, paso[i][3]);
    delay(10);

  }
}

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object

  myThread.onRun(niceCallback);
  myThread.setInterval(0);
}

void loop() {
  // checks if thread should run
  if (myThread.shouldRun())
    myThread.run();

  // Other code...

    myservo.write(0);                  // sets the servo position according to the scaled value
    delay(10);                           // waits for the servo to get there
    myservo.write(180);                  // sets the servo position according to the scaled value
    delay(10);
}
