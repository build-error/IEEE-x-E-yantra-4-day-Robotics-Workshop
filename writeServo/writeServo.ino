#include <Servo.h>
#include <math.h>
#define PI 3.14159
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

float pos(float deg) {
  return 0.777*deg;
}

void servo_pos(int deg) {
  myservo.write(pos(deg));
}

float pan_pos(float x, float d) {
  myservo.write(pos(asin(x/d)*180/PI));
}

void loop() {
  // put your main code here, to run repeatedly:  
  pan_pos(1, 4);
}
