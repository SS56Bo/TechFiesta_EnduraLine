//this is a simple Arduino code that we use to light an LED 
// for this we put the negative side of the LED on the GND and 
// the positive side on the 13 pin

//NOTE: You can also use the 12 pin or any of the pins used 
//however, you should chnage the LED value to that 
//corresponding pin 
int LED = 13;
int delayTime = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(delayTime); 
  digitalWrite(LED, LOW); 
  delay(delayTime); 
}
