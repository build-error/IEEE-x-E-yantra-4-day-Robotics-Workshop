void setup() {
   // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int led_status = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    led_status = Serial.parseInt();
    Serial.println(led_status);
  }

  while(!Serial.available()) {
    digitalWrite(13, led_status);
  }
}
