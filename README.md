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

![imagen dht11](https://github.com/JBsCorner/iiot-workshop/blob/main/images/dht11_board.png?raw=true)

### 01.A: CONTROLLINO MAXI
The Controllino is a programmable controller based on the Arduino platform, specifically designed for industrial automation applications projects. This device merges the ease of Arduino programming with the necessary capabilities to control and operate industrial machinery, manufacturing processes, and building automation systems. It offers a variety of digital and analog inputs and outputs and can handle high current loads, making it ideal for a broad range of industrial applications. Its compatibility with Arduino software allows engineers and developers to easily create customized solutions, while its sturdy construction ensures reliability in demanding industrial environments.

![imagen controllino_maxi](https://github.com/JBsCorner/iiot-workshop/blob/main/images/controllino_maxi.png?raw=true)

**REQUIREMENTS**

**Hardware:**
* Controllino Maxi.
* Controllino Power Supply.
* USB Type-B to Type-A connector.
* DHT11 Sensor.
* 3 Jumper wires.
* PC/Laptop (Windows 10 used).

**Software:**
* Arduino IDE (2.2.1 used)

**STEP BY STEP**
1. Download and install Arduino IDE from the official webpage: [https://www.arduino.cc/](https://www.arduino.cc/).
2. Controllino setup: 
    * Connect the Controllino Maxi to your Laptop or PC using the USB cable.
    * Connect Controllino's Power Supply (USB cable might be enough for some applications).
    * Install Controllino's library (3.0.7 used) and Board Hardware Definition following [these](https://www.controllino.com/board-library-setup-in-arduino-ide/) steps.
    * You can load and test some of the provided examples from *File > Examples* to validate proper operation.
3. Using the jumper wires, connect de DHT11 sensor to the Controllino Maxi.
   ![imagen controllino_dht11_wiring](https://github.com/JBsCorner/iiot-workshop/blob/main/images/controllino_dht11_wiring.png?raw=true)
5.aa 
