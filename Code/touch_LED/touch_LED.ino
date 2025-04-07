int touch = 0;
int TouchSensitivity = 200;
int led = 8;

void setup() {
  Serial.begin(115200);
  //touch pin
  pinMode(A0, INPUT);
  //LED pin
  pinMode(led, OUTPUT);

}

void loop() {
  //read input data
  touch = 1024 - analogRead(A0);

  if (touch >= TouchSensitivity) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  Serial.println(touch);
  delay(100);
}
