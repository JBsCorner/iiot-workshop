# SENSOR TO CLOUD: HANDS-ON IIOT WORKSHOP

This repository contains a hands-on workshop designed to emulate a complete industrial system: from the sensors taking measurements of the industrial process to the Cloud tools that allow for the storage and analysis of these data.

## USE CASE OVERVIEW
TBD

## ARCHITECTURE BUILDING BLOCKS
TBD

## PHASE 01: SENSING THE PHYSICAL WORLD
In this first phase, we will use a temperature sensor to determine the temperature of the process at each moment. For this purpose, in addition to a temperature sensor, we will need a device capable of taking measurements every few seconds and recording them. 

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
4. Program the Controllino to read from DHT11 sensor and print humidity and temperature:
    * Open Arduino IDE.
    * Install *DHT sensor library* by Adafruit from *Tools > Manage Libraries* (1.4.6 used).
    * Create a new code sketch from *File > New Sketch*.
    * Copy [this](https://github.com/JBsCorner/iiot-workshop/blob/main/code/controllino/controllino_dht11.ino) sketch code into Arduino IDE.
    * Upload the code into the Controllino board.
    * *Voilà*, now you should be able to see humidity and temperature readings being printed on your serial monitor.
      
   ![controllino_dht11_serial_monitor](https://github.com/JBsCorner/iiot-workshop/blob/main/images/controllino_dht11_serial_monitor.png?raw=true)

## PHASE 02: BRIDGING THE OT-IT GAP
We have successfully digitized various physical signals from our process. However, the true essence of IoT lies not just in data capture, but in its transmission for later processing and analysis. Therefore, the next stage involves enabling communication from our industrial device. We will use a specific industrial protocol to send the data to platforms capable of analyzing and maximizing the potential of this information.

### 02.A: CONTROLLINO THROUGH MODBUS TCP

Modbus TCP is a widely used communication protocol that enables the exchange of data between devices in industrial networks. It is an extension of the Modbus protocol, adapted for use over TCP/IP networks, which allows for the seamless integration of industrial devices with the infrastructure of the Internet. Essentially, Modbus TCP facilitates communication between a server, such as a PLC (Programmable Logic Controller) or an industrial computer, and one or more client devices. It operates on a client-server model, where the client initiates requests for data, and the server responds with the requested information. This protocol is highly regarded for its simplicity, reliability and ease of implementation.

![modbus_logo](https://github.com/JBsCorner/iiot-workshop/blob/main/images/modbus_logo.png?raw=true)

Modbus supports various types of registers and operations that facilitate diverse communication needs in industrial environments. The primary types of registers include Discrete Inputs and Coils, used for reading and writing boolean values, respectively, and Input Registers and Holding Registers, designed for reading and writing numerical values. Operations can be categorized into reading, where data is retrieved from these registers, and writing, where values are sent to be stored or to modify device settings.

![modbus](https://github.com/JBsCorner/iiot-workshop/blob/main/images/modbus_tables.png?raw=true)

**REQUIREMENTS**

**Hardware:**
* Previously used HW.
* Ethernet cable.

**Software:**
* Previously used SW.
* Node RED

**STEP BY STEP**
1. Download and install Node-RED by following the steps indicated on its official website: [https://nodered.org/](https://nodered.org/)
    * npm (used 10.4.0).
    * Node.js (used 20.11.0).
    * Node-RED (used 3.1.3).
2. Our Controllino will act as Modbus Server:
    * * Copy [this](https://github.com/JBsCorner/iiot-workshop/blob/main/code/controllino/controllino_dht11.ino) sketch code into Arduino IDE.
