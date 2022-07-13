#include <Servo.h>
#include <math.h>

Servo panServo;
Servo tiltServo;

char x, y;
long int v;

void servoSerialControl(){
  if (Serial.available() > 2) {
    x = Serial.read();
    v = Serial.parseInt();
  if(x =='a'){
      panServo.write(v);  
    }
    delay(10);

  if(x =='b'){
      tiltServo.write(v);  
    }
    delay(10);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  panServo.attach(10);
  tiltServo.attach(11);
}

void loop() {
  servoSerialControl();
}
