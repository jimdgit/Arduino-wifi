/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  // initialize digital pin 13 as an output.
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
int count = 0;
// the loop function runs over and over again forever
void loop() {
  ++count;
  Serial.print("Count : ");
  Serial.println(count);
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
}
