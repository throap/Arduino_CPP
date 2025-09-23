// C++ code
//
const int analog_pin = A0;
int ADC_val = 0;
int LED = 7;
int digital_map_LED;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(analog_pin, INPUT);
}

void loop()
{
  //baisc read and write analog pin values
  ADC_val = analogRead(analog_pin);
  Serial.println(ADC_val);
  digital_map_LED = map(ADC_val, 0, 1023, 0, 225);
  analogWrite(LED, ADC_val);

  //if statements below
  if(ADC_val<=255){
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
  else if(ADC_val<=520){
    digitalWrite(LED, HIGH);
    delay(750);
    digitalWrite(LED, LOW);
    delay(750);
  }
  else if(ADC_val<=755){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
  else {
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
}
