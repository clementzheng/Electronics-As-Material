#include <CapacitiveSensor.h> // add the CapacitiveSensor library

long capVal = 0;

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2); // 1MOhm resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup() {
  cs_4_2.set_CS_Timeout_Millis(50); // set a limit to how long the capacitive sensor takes for each reading
  Serial.begin(9600); // begin serial so we can communicate with the Arduino over USB
}

void loop() {
  capVal =  cs_4_2.capacitiveSensor(30);
  Serial.println(capVal); // print the capacitive sensor value in a new line in serial
  
  delay(50); // arbitrary delay to limit data to serial port
}
