import processing.serial.*;

void setup() {
  
  for (int i=0; i<Serial.list().length; i++) {
    print("[", i, "]");
    print(Serial.list()[i]);
    println();
  }
  
  exit();
}
