// C++ code
//

int PIR = 2; // connecting the PIR sensor to pin 2
int ledPin = 13; // the built in LED is connected to pin 13

void setup() {
  pinMode(PIR, INPUT); // initialising PIR sensor as input
  pinMode(ledPin, OUTPUT); // initialising the led pin as output
  Serial.begin(9600); // start serial communication at 9600bps
}

void loop() {
  int sensorValue = digitalRead(PIR); // read from PIR sensor

  if (sensorValue == HIGH) { // if motion detected
    digitalWrite(ledPin, HIGH); // turn the LED ON
    Serial.println("Motion Detected!"); // prints motion detected on serial monitor
  } 
  else { // if there is no motion detected
    digitalWrite(ledPin, LOW); // turn the LED OFF
    Serial.println("No Motion Detected."); // print no motion detected on serial monitor
  }

  delay(1000); // wait for a second
}