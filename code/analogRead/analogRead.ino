int pin = A0; // declare pin number for digital read
int analogVal = 0; // declare variable to store digital read value

void setup() {
  pinMode(pin, INPUT); // set pin as an input
  Serial.begin(9600); // begin serial so we can communicate with the Arduino over USB
}

void loop() {
  analogVal = analogRead(pin); // digital read pin and assign the reading to buttonVal
  Serial.println(analogVal); // print the button value in a new line in serial

  delay(50); // pause loop here for 50ms
}
