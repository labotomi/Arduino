/* 
   this is to test executing separate instances of each function.
   the code is simply to blink leds on pins 13 and 14 at unique intervals then print the value and next time the function will
   be executed for each separate led.
*/

long nextTime13 = 0;
long nextTime14 = 0;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
}
void loop() {
  if (nextTime13 < millis()) {
    nextTime13 = blink(1000, 13);
    prnt(13,nextTime13);
  }
  if (nextTime14 < millis()) {
    nextTime14 = blink(5000, 14);
    prnt(14,nextTime14);
  }
}

long blink(int interval, int led) {
  long nextTime;
  if (digitalRead(led) == LOW) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  nextTime = millis() + (interval/2);
  return nextTime;
}

void prnt(int led, long nextTime){
    Serial.print(led);
    Serial.print(": ");
    Serial.print(digitalRead(led));
    Serial.print("  ");
    Serial.print(nextTime);
    Serial.println(" ms");
}


