#include <Servo.h>

// -------------------- PIN ASSIGNMENTS --------------------
const int trigPin = 2;        // Ultrasonic trigger
const int echoPin = 3;        // Ultrasonic echo

const int servoPin = 5;       // Easy PWM pin for a servo
const int pressurePin = A0;   // Analog input for pressure plate
const int solenoidPin = 8;    // Digital output to transistor/relay

// -------------------- OBJECTS --------------------
Servo gateServo;

// -------------------- VARIABLES --------------------
long duration;
int distance;
const int triggerDistance = 20;   // cm distance to activate servo
const int pressureThreshold = 300; // adjust after testing

// -------------------------------------------------------------
void setup() {
  Serial.begin(9600);

  // Ultrasonic setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo setup
  gateServo.attach(servoPin);
  gateServo.write(0);

  // Pressure plate
  pinMode(pressurePin, INPUT);

  // Solenoid output
  pinMode(solenoidPin, OUTPUT);
  digitalWrite(solenoidPin, LOW);     // OFF initially

  Serial.println("System Ready");
}

void loop() {

  // ---------- ULTRASONIC READING ----------
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;    // speed of sound conversion

  Serial.print("Distance: ");
  Serial.println(distance);

  // ---------- TRIGGER SERVO IF MOTION CLOSE ----------
  if (distance > 0 && distance <= triggerDistance) {
    Serial.println("Motion detected! Opening gate...");
    gateServo.write(180);  // open gate for marble
    delay(1000);           // keep open long enough for marble to roll
  }

  // ---------- READ PRESSURE PLATE ----------
  int pressureValue = analogRead(pressurePin);
  Serial.print("Pressure: ");
  Serial.println(pressureValue);

  // If marble hits the plate
  if (pressureValue > pressureThreshold) {
    Serial.println("Marble detected! Activating solenoid...");
    digitalWrite(solenoidPin, HIGH);   // fire solenoid
    delay(500);                         // push car

    digitalWrite(solenoidPin, LOW);     // turn solenoid off
    delay(1000);                        // small buffer time
  }

  delay(50); // loop smoothing
}
