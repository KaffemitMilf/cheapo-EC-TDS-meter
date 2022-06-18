#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  delay(1000);  //added to give the onewire stuff time to initialize.
  sensors.begin();

  pinMode(8, OUTPUT);
}

void loop() {
  Serial.println("-----------------------------------------");
  Serial.print(measureEC());
  delay(10000);
  Serial.println("-----------------------------------------");
}
  


float measureEC(){
  //turn on pin 8
  digitalWrite(9, HIGH);
  
  // measure R2
  int unconvertedVReading = analogRead(A5);
  unconvertedVReading = analogRead(A5);
  //turn off pin 9
  
  digitalWrite(9, LOW);

  //convert Reading into voltage
  float voltage = (5.0f/1024.0f)*unconvertedVReading;
  
  // your r1 value
  int r1 = 470;
  //calculating r2
  float r2 = (voltage* r1)/(5.0f-voltage);

  //resistance per cm
  float rCm = (r2/0.6);
 
  //calculate ec/cm 
  float ec = (1.0f/rCm);

  //measure temperature
  float temp = measureTemp();

  
  //compensate temperature
  float ec25 = ec / (1.0f + 0.019f * (temp - 25.0));
  ec25 = ec25* pow(10,6);
  //μS
  
  return ec25;
  
}



float measureTemp() {
  sensors.requestTemperatures(); //needed, cause otherwise temperature conversion wont take place
  return sensors.getTempCByIndex(0);
}
