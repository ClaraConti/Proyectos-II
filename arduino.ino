#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 2      // Pin de datos del DHT11
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);


SoftwareSerial BT(10, 11); 

void setup() {
  Serial.begin(9600); 
  BT.begin(9600); 
  dht.begin();
  Serial.println("Iniciando Control ...");
}

void loop() {
  
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer del sensor DHT11!");
  } else {
    String datos = "Temp:" + String(temperatura) + ", Hum:" + String(humedad);
    Serial.println(datos);

    
    BT.println(datos);
  }

  delay(2000);
}