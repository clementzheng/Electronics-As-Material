// Read data from the serial and turn ON or OFF a light depending on the value

char val; // Data received from the serial port

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  while (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }
  if (val == 'E') { 
    // If E was sent, i.e. an apple was eaten, do something here
  } else if (val == 'D') { 
    // If D was sent, i.e. snake died, do something here
  }

  delay(25);
}
