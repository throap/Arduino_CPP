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
 ADC_val = analogRead(analog_pin);
 Serial.println(ADC_val);
 digital_map_LED = map(ADC_val, 0, 1023, 0, 225);
 analogWrite(LED, ADC_val);
}
