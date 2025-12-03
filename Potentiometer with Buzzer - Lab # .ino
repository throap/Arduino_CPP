int readSensor();
const int buzzer = 13;

void setup() {
  Serial.begin(9600);
}

void loop() { 
	int sensor_value = readSensor(); // returned value 
	Serial.println(sensor_value);

  if (sensor_value < 523 )
    digitalWrite(buzzer, HIGH);
  else 
    digitalWrite(buzzer, LOW);
}
//FUNCTION
int readSensor() { 
	int value = analogRead(A0); 
	return value; // send value back 
}
