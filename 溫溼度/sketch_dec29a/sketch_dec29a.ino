#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 3
#define DHTTYPE    DHT22 
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  delay(1000);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  if(event.temperature>27 && event.temperature<29 )
  {
    digitalWrite(2,LOW);
  }
  else
  {
    digitalWrite(2,HIGH);
  }
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }      
}
