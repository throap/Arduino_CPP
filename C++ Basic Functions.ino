const int LED1 = 13;
void blink ();
void hello ();

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
}

void blink () {
  digitalWrite(LED1, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
void hello () {
  Serial.println("HI!");
}

void loop() {
  blink();
  hello();
}
