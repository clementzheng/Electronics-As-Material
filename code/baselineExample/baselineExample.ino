int baseline = 0;
int val = 0;
int threshold = 100;

int pin = A0;

void setup() {

  // Take the first analog reading
  baseline = analogRead(pin);

  // Take many analog readings for two seconds
  // average the new analog readings with the baseline
  while (millis() < 2000) {
    baseline = (baseline + analogRead(pin)) / 2;
  }

  Serial.begin(9600);

}

void loop() {

  val = analogRead(pin) - baseline;

  // Serial print multiple value, seperated by a space
  Serial.print(val);
  Serial.print(" ");
  Serial.print(-threshold);
  Serial.print(" ");
  Serial.print(threshold);
  Serial.println(); // Print a line break

  delay(25);

}
