int led = 13; // attach led to pin 13
int photo = A0; // attach the photoresistor to analog pin 0

float MPH; // makes an interger called MPH
long time1; // makes an integer called time1
long afterTime; // makes an integer called afterTime
long currentTime; // makes an integer called currentTime
float cmms; // makes an integer called cmms

void setup() { // put your setup code here, to run once:
  pinMode(led, OUTPUT); // makes the led an output
  pinMode(photo, INPUT); // makes the photoresistor an input
  Serial.begin(9600); // starts serial monitor at 9600 baud
  digitalWrite(led, HIGH); // writes the led high

}

void loop() { // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0); // makes an integer called sensorValue equal to whatever A0 is reading
  delay(1); // delays 1 milisecond

  while (analogRead(A0) > 900) { // >500 when the gate is not blocked.
    ; // ask Josh ¯\_(ツ)_/¯
  }
  currentTime = millis(); // makes the current time equal to the millis int
  delay(50); // delays 50 miliseconds

  while (analogRead(A0) < 900) { // <500 when gate is blocked
    ; // ¯\_(ツ)_/¯
  }

  afterTime = millis(); // makes an int called afterTime = to millis
  delay(50); // delays 50 miliseconds

  time1 = afterTime - currentTime; // makes time 1 equal to afterTime-currentTime
  Serial.print("MS = "); // serial prints "MS = "
  Serial.print(time1); // serial prints the time1 integer
  cmms =  8.5 / time1; // makes cmms equal to 8.5/time1
  MPH = cmms * 22.369; // makes MPH equal to cmms * 22.369
  Serial.println("MPH = "); // serial prints "MPH = "
  Serial.print(MPH); // serial prints the MPH integer
  delay(250); // delays 250 miliseconds
  time1 = 0; // makes time equal to 0

}
