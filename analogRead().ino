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
    analogWrite(LED, ADC_val);
    delay(200);
    analogWrite(LED, 0);
    delay(200);
  }
  else if(ADC_val<=520){
    analogWrite(LED, ADC_val);
    delay(500);
    analogWrite(LED, 0);
    delay(500);
  }
  else if(ADC_val<=755){
    analogWrite(LED, ADC_val);
    delay(700);
    analogWrite(LED, 0);
    delay(700);
  }
  else {
    analogWrite(LED, ADC_val);
    delay(1000);
    analogWrite(LED,0);
    delay(1000);
  }
}
