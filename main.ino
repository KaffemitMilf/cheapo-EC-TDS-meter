#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define voltageDividerOutput A5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  delay(1000);  //added to give the onewire stuff time to initialize.
  sensors.begin();

  pinMode(8, OUTPUT);
}

void loop() {
  Serial.println(measureEC());
  delay(10000);
}
  


float measureEC(){
  digitalWrite(8,HIGH);
  // read the input on analog pin 0:
  float sensorValue = analogRead(voltageDividerOutput);

  digitalWrite(8,LOW);
  // convert analog input (0-1024) to a voltage, voltage between :
  float vOut = sensorValue * (5.0f / 1024.0f);

  // change this float to your value of R1
  float valueR1 = 1000.0f;
  // calculate R2, 5 = Vin which is 5V in my case
  float valueR2 = (vOut*valueR1) / (5.0f-vOut);
  Serial.println(valueR2);

  // calculating Resistance/cm
  float Rcm = valueR2/0.6;

  // calculating EC and covert it to microS/cm
  float EC = (1.0f/Rcm)*1000000.0f;
  
  // compensate water temp.
  float EC25 = EC / (1.0f + 0.019f * (measureTemp() - 25));

  return EC25;
}
  

float measureTemp() {
  sensors.requestTemperatures(); //needed, cause otherwise temperature conversion wont take place
  return sensors.getTempCByIndex(0);
}
