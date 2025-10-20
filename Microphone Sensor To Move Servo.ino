const int micPin = A0;
const int ledPin = 7;
#include <Servo.h> // Import Servo Library

Servo my_servo;

int baseline = 0;         // Baseline sound level when powered on
int clapThreshold = 20;   // Amount above baseline to count as a clap

void setup() {
  pinMode(micPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  // Read initial baseline value once at startup
  baseline = analogRead(micPin);
  Serial.print("Baseline sound level: ");
  Serial.println(baseline);
  my_servo.attach(12);
  my_servo.write(0);
  digitalWrite(ledPin, LOW); // Make sure LED is off initially
}

void loop() {
  int micValue = analogRead(micPin);
  Serial.print("Mic value: ");
  Serial.println(micValue);

  // Wait for first clap (sound above baseline + threshold)
  if (micValue > baseline + clapThreshold) {
    Serial.println("First clap detected! Turning LED ON");
    digitalWrite(ledPin, HIGH);
    my_servo.write(180);
    delay(1000); //to prevent it from going immediately into the while loop
    // Now wait inside this while loop for the second clap
    while (true) {
      int micValue2 = analogRead(micPin);
      Serial.print("Waiting for second clap, mic value: ");
      Serial.println(micValue2);

      if (micValue2 > baseline + clapThreshold) {
        Serial.println("Second clap detected! Turning LED OFF");
        digitalWrite(ledPin, LOW);
        my_servo.write(0);
        delay(500);  // Small delay to avoid immediate re-trigger
        break;      // Exit the while loop back to waiting for the first clap
      }
      delay(50);
    }
  }
  delay(50);
}
