int led = 13;
int photo = A0;

float MPH;
long time1;
long afterTime;
long currentTime;
float cmms;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(photo, INPUT);
  Serial.begin(9600);
  digitalWrite(led, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogRead(A0);
  delay(1);

 while (analogRead(A0) > 900) { //>500 when the gate is not blocked. 
   ;//  
}
  currentTime = millis();
  delay(50);

while (analogRead(A0) < 900) {
 ;//
}

  afterTime = millis();
  delay(50);
  
  time1 = afterTime - currentTime;
  Serial.print("MS =");
  Serial.println(time1);
  cmms =  8.5/time1; 
  MPH = cmms * 22.369;
  Serial.print("MPH = ");
  Serial.println(MPH);
  delay(250);
  time1 = 0;

}
