#include <Servo.h>

// -------------------- PIN ASSIGNMENTS --------------------
const int trigPin = 2;        
const int echoPin = 3;        

const int servoPin = 5;       
const int pressurePin = A0;   
const int solenoidPin = 8;    

// -------------------- OBJECTS --------------------
Servo gateServo;

// -------------------- VARIABLES --------------------
long duration;
int distance;

const int triggerDistance = 100;   // cm
const int pressureThreshold = 300;

// -------------------------------------------------------------
void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gateServo.attach(servoPin);
  gateServo.write(0);  // start closed

  pinMode(pressurePin, INPUT);

  pinMode(solenoidPin, OUTPUT);
  digitalWrite(solenoidPin, LOW);

  Serial.println("System Ready");
}

// -------------------------------------------------------------
void loop() {

  // ---------- ULTRASONIC READING ----------
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // ---------- TRIGGER SERVO IF MOTION CLOSE ----------
  if (distance > 0 && distance < triggerDistance) {
    Serial.println("Motion detected! Opening gate...");
    gateServo.write(180);
    delay(1500);     // allow marble to roll
  }

  // ---------- PRESSURE PLATE ----------
  int pressureValue = analogRead(pressurePin);
  Serial.print("Pressure: ");
  Serial.println(pressureValue);

  if (pressureValue > pressureThreshold) {
    Serial.println("Marble detected! Activating solenoid...");
    digitalWrite(solenoidPin, HIGH);
    delay(500);
    digitalWrite(solenoidPin, LOW);
    delay(1000);
  }

  delay(50);
}
