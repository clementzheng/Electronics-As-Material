int pin = 7; // declare pin number for digital read
int buttonVal = 1; // declare variable to store digital read value
int buttonValPrev = 1; // declare variable to store previous button value

void setup() {
  pinMode(pin, INPUT_PULLUP); // set pin as an input
  Serial.begin(9600); // begin serial so we can communicate with the Arduino over USB
}

void loop() {
  buttonVal = digitalRead(pin); // digital read pin and assign the reading to buttonVal
  
  // when the button is pressed, buttonVal = 0
  // if buttonValPrev = 1 (not pressed), then buttonVal - buttonValPrev = -1
  // hence, a negative value means the button was just pressed
  // vice versa, a positive value means the button was just released
  if (buttonVal - buttonValPrev < 0) {
    Serial.println("pressed");
  } else if (buttonVal - buttonValPrev > 0) {
    Serial.println("released");
  }

  buttonValPrev = buttonVal // update buttonValPrev with current button value
  
  delay(50); // pause loop here for 50ms
}
