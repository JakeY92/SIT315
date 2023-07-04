// Pins
int PIR = 2; // Connecting the PIR sensor to pin 2
int ledPin = 13; // The built-in LED is connected to pin 13
volatile int sensorState = LOW; // Variable to store the current state of PIR sensor

void setup() {
  pinMode(PIR, INPUT); // Initialising PIR sensor as input
  pinMode(ledPin, OUTPUT); // Initialising the LED pin as output
  Serial.begin(9600); // Start serial communication at 9600bps

  // Attach an interrupt to the PIR sensor pin
  attachInterrupt(digitalPinToInterrupt(PIR), motionDetected, CHANGE);
}

void loop() {
  // Read the sensor's state and act accordingly
  if (sensorState == HIGH) { // If motion detected
    digitalWrite(ledPin, HIGH); // Turn the LED ON
    Serial.println("Motion Detected!"); // Prints "Motion Detected" on the serial monitor
  } else { // If there is no motion detected
    digitalWrite(ledPin, LOW); // Turn the LED OFF
    Serial.println("No Motion Detected."); // Print "No Motion Detected" on the serial monitor
  }

  delay(1000); // Wait for a second
}

void motionDetected() {
  sensorState = digitalRead(PIR); // Update the sensor's state
}
