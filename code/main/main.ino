#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  delay(1000);  //added to give the onewire stuff time to initialize.
  sensors.begin();

  pinMode(9, OUTPUT);
}

void loop() {
  Serial.println("-----------------------------------------");
  Serial.println(String(measureEC()) + "microS");
  delay(10000);
  Serial.println("-----------------------------------------");
}
  


float measureEC(){
  //turn on pin 8
  digitalWrite(8, HIGH);
  delay(500);
 
  
  // measure R2
  int unconvertedReading = analogRead(A5);
  unconvertedReading = analogRead(A5);
  
  //turn off pin 8
  digitalWrite(8, LOW);

  //convert Reading into voltage
  float voltage = (5.0f/1024.0f)*unconvertedReading;
  
  // your r1 value
  int r1 = 470;
  //calculating r2, 
  float r2 = (voltage* r1)/(5.0f-voltage)-25;
  Serial.println(String(r2)+"R2");
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
