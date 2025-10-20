int enA = 9; // Enable pin for Motor A (PWM for speed control)
int in1 = 10; // Input 1 for Motor A (direction control)
int in2 = 11; // Input 2 for Motor A (direction control)

void setup() {
  // Set the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Initialize Serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Move forward at a specific speed
  digitalWrite(in1, HIGH); // Set direction
  digitalWrite(in2, LOW);
  analogWrite(enA, 200); // Set speed (0-255)
  Serial.println("Moving Forward");
  delay(3000); // Run for 3 seconds

  // Stop the motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0); // Set speed to 0
  Serial.println("Stopped");
  delay(1000); // Pause for 1 second

  // Move backward at a specific speed
  digitalWrite(in1, LOW); // Set direction
  digitalWrite(in2, HIGH);
  analogWrite(enA, 150); // Set speed (0-255)
  Serial.println("Moving Backward");
  delay(3000); // Run for 3 seconds

  // Stop the motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  Serial.println("Stopped");
  delay(1000);
}
