#include <Servo.h>
#include <math.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(10);
  myservo.write(0);  
}

int old_pos = 0, new_pos = 0;

void loop() {
  while(Serial.available()) {
    new_pos = Serial.parseInt();
    Serial.println(new_pos);
    myservo.write(new_pos);
  }
}
