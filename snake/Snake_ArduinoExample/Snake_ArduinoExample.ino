int pinA = 3; // define digital pin number
int pinB = 4;
int pinC = 5;
int pinD = 6;
int pinE = 7;

int buttonValA = 0; // declare button value variables
int buttonValB = 0;
int buttonValC = 0;
int buttonValD = 0;
int buttonValE = 0;

void setup() {
  pinMode(pinA, INPUT_PULLUP); // set pin to INPUT_PULLUP
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinC, INPUT_PULLUP);
  pinMode(pinD, INPUT_PULLUP);
  pinMode(pinE, INPUT_PULLUP);

  Serial.begin(9600); // begin Serial communication
}

void loop() {
  
  buttonValA = digitalRead(pinA); // read digital pin value
  buttonValB = digitalRead(pinB);
  buttonValC = digitalRead(pinC);
  buttonValD = digitalRead(pinD);
  buttonValE = digitalRead(pinE);

  if (buttonValA > 0 && buttonValA < 2) { // if button value is 0, send a text command over Serial
    Serial.println("1");
  }

  if (buttonValA == 1) {
    
  }

  if (buttonValB == 0) {
    Serial.println("2");
  }

  if (buttonValC == 0) {
    Serial.println("3");
  }

  if (buttonValD == 0) {
    Serial.println("4");
  }

  if (buttonValE == 0) {
    Serial.println("5");
  }

  delay(30); // delay for 30ms

}
