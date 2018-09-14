
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  motor1.setSpeed(255);//backward/left
  motor2.setSpeed(255);//backward/right
  motor3.setSpeed(255);//forward/right
  motor4.setSpeed(255);//forward/left

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);



}
int x;
void accelerate(int x) {

  if (x==1) {


    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    Serial.println("FORWARD");

  }

  if (x==2) {

    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);


    Serial.println("BACKWARD");
  }
  if (x==3) {

    motor1.run(RELEASE);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(RELEASE);

    Serial.println("M1YM2");

  }
  if (x==4) {

    motor1.run(RELEASE);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(RELEASE);
    Serial.println("M4YM3");

  }
  if (x==0) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    Serial.println("STOP");

  }

}

void loop() {



  accelerate(x);
}
