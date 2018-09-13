
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
       
  
}
void accelerate(int x, int y){

if(x>0||y>0){

 motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);
  
}

if(x<0||y<0){

 motor1.run(BACKWARD);
 motor2.run(BACKWARD);
 motor3.run(BACKWARD);
 motor4.run(BACKWARD);
  
}
if(x>0||y<0){

 motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(BACKWARD);
 motor4.run(BACKWARD);
  
}
if(x<0||y>0){

 motor1.run(BACKWARD);
 motor2.run(BACKWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);
  
}
if(x==0||y==0){
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
  
}
  
}
int x=0;
int y=0;
void loop() {

accelerate(x,y);
}
