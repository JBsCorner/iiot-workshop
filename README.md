# SENSOR TO CLOUD: HANDS-ON IIOT WORKSHOP

This repository contains a hands-on workshop designed to emulate a complete industrial system: from the sensors that take measurements of the industrial process to the Cloud tools that allow for the storage and analysis of these data.

## USE CASE OVERVIEW
TBD

## ARCHITECTURE BUILDING BLOCKS
TBD

## PHASE 01: SENSING THE PHYSICAL WORLD
In this first step, we will use a temperature sensor to determine the temperature of the process at each moment. For this purpose, in addition to a temperature sensor, we will need a device capable of taking measurements every few seconds and recording them. 

The sensor we will be using is a basic temperature and humidity sensor, specifically the DHT11 model. This sensor offers the following key features:
| Feature        | DHT11                        |
|----------------|------------------------------|
| **Power Supply**    | 3.3V to 5V                  |
| **Consumption**     | 2.5 mA                      |
| **Output Signal**   | Digital                     |
| **TEMPERATURE**     |                             |
| Range           | 0°C to 50°C                  |
| Accuracy        | +/- 2°C at 25°C              |
| Resolution      | 1°C                          |
| **HUMIDITY**        |                             |
| Range           | 20% to 90% RH                |
| Accuracy        | +/- 5%                       |
| Resolution      | 1%                           |

![imagen dht11](https://github.com/JBsCorner/iiot-workshop/blob/main/images/dht11.jpg?raw=true)

We can find such sensors both 

### 01.A: CONTROLLINO MAXI
The Controllino is a programmable controller based on the Arduino platform, specifically designed for industrial automation applications projects. This device merges the ease of Arduino programming with the necessary capabilities to control and operate industrial machinery, manufacturing processes, and building automation systems. It offers a variety of digital and analog inputs and outputs and can handle high current loads, making it ideal for a broad range of industrial applications. Its compatibility with Arduino software allows engineers and developers to easily create customized solutions, while its sturdy construction ensures reliability in demanding industrial environments.

![imagen dht11](https://github.com/JBsCorner/iiot-workshop/blob/main/images/controllino_maxi.png?raw=true)

**REQUIREMENTS**
**Hardware:**
* Controllino Maxi.
* Controllino Power Supply.
* USB Type-B to Type-A connector.
* DHT11 Sensor.
* PC/Laptop (Windows OS used for this tutorial).

**Software:**
* Arduino IDE.

**STEP BY STEP**
