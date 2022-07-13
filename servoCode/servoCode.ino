#include <Servo.h>
#include <math.h>
#define PI 3.14159

Servo panServo;
Servo tiltServo;

const float min_signal = 60, max_signal = 145, 
            min_degree = 0, max_degree = -90,
            const_distance = 200;
char x, y;
long int v;
float signal_pos(float deg) {
  float slope = (max_degree - min_degree) / (max_signal - min_signal);
  return slope*(deg-min_degree) + min_signal;
}

void servo_pos(int deg) {
  panServo.write(signal_pos(deg));
}

float pan_pos(float x) {
  servo_pos(atan(x/const_distance)*(180/PI));
}

void servoSerialControl(){
  if (Serial.available() > 2) {
    x =Serial.read();
    v =Serial.parseInt();
  if(x =='a'){
      panServo.write(v);  
    }
    delay(10);
  }
  y =Serial.read();
    v =Serial.parseInt();
  if(y =='b'){
      tiltServo.write(v);  
    }
    delay(10);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  panServo.attach(9);
  tiltServo.attach(10);
//  servo_pos(0);  
}

void loop() {
  servoSerialControl();
}
