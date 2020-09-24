int pin = A0; // declare pin number for analog read
int analogVal = 0; // declare variable to store digital read value
int analogValPrev = 0; // declare variable to store previous button value
int threshold = 523;

void setup() {
  pinMode(pin, INPUT); // set pin as an input
  Serial.begin(9600); // begin serial so we can communicate with the Arduino over USB
}

void loop() {
  analogVal = analogRead(pin); // analog read pin and assign the reading to buttonVal
  
  if (analogVal >= threshold && analogValPrev < threshold) {
    Serial.println("pressed");
  } else if (analogVal < threshold && analogValPrev >= threshold) {
    Serial.println("released");
  }

  analogValPrev = analogVal; // update buttonValPrev with current button value
  
  delay(50); // pause loop here for 50ms
}
