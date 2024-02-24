# FACTORY TO CLOUD: HANDS-ON IIOT WORKSHOP

This repository contains a hands-on workshop designed to emulate a complete industrial system: from the sensors taking measurements of the industrial process to the Cloud tools that allow for the storage and analysis of these data.

## USE CASE OVERVIEW
TBD

## ARCHITECTURE BUILDING BLOCKS

![architecture_overview](https://github.com/JBsCorner/iiot-workshop/blob/main/images/architecture_overview.jpg?raw=true)

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
  
#### 01.A.01: OUR FIRST SENSOR

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

#### 01.A.02: FULL PUMP MONITORING

**STEP BY STEP**
* TBD
  
### 01.B: VIRTUAL PLC

For those who do not have the necessary hardware, we will proceed to simulate a PLC with all the necessary sensors to monitor the pump. To do this, we will use the Node-RED tool.

Node-RED is an open-source programming tool for wiring together hardware devices, APIs, and online services.. It provides a browser-based editor that makes it easy to wire together flows using the wide range of nodes in the palette that can be deployed to its runtime in a single click. Designed to be lightweight and built on Node.js, Node-RED is ideal for creating Internet of Things (IoT) applications with ease. It enables users to connect devices, services, and APIs with a simple drag-and-drop interface, allowing for complex systems to be developed without the need for traditional programming. Node-RED's visual approach to programming is particularly suited for managing data streams from sensors and actuators, processing and analyzing data in real-time, and integrating various data sources and services into a cohesive system. With its extensive library of nodes and the ability to add custom nodes, Node-RED is a versatile tool that can be adapted to a wide range of IoT projects and workflows.

![nodered_logo](https://github.com/JBsCorner/iiot-workshop/blob/main/images/nodered_logo.png?raw=true)

**REQUIREMENTS**

**Hardware:**
* PC/Laptop (Windows 10 used).

**Software:**
* Node RED.

**STEP BY STEP**
1. We will use Node-RED to create our Virtual PLC. Download and install Node-RED by following the steps indicated on its official website: [https://nodered.org/](https://nodered.org/)
    * npm (used 10.4.0).
    * Node.js (used 20.11.0).
    * Node-RED (used 3.1.3).
      
2. Install the following Node-RED modules:
    * node-red-dashboard (3.3.1 used).
      
3. We will now create the Virtual PLC using Node-RED programming and dashboarding capabilities:
    * Import and Deploy [this flow](https://github.com/JBsCorner/iiot-workshop/blob/main/code/node-red/nodered_virtualplc.json) into your environment.
      ![nodered_virtualplcflow](https://github.com/JBsCorner/iiot-workshop/blob/main/images/nodered_virtualplcflow.png?raw=true)
    * Open Node-RED UI at http://localhost:1880/ui and your Virtual PLC will load. You can check change sampling interval, activate/deactivate sensors and change simulated measurments limits.
      ![nodered_virtualplcdashboard](https://github.com/JBsCorner/iiot-workshop/blob/main/images/nodered_virtualplcdashboard.png?raw=true)

## PHASE 02: VISUALIZING THE INDUSTRIAL PROCESS
We have successfully digitized various physical signals from our process. However, it is currently difficult for a human to know the status of the industrial process or to act upon it. Therefore, in this phase, we will establish communication through industrial protocols between our industrial device and an HMI (Human Machine Interface) with the goal of being able to visualize the information and allow basic actions.

We will take advantage of Modbus TCP for this task. Modbus TCP is a widely used communication protocol that enables the exchange of data between devices in industrial networks. It is an extension of the Modbus protocol, adapted for use over TCP/IP networks, which allows for the seamless integration of industrial devices with the infrastructure of the Internet. Essentially, Modbus TCP facilitates communication between a server, such as a PLC (Programmable Logic Controller) or an industrial computer, and one or more client devices. It operates on a client-server model, where the client initiates requests for data, and the server responds with the requested information. This protocol is highly regarded for its simplicity, reliability and ease of implementation.

![modbus_logo](https://github.com/JBsCorner/iiot-workshop/blob/main/images/modbus_logo.png?raw=true)

### 02.01: ENABLING MODBUS TCP ON OUR PLC

Modbus supports various types of registers and operations that facilitate diverse communication needs in industrial environments. The primary types of registers include Discrete Inputs and Coils, used for reading and writing boolean values, respectively, and Input Registers and Holding Registers, designed for reading and writing numerical values. Operations can be categorized into reading, where data is retrieved from these registers, and writing, where values are sent to be stored or to modify device settings.

![modbus](https://github.com/JBsCorner/iiot-workshop/blob/main/images/modbus_tables.png?raw=true)

In our case, we decide to configure the PLC as indicated below:
* Five Coils (addresses 0 to 4) will be used to activate o deactivate individually each sensor.
* No Discrete Input will be used.
* Five Input Registries (addresses 10 to 14) will be used to read sensor values.
* One Holding Registry (address 20) will be used to set sensor sampling interval.

![modbus_plcsetup](https://github.com/JBsCorner/iiot-workshop/blob/main/images/modbus_plcsetup.jpg?raw=true)

#### 02.01.A: CONTROLLINO THROUGH MODBUS TCP

**REQUIREMENTS**

**Hardware:**
* Previously used HW.
* Ethernet cable.

**Software:**
* Previously used SW.

**STEP BY STEP**
1. Our Controllino will act as the Modbus Server. In order to prepare the Controllino for Modbus communication:
    * Install [Arduino Modbus library](https://www.arduino.cc/reference/en/libraries/arduinomodbus/) in your Arduino IDE (1.0.9 used).
    * Copy [this](https://github.com/JBsCorner/iiot-workshop/blob/main/code/controllino/controllino_modbus.ino) sketch code into Arduino IDE.
    * Upload the code into the Controllino board.
      
2. Our PC will act as the Modbus Client. First we need to connect them together:
    * Connect the Controllino to your PC or Laptop using the Ethernet cable.
    * Edit you Ethernet network settings as follows.
        * IP: 10.0.0.2
        * Subnet Mask: 255.255.255.0
        * Default Gatewat: 10.0.0.1
   * Last step is OS specific. In Windows, you may find these settings at *Control Panel > Network and Sharing Center > Ethernet > Internet Protocol Version 4 (TCP/IPv4) > Properties*.
  
3. In order to test correct connectivity between both devices:
    * From your PC/Laptop, open *cmd* utility and execute a *ping* command: `ping 10.0.0.1`.
    * From your PC/Laptop, open *cmd* utility and execute a *telnet* command: `telnet 10.0.0.1 502`.
  
#### 02.01.B: VIRTUAL PLC THROUGH MODBUS TCP

**REQUIREMENTS**

**Hardware:**
* Previously used HW.

**Software:**
* Previously used SW.

**STEP BY STEP**
1. Our Virtual PLC will act as the Modbus Server. In order to prepare the Virtual PLC for Modbus communication, install the following Node-RED modules:
    * node-red-contrib-modbus (5.28.0 used).
      
2. We will create the Modbus Virtual PLC in a different flow:
    * Create a new Node-RED flow for our Modbus Virtual PLC.  
    * Import and Deploy [this flow](https://github.com/JBsCorner/iiot-workshop/blob/main/code/node-red/nodered_modbusvirtualplc.json) into your environment.
    * You will notice the UI is exactly the same, but a new Modbus Server node is active in our flow tab.
      ![nodered_modbusvirtualplc](https://github.com/JBsCorner/iiot-workshop/blob/main/images/nodered_modbusvirtualplc.png?raw=true)
    
3. In order to test correct connectivity to Modbus TCP Server: from your PC/Laptop, open *cmd* utility and execute a *telnet* command: `telnet 10.0.0.1 502`.

### 02.02: CONNECTING AN HMI FOR PROCESS VISUALIZATION
An HMI, or Human-Machine Interface, is a platform that provides the means for users to interact with and control machines, systems, or devices. Typically, HMIs are used in industrial and manufacturing processes, allowing operators to see real-time system data, manipulate control settings, and monitor operational processes through graphical interfaces onsite. These interfaces can range from simple push-button panels to complex touchscreen displays, providing visual representations of industrial tasks with detailed monitoring of machine inputs and outputs. They are widely used across various industries, including automation, manufacturing, and utilities, to enhance user experience and system usability.

![hmi_rockwell](https://github.com/JBsCorner/iiot-workshop/blob/main/images/hmi_rockwell.jpg?raw=true)

<sub>*Source: Rockwell Automation.*</sub>

**REQUIREMENTS**

**Hardware:**
* Previously used HW.

**Software:**
* Previously used SW.
* Node-RED
  
1. We will use Node-RED to create our Modbus client and HMI. Download and install Node-RED by following the steps indicated on its official website: [https://nodered.org/](https://nodered.org/)
    * npm (used 10.4.0).
    * Node.js (used 20.11.0).
    * Node-RED (used 3.1.3).
      
2. Install the following Node-RED modules:
    * node-red-contrib-modbus (5.28.0 used).
    * node-red-dashboard (3.3.1 used).
      
3. First, we will create a simple Modbus client and test Client-Server connectivity.
    * Start Node-RED.
    * Import and Deploy [this flow](https://github.com/JBsCorner/iiot-workshop/blob/main/code/node-red/nodered_modbus_client.json) into your environment. Make sure that the Modbus server's IP address corresponds to the one used in your PLC (either 10.0.0.1 or localhost).
    * You should now be able to read PLC registries in Node RED debug tab as well as update them by clicking on the different provided Inject Nodes.
      ![nodered_modbusclient](https://github.com/JBsCorner/iiot-workshop/blob/main/images/nodered_modbusclient.png?raw=true)

4. We will now create an HMI using Node-RED dashboard capabilities:
    * Import and Deploy [this flow](https://github.com/JBsCorner/iiot-workshop/blob/main/code/node-red/modbus_hmi.json) into your environment.
      ![nodered_modbushmi](https://github.com/JBsCorner/iiot-workshop/blob/main/images/nodered_modbushmi.png?raw=true)
    * Open Node-RED UI at http://localhost:1880/ui and your HMI will load. You can check current status and interact with your industrial device from this HMI.
      ![nodered_modbushmiui](https://github.com/JBsCorner/iiot-workshop/blob/main/images/nodered_modbushmiui.png?raw=true)
      
## PHASE 03: REMOTE MONITORING
Our industrial plant is now up and running. However, we can only monitor its status or change its operating conditions locally from the HMI at the plant. In order to enable remote communication with the industrial plant, we will set-up an Edge Gatway capable of sending and receiving data to and from our Cloud IoT Platform.

In our case, we will use AWS (Amazon Web Services) Cloud Platform to build our IoT and Data Platforms. AWS is a cloud computing platform provided by Amazon that includes a mixture of infrastructure as a service (IaaS), platform as a service (PaaS), and packaged software as a service (SaaS) offerings. AWS offers over 200 fully featured services from data centers globally. AWS services include computing power, storage options, networking, and databases, designed to help businesses scale and grow by enabling applications to be more resilient, flexible, and scalable.

![aws_logo](https://github.com/JBsCorner/iiot-workshop/blob/main/images/aws_logo.png?raw=true)

Most cloud service providers, such as AWS, enable MQTT endpoints in order to connect cloud services and IoT devices. MQTT (Message Queuing Telemetry Transport) is a lightweight, publish-subscribe network protocol that transports messages between devices. Designed for the constrained environments of IoT, MQTT is ideal for connecting remote devices with a minimal network footprint, ensuring efficient and reliable communication even under limited bandwidth or high-latency conditions. It operates on top of TCP/IP and is known for its simplicity, ease of implementation, and low power usage, making it well-suited for a wide range of IoT applications, from home automation to industrial monitoring. MQTT enables devices to publish messages to a topic on a broker and allows other devices to subscribe to that topic to receive the messages, facilitating real-time, machine-to-machine communication. With its robust support for secure messaging, MQTT is a key enabler of IoT ecosystems, providing a dependable method for connecting sensors, actuators, and other IoT devices to applications and middleware.

![mqtt_logo](https://github.com/JBsCorner/iiot-workshop/blob/main/images/mqtt_logo.png?raw=true)

### 03.1: DEVICE REGISTRATION

To enable an IoT device to communicate with the AWS IoT Platform, it must undergo a registration process.

**REQUIREMENTS**

**Hardware:**
* No HW required.

**Software:**
* AWS Account.

**STEP BY STEP**
1. In order to use AWS services, we first need to log into AWS Console:
    * Your AWS Account ID and user credentials will be provided to you by your instructor.
    * Navigate to [AWS Home Page](https://aws.amazon.com/) and click on Sign In.
    * AWS Sing-in page will now load. Select the "IAM user" sign-in option and enter your Account ID and user credentials.
      ![aws_login](https://github.com/JBsCorner/iiot-workshop/blob/main/images/aws_login.png?raw=true)
    * Once in the console, select the US East (N. Virginia) - us-east-1 region. This option can typically be found at the top-right corner of the AWS Management Console.
2. As its name suggests, IoT Core is the central service of the AWS IoT suite. We can register a new IoT device from IoT Core:
    * Navigate to the IoT Core service.
      ![aws_iot_core](https://github.com/JBsCorner/iiot-workshop/blob/main/images/aws_iot_core.png?raw=true)
    * From the left pane, click on *Manage > All devices > Things*.
    * Now, click on *Create Things*, select *Create single thing*, and enter the following name for your thing: *{your user name}-thing* (i.e. jbscorner-thing).
    * Click *Next* without any further configuration and select *Skip creating a certificate at this time* to finalize your IoT device registration.
    * Your newly created thing will appear under *Manage > All devices > Things*.
3. No device can connect and exchange data with IoT Core without having been previously authorized to do so. Next, we will create a policy for this purpose:
    * From the left pane, click on *Security > Policies*.
    * Now, click on *Create Policy* and enter the following name for your policy: *{your user name}-policy* .
    * Copy [this policy](https://github.com/JBsCorner/iiot-workshop/blob/main/code/aws/aws_iotcore_thing_policy.json) statement into Policy Document JSON editor. 
    * You must replace the literals *region* and *account-id* in each ARN with those corresponding to your account.
    * Click *Next* without any further configuration to finalize your IoT Policy creation.
    * Your newly created policy will appear under *Security > Policies*.
4. Lastly, we must provide a mechanism for the device to identify itself when connecting to the platform. We will do this by creating a unique certificate that we will assign to the device.
    * From the left pane, click on *Security > Certificates*.
    * Now, click on *Add Certificate > Create Certificate*.
    * Select *Auto-generate new certificate* and *Active* as the initial status.
    * Download and save for later both Public and Private keys together with AWS Root CA.
      ![aws_iot_certificates](https://github.com/JBsCorner/iiot-workshop/blob/main/images/aws_iot_certificates.png?raw=true)
    * Your newly created certificate will appear under *Security > Certificates*.
    * Select your certificate, *Actions > Attach Policy* to link your previously created policy to your certificate.
    * Select again your certificate, *Actions > Attach to Things* to link both yout certificate and policy with your device.

### 03.2.A: NODE-RED EDGE GATEWAY

We will create a new Node-Red flow to represent the industrial Edge Gateway.

**REQUIREMENTS**

**Hardware:**
* Previously used HW.

**Software:**
* Previously used SW.

**STEP BY STEP**
1. Create a new Node-Red flow for the Edge Gateway.
2. Using MQTT Node-Red nodes and previously downloaded certificates create a new flow that connects through Modbus to the PLC and sends received measurements to AWS IoT Core.
3. AWS IoT Core endpoint can be found on the left pane under *Settings*.
4. AWS offers a MQTT web client for testing purposes under *Test > MQTT Test Client*.
      
    
      
