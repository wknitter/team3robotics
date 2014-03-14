void setup() {
  Serial.begin(9600);
  Serial.println("Warming up...");
  delay(20000);
}

void loop() {
  Serial.print("IN2=");
  Serial.println(digitalRead(2), DEC);
  delay(200);
}
