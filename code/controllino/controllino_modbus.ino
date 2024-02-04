/*
 * IIOT WORKSHOP
 * @author: Juan Benavente
 */

//LIBRARIES -----------------------------------------------------------------
#include <SPI.h>
#include <Controllino.h>
#include "DHT.h"
#include <Ethernet.h>
#include <ArduinoRS485.h>
#include <ArduinoModbus.h>


//DEFINITIONS ---------------------------------------------------------------
#define DHTTYPE DHT11             // DHT 11 Sensor Type
#define DHTPIN CONTROLLINO_D0     // Digital pin connected to the DHT sensor
#define LED1 CONTROLLINO_D1       // Status LEDs
#define LED2 CONTROLLINO_D2
#define LED3 CONTROLLINO_D3
#define LED4 CONTROLLINO_D4
#define LED5 CONTROLLINO_D5

//GLOBAL DECLARATIONS -------------------------------------------------------
DHT dht(DHTPIN, DHTTYPE);
// Controllino's MAC address
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// Controllino's Address
IPAddress ip(10, 0, 0, 1);
// Modbus Server 
EthernetServer ethServer(502);
ModbusTCPServer modbusTCPServer;
// Update Interval
long updateInterval = 2000; // Initial delay
unsigned long lastUpdateTime = 0;
// LEDs
const int ledPins[] = {LED1, LED2, LED3, LED4, LED5};
const int ledNumber[] = {1, 2, 3, 4, 5};
const int numLeds = 5;
int ledStatus[] = {LOW, LOW, LOW, LOW, LOW};

//SETUP ---------------------------------------------------------------------
void setup() {
  // Initialization ---------------------------------------------------------
  // Serial
  Serial.begin(9600); // Serial
  while (!Serial) {
    ;
  }             
  Serial.println("Initializing Device");

  // DHT Sensor
  dht.begin();

  // Ethernet
  Ethernet.begin(mac, ip); // Ethernet  
  if (Ethernet.hardwareStatus() == EthernetNoHardware) { // Check for Ethernet hardware present
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) { // Check for Ethernet cable
    Serial.println("Ethernet cable is not connected.");
  }
  ethServer.begin();
  
  // Modbus server
  if (!modbusTCPServer.begin()) {
    Serial.println("Failed to start Modbus TCP Server!");
    while (1);
  }
  // Modbus Registers
  modbusTCPServer.configureCoils(0, 5);               // LED Status
  modbusTCPServer.configureInputRegisters(100, 2);    // Humidity, Temperature
  modbusTCPServer.configureHoldingRegisters(400, 1);  // Delay Configuration
  modbusTCPServer.holdingRegisterWrite(400, static_cast<uint16_t>(updateInterval));

  // LEDs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i],ledStatus[i]);
  }
  Serial.println("Device Initialized");
}

//LOOP ----------------------------------------------------------------------
void loop() {
  // Update sensor registries
  updateDht();

  // Modbus Clients
  EthernetClient client = ethServer.available();
  if (client) { // a new client connected
    Serial.println("New Modbus client");
    modbusTCPServer.accept(client);
    while (client.connected()) {
      // poll for Modbus TCP requests, while client connected
      modbusTCPServer.poll();
      // Update the LEDs
      updateLeds();
      // Update sensor registries
      updateDht();
      // Update Interval
      long newUpdateInterval = modbusTCPServer.holdingRegisterRead(400);
      if (newUpdateInterval != updateInterval ){
        updateInterval = newUpdateInterval;
        Serial.print("New Update Interval: ");
        Serial.println(updateInterval);
      }
    }
    Serial.println("Modbus client disconnected");
  }
}

//UPDATE DHT SENSOR REGISTRIES -----------------------------------------------
void updateDht(){
  unsigned long currentMillis = millis();
  if (currentMillis - lastUpdateTime >= updateInterval) {
    // Read variables
    float h = dht.readHumidity();     // Humidity
    float t = dht.readTemperature();  // Temperature (Celsius)
    uint16_t hUint = h*100;                   // Humidity
    uint16_t tUint = t*100;                   // Temperature (Celsius)
    // Write modbus registers
    modbusTCPServer.writeInputRegisters(100, (uint16_t*)&hUint, 1);
    modbusTCPServer.writeInputRegisters(101, (uint16_t*)&tUint, 1);
    // Update time
    lastUpdateTime = currentMillis;
    
    // Serial Print New Measurement
    Serial.print("Humidity ");
    Serial.print(h);
    Serial.print(" %t. ");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C ");
  }
}

//UPDATE STATUS LEDS ---------------------------------------------------------
void updateLeds() {
  int coilValue = 0;
  for (int i = 0; i < numLeds; i++) {
    coilValue = modbusTCPServer.coilRead(i);
    if(coilValue != ledStatus[i]){
      if (coilValue) {
        digitalWrite(ledPins[i], HIGH);
        Serial.print("LED ");
        Serial.print(ledNumber[i]);
        Serial.println(" activado");
        ledStatus[i] = HIGH;
      } else {
        digitalWrite(ledPins[i], LOW);
        Serial.print("LED ");
        Serial.print(ledNumber[i]);
        Serial.println(" desactivado");
        ledStatus[i] = LOW;
      }
    }
  }
}

