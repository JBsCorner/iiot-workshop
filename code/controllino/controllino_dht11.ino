/*
 * IIOT WORKSHOP
 * @author: Juan Benavente
 */

//LIBRARIES -----------------------------------------------------------------
#include <SPI.h>
#include <Controllino.h>
#include "DHT.h"

//DEFINITIONS ---------------------------------------------------------------
#define DHTTYPE    DHT11          // DHT 11 Sensor Type
#define DHTPIN CONTROLLINO_D0     // Digital pin connected to the DHT sensor

//GLOBAL DECLARATIONS -------------------------------------------------------
DHT dht(DHTPIN, DHTTYPE);

//SETUP ---------------------------------------------------------------------
void setup() {
  // Initialize serial communication
  Serial.begin(9600);                 
  // Initialize DHT device.
  Serial.println("Initializing...");  
  dht.begin();
}

//LOOP ----------------------------------------------------------------------
void loop() {
  // Delay between measurements.
  delay(2000);

  // Read variables
  float h = dht.readHumidity();     // Humidity
  float t = dht.readTemperature();  // Temperature (Celsius)

  // Serial Print
  Serial.print("Humidity ");
  Serial.print(h);
  Serial.print(" %t. ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}
