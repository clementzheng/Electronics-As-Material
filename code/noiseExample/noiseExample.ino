#include <CapacitiveSensor.h> // add the CapacitiveSensor library

long capVal = 0;
long capValPrev = 0;
long differenceVal = 0;

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2); // 1MOhm resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup() {
  cs_4_2.set_CS_Timeout_Millis(50); // set a limit to how long the capacitive sensor takes for each reading
  capVal =  cs_4_2.capacitiveSensor(30);
  capValPrev = capVal;
  
  Serial.begin(9600);
}

void loop() {
  capVal =  cs_4_2.capacitiveSensor(30);

  differenceVal = abs(capVal - capValPrev);

  Serial.println(differenceVal);

  capValPrev = capVal;
  delay(25); // arbitrary delay to limit data to serial port
}
