#include <SharpIR.h>

int L_Speed = 46;
int L_Forward = 23;
int L_Back = 22;
int R_Speed = 45;
int R_Forward = 24;
int R_Back = 25;

void setup() {
  // put your setup code here, to run once:
  pinMode(L_Speed, OUTPUT);
  pinMode(L_Forward, OUTPUT);
  pinMode(L_Back, OUTPUT);
  pinMode(R_Speed, OUTPUT);
  pinMode(R_Forward, OUTPUT);
  pinMode(R_Back, OUTPUT);
}

void right_Forward() {
  digitalWrite(R_Forward, 1);
  digitalWrite(R_Back, 0);
}

void right_Reverse() {
  digitalWrite(R_Back, 1);
  digitalWrite(R_Forward, 0);
}

void left_Forward() {
  digitalWrite(L_Forward, 1);
  digitalWrite(L_Back, 0);
}

void left_Reverse() {
  digitalWrite(L_Back, 1);
  digitalWrite(L_Forward, 0);
}

void Forward(int a) {
  analogWrite(L_Speed, a);
  analogWrite(R_Speed, a);
  left_Forward();
  right_Forward();
//  LeftCount = LeftDistance = 0;
//  RightCount = RightDistance = 0;
}

void Reverse(int a) {
  analogWrite(L_Speed, a);
  analogWrite(R_Speed, a);
  left_Reverse();
  right_Reverse();
}

void LeftTurn(int a) {
  analogWrite(L_Speed, a);
  analogWrite(R_Speed, a);
  right_Forward();
  left_Reverse();
}

void RightTurn(int a) {
  analogWrite(L_Speed, a);
  analogWrite(R_Speed, a);
  right_Reverse();
  left_Forward();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 4; i++) {
   Forward(200);
  delay(5000);
  RightTurn(200);
  delay(1250); 
  }
}
