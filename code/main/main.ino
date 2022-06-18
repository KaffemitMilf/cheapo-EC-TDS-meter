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
  measureEC();
  delay(5000);
}
  


float measureEC(){
  //turn on pin 8
  digitalWrite(8, HIGH);
  
  // measure R2
  int unconvertedVReading = analogRead(A0);
  unconvertedVReading = analogRead(A0);
  //turn off pin 8
  
  digitalWrite(8, LOW);

  //convert Reading into voltage
  float voltage = (unconvertedVReading*5.0f)/1024.0;
  Serial.println(voltage);
  // your r1 value
  int r1 = 1000;
  //calculating r2
  Serial.println(voltage);
  float r2 = (voltage* r1)/(5.0f-voltage);
  Serial.println(r2);
  //resistance per cm
  float rCm = (r2/0.6);
  Serial.println(rCm);
 
  //calculate ec/cm 
  float ec = (1.0f/rCm);
  Serial.println(ec,32);
  //compensate temperature
  float ec25 = ec / (1.0f + 0.019f * (measureTemp() - 25.0));
  Serial.println(ec25,32);
  return ec25;
  
}



float measureTemp() {
  sensors.requestTemperatures(); //needed, cause otherwise temperature conversion wont take place
  return sensors.getTempCByIndex(0);
}
