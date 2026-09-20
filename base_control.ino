#include <SoftwareSerial.h>
#include <Wire.h>
#include <AFMotor.h>

SoftwareSerial Bluetooth(9, 10); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)
AF_DCMotor motor(1, MOTOR12_64KHZ);
AF_DCMotor motor1(2, MOTOR12_64KHZ);
AF_DCMotor motor2(3, MOTOR12_64KHZ);
AF_DCMotor motor3(4, MOTOR12_64KHZ);

int wheelSpeed = 100;
int dataIn, m;

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(1);
  delay(20);
}

void loop() {
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.read();
    Serial.println(dataIn);

    if (dataIn == 0) m = 0;
    if (dataIn == 1) m = 1;
    if (dataIn == 2) m = 2;
    if (dataIn == 3) m = 3;
    if (dataIn == 4) m = 4;
    if (dataIn == 5) m = 5;
    if (dataIn == 6) m = 6;
    if (dataIn == 7) m = 7;
    if (dataIn == 8) m = 8;
    if (dataIn == 9) m = 9;
    if (dataIn == 10) m = 10;
    if (dataIn == 11) m = 11;
    if (dataIn == 12) m = 12;
    if (dataIn == 14) m = 14;

    if (dataIn >= 16) {
      wheelSpeed = dataIn;
      Serial.println(wheelSpeed);
    }
  }

  if (m == 5) moveSidewaysLeft();
  if (m == 4) moveSidewaysRight();
  if (m == 2) moveForward();
  if (m == 7) moveBackward();
  if (m == 1) moveRightForward();
  if (m == 3) moveLeftForward();
  if (m == 6) moveRightBackward();
  if (m == 8) moveLeftBackward();
  if (m == 9) rotateLeft();
  if (m == 10) rotateRight();
  if (m == 0) stopMoving();

  if (m == 12) {
  }
}

void moveForward() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(wheelSpeed);
  motor1.run(FORWARD);
  motor.run(FORWARD);
  motor3.run(FORWARD);
  motor2.run(FORWARD);
}

void moveBackward() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(wheelSpeed);
  motor1.run(BACKWARD);
  motor.run(BACKWARD);
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
}

void moveSidewaysRight() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(wheelSpeed);
  motor1.run(BACKWARD);
  motor.run(FORWARD);
  motor3.run(BACKWARD);
  motor2.run(FORWARD);
}

void moveSidewaysLeft() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(wheelSpeed);
  motor1.run(FORWARD);
  motor.run(BACKWARD);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
}

void rotateLeft() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(wheelSpeed);
  motor1.run(FORWARD);
  motor.run(FORWARD);
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
}

void rotateRight() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(wheelSpeed);
  motor1.run(BACKWARD);
  motor.run(BACKWARD);
  motor3.run(FORWARD);
  motor2.run(FORWARD);
}

void moveRightForward() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(0);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor.run(FORWARD);
  motor2.run(FORWARD);
}

void moveRightBackward() {
  motor1.setSpeed(wheelSpeed);
  motor.setSpeed(0);
  motor3.setSpeed(wheelSpeed);
  motor2.setSpeed(0);
  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);
}

void moveLeftForward() {
  motor.setSpeed(0);
  motor1.setSpeed(wheelSpeed);
  motor2.setSpeed(0);
  motor3.setSpeed(wheelSpeed);
  motor2.run(RELEASE);
  motor.run(RELEASE);
  motor1.run(FORWARD);
  motor3.run(FORWARD);
}

void moveLeftBackward() {
  motor.setSpeed(wheelSpeed);
  motor1.setSpeed(0);
  motor2.setSpeed(wheelSpeed);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor.run(BACKWARD);
  motor2.run(BACKWARD);
}

void stopMoving() {
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor.setSpeed(0);
}
