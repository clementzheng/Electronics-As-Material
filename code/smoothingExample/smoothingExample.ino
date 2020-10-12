int val = 0;
int pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Exponential Moving Average
  // https://www.megunolink.com/articles/coding/3-methods-filter-noisy-arduino-measurements/
  val = (val + analogRead(pin)) / 2;

  Serial.print(analogRead(pin));
  Serial.print(" ");
  Serial.print(val);
  Serial.println();

  delay(25);
}
