# Arduino Temperature Controller with LM35 Sensor

A simple temperature monitoring and control system using Arduino Uno, LM35 temperature sensor, and a relay module. The system reads ambient temperature and activates a relay when the temperature exceeds a configurable threshold, making it suitable for cooling fan control, heater control, or other temperature-dependent applications.

## About the LM35 Temperature Sensor
The LM35 is a precision integrated-circuit temperature sensor (PTAT; proportional to absolute temperature) manufactured by Texas Instruments (https://www.ti.com/product/LM35). It provides an analog voltage output that is linearly proportional to temperature, with a scale factor of 10 millivolts per degree Celsius. This means at 25°C, the sensor outputs 250mV, and at 100°C, it outputs 1V. The LM35 operates over a temperature range of -55°C to 150°C, requires no external calibration, and draws only about 60 microamps from its power supply, making it ideal for battery-powered applications. Unlike thermistors, the LM35 produces a linear output, which simplifies the code needed to convert its readings to actual temperature values. The sensor has three pins: VCC (4V to 30V supply), GND, and OUT (analog voltage output), making it extremely easy to interface with Arduino's analog input pins.

## About the Arduino Uno
The Arduino Uno is an open-source microcontroller board based on the ATmega328P chip, developed by Arduino.cc and widely regarded as the most popular board for beginners and prototyping (https://en.wikipedia.org/wiki/Arduino_Uno). It features 14 digital input/output pins (of which 6 can provide PWM output), 6 analog input pins, a 16 MHz ceramic resonator, a USB connection for programming and power, a power jack, an ICSP header, and a reset button. The board operates at 5V logic levels, making it directly compatible with many sensors and modules including the LM35 and standard relay modules used in this project. Each analog pin provides 10-bit resolution, meaning it can read 1024 different voltage levels between 0V and 5V, which translates to approximately 0.49°C resolution when reading the LM35 sensor. The ATmega328P offers 32KB of flash memory for storing your program, 2KB of SRAM for variables, and 1KB of EEPROM for persistent data storage. Programming is done through the Arduino IDE using a simplified C/C++ language, and the extensive library ecosystem makes it easy to add functionality for displays, communication modules, and various sensors. While this project uses the Arduino Uno, the code is compatible with other Arduino boards such as the Nano, Mega, and Leonardo with minimal or no modifications.

## About the Relay Module
A relay is an electrically operated switch that allows a low-power signal from the Arduino (5V, a few milliamps) to control a much higher power circuit, such as a 120V/240V AC appliance or a high-current DC load. Arduino-compatible relay modules typically include the relay itself along with a driver circuit featuring an optocoupler for electrical isolation and a transistor to provide sufficient current to energize the relay coil, since Arduino pins cannot supply enough current directly. Most modules have three output terminals: COM (common), NO (normally open), and NC (normally closed). When the relay is not energized, COM is connected to NC; when energized, COM switches to NO. Many relay modules are active-LOW, meaning they activate when the Arduino pin is set to LOW rather than HIGH, though some modules are active-HIGH. Common specifications for single-channel modules include 5V coil voltage, 10A switching capacity at 250VAC or 30VDC, and trigger current of 15-20mA. These modules make it safe and simple to control fans, heaters, lights, pumps, or other devices based on sensor readings from your Arduino.

## Applications and Future Extensions

### Practical Applications

This Arduino temperature controller project serves as a foundation for numerous real-world applications. In smart home environments, it can automate cooling fans, portable heaters, or ventilation systems to maintain comfortable room temperatures without manual intervention. For HVAC systems, the project can function as a simple thermostat or supplement existing climate control by managing auxiliary heating or cooling equipment. In agricultural settings, it proves valuable for greenhouse temperature regulation, livestock barn ventilation, or protecting plants from frost by activating heaters when temperatures drop. The system also suits industrial monitoring applications such as server room cooling, equipment overheating protection, or process temperature control in manufacturing. Hobbyists and makers can adapt this project for aquarium heater control, 3D printer enclosure heating, fermentation temperature management for homebrewing, or incubator temperature regulation.

### Extension to AIoT Temperature Control System

This project can be significantly enhanced by migrating to an Arduino-compatible AIoT (Artificial Intelligence of Things) platform such as open-source Sipeed Maixduino (https://wiki.sipeed.com/soft/maixpy/en/develop_kit_board/maix_duino.html), which combines an ESP32 WiFi/Bluetooth module with a Kendryte K210 AI processor (https://wiki.sipeed.com/soft/maixpy/en/develop_kit_board/core_k210.html). With such a platform, the basic temperature controller transforms into an intelligent system capable of learning occupancy patterns and adjusting temperature setpoints automatically, predicting temperature trends using machine learning to activate heating or cooling preemptively, recognizing voice commands for hands-free thermostat control, performing facial recognition to apply personalized temperature preferences for different users, and connecting to cloud services for remote monitoring and control via smartphone applications. The K210 processor enables edge AI computing, meaning the device can run neural network models locally without requiring constant internet connectivity. Additional sensors such as humidity, air quality, and motion detectors can feed data into AI models that optimize comfort while minimizing energy consumption. Integration with popular IoT platforms like Home Assistant, Blynk, or AWS IoT further extends capabilities to include scheduling, geofencing, energy usage analytics, and coordination with other smart home devices. This evolution from a simple relay controller to a full AIoT system demonstrates how foundational embedded systems knowledge scales into sophisticated modern applications.

## Upgrading to AIoT: Sipeed Maixduino Temperature Control System

### Why Upgrade from Arduino Uno to Sipeed Maixduino?

The Arduino Uno is excellent for basic temperature control, but it lacks connectivity, processing power, and intelligence capabilities. The Sipeed Maixduino addresses all these limitations by combining three powerful components on a single Arduino-form-factor board: the Kendryte K210 dual-core 64-bit RISC-V AI processor running at 400MHz with dedicated neural network accelerator (KPU), an ESP32 module providing WiFi and Bluetooth connectivity, and Arduino-compatible headers allowing you to reuse existing sensors and modules including the LM35 and relay from this project.

### About the Sipeed Maixduino

The Sipeed Maixduino is an AIoT development board designed for edge AI applications. The Kendryte K210 processor features 8MB of on-chip SRAM, a Neural Network Processing Unit capable of 0.5 TOPS (trillion operations per second), hardware-accelerated FFT for audio processing, and dedicated image processing units. The integrated ESP32 handles all wireless communication, freeing the K210 to focus on AI inference tasks. The board supports MicroPython and Arduino IDE programming, runs neural network models in formats like TensorFlow Lite and ONNX, and can perform complex AI tasks entirely at the edge without cloud dependency. At approximately $20-30 USD, it offers exceptional value for AIoT prototyping.

### High-Value AIoT Features for Temperature Control

**1. Predictive Temperature Management**

Unlike the reactive Arduino system that only responds after temperature thresholds are crossed, the Maixduino can run time-series prediction models trained on historical temperature data. By analyzing patterns from past hours or days, the system anticipates temperature changes before they occur. For example, if the model detects that room temperature typically rises at 2:00 PM due to afternoon sun exposure, it can activate cooling preemptively at 1:45 PM, maintaining more stable temperatures and reducing energy consumption from rapid heating and cooling cycles. This predictive capability transforms the system from a simple thermostat into an intelligent climate management solution.

**2. Multi-Sensor Fusion with AI Analysis**

The K210 processor can simultaneously analyze data from multiple sensors including temperature, humidity, air quality, ambient light, barometric pressure, and occupancy detectors. Machine learning models running on the KPU correlate these inputs to make smarter decisions. For instance, the system might learn that high humidity combined with moderate temperature feels uncomfortably warm, triggering cooling at a lower threshold than temperature alone would indicate. This holistic environmental analysis creates genuinely comfortable conditions rather than simply hitting a temperature number.

**3. Occupancy Detection and Facial Recognition**

Using an inexpensive camera module connected to the Maixduino, the K210 can run real-time person detection and facial recognition models. The system learns which family members prefer which temperature settings and automatically adjusts when specific individuals enter a room. When no occupancy is detected for a configurable period, the system enters energy-saving mode with relaxed temperature thresholds. This personalization and automatic energy management can reduce heating and cooling costs by 15-30% compared to fixed-schedule thermostats while improving comfort for each household member.

**4. Voice Control Integration**

The K210 includes hardware audio processing capabilities and can run keyword spotting and simple speech recognition models. Users can adjust temperature settings, request current conditions, or switch operating modes using voice commands without requiring cloud connectivity or smart speakers. Commands like "make it cooler" or "set temperature to 24 degrees" can be processed entirely on-device with sub-second response times and complete privacy since audio never leaves the device.

**5. Anomaly Detection and Predictive Maintenance**

AI models can establish baseline patterns for normal system operation including typical temperature ranges, heating and cooling cycle durations, and sensor reading consistency. When the system detects anomalies such as a relay cycling too frequently, temperature readings drifting unexpectedly, or cooling taking longer than usual to reach setpoint, it can alert users to potential problems before complete failure occurs. This predictive maintenance capability is particularly valuable in commercial and industrial applications where equipment downtime carries significant costs.

**6. Cloud Connectivity and Remote Management**

The integrated ESP32 enables secure WiFi connectivity to cloud platforms including AWS IoT, Google Cloud IoT, Microsoft Azure IoT, and open-source alternatives like Home Assistant and ThingsBoard. Users can monitor temperature history, adjust settings, receive alerts, and analyze energy consumption patterns from anywhere using smartphone applications or web dashboards. The system can also receive over-the-air firmware updates, weather forecast data for enhanced predictive control, and dynamic electricity pricing information to optimize heating and cooling during off-peak hours.

**7. Energy Optimization with Machine Learning**

By combining occupancy patterns, weather forecasts, electricity pricing data, and learned thermal characteristics of the building, the Maixduino can optimize energy consumption while maintaining comfort. The system learns how quickly each room heats or cools, how external temperature and sunlight affect indoor conditions, and when occupants typically arrive home. This enables strategies like pre-cooling during cheap afternoon rates before expensive evening peak pricing, or allowing temperature to drift slightly during unoccupied hours while ensuring comfort is restored before occupants return.

**8. Edge AI Advantages**

Running AI inference directly on the Maixduino rather than sending data to cloud servers provides several critical advantages. Response times are measured in milliseconds rather than seconds, ensuring immediate reaction to temperature changes. The system continues functioning during internet outages. Privacy-sensitive data like facial recognition templates and voice recordings never leave the premises. Operating costs remain low since there are no cloud computing fees. These edge computing benefits make the Maixduino solution suitable for privacy-conscious consumers, remote locations with unreliable connectivity, and cost-sensitive commercial deployments.

### Hardware Migration Path

Upgrading from Arduino Uno to Sipeed Maixduino requires minimal hardware changes since the Maixduino maintains Arduino-compatible headers. The LM35 sensor connects identically to an analog input pin, and the relay module connects to a digital output pin exactly as before. Additional components for the enhanced AIoT system might include an OV2640 camera module for occupancy detection and facial recognition, an I2S microphone module for voice control, additional environmental sensors such as DHT22 for humidity and MQ-135 for air quality, an SSD1306 OLED display for local status information, and an optional SD card for data logging and model storage.

### Software Development Options

The Maixduino supports multiple programming environments to suit different skill levels and requirements. MaixPy provides a MicroPython implementation with AI libraries allowing rapid prototyping using familiar Python syntax. The Arduino IDE with Maixduino board support enables C/C++ programming for those comfortable with Arduino development. PlatformIO offers professional embedded development with advanced debugging capabilities. For AI model development, the K210 supports models trained using TensorFlow, Keras, or PyTorch and converted using tools like NNCase for deployment on the KPU neural network accelerator.

### Commercial and Industrial Value

The AIoT temperature control system based on Maixduino creates substantial commercial value across multiple market segments. Smart home manufacturers can differentiate products with genuine AI capabilities rather than simple automation. Building management companies can reduce energy costs while improving occupant comfort and satisfaction. Agricultural operations can optimize greenhouse conditions for crop yield while minimizing heating and cooling expenses. Industrial facilities can implement predictive maintenance for critical temperature-controlled processes. Healthcare facilities can ensure precise environmental control for patient comfort and equipment requirements. Data centers can implement intelligent cooling that adapts to computational load patterns. The combination of low hardware cost, edge AI capability, and wireless connectivity positions this platform competitively against solutions costing five to ten times more.

### Conclusion

While the Arduino Uno provides an excellent foundation for learning temperature control concepts, the Sipeed Maixduino transforms a basic thermostat into an intelligent, connected, and adaptive climate management system. The addition of machine learning, wireless connectivity, voice control, and computer vision capabilities creates a solution that genuinely understands its environment and users rather than simply reacting to threshold crossings. This progression from Arduino to AIoT demonstrates the evolution from embedded systems to intelligent edge devices and prepares developers for the next generation of smart home and industrial IoT applications.


## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Wiring Diagram](#wiring-diagram)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Features

- Real-time temperature monitoring using LM35 analog sensor
- Automatic relay control based on temperature threshold
- Hysteresis to prevent relay chattering
- Serial monitor output for debugging and monitoring
- Configurable temperature setpoint and hysteresis values

## Hardware Requirements

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno | 1 | Or compatible board (Nano, Mega, etc.) |
| LM35 Temperature Sensor | 1 | Analog output, 10mV/°C |
| 5V Relay Module | 1 | Single channel, optocoupler isolated recommended |
| Jumper Wires | Several | Male-to-male and male-to-female |
| Breadboard | 1 | Optional, for prototyping |
| 5V Power Supply | 1 | Or USB power via Arduino |

## Wiring Diagram

### LM35 Sensor Connections

| LM35 Pin | Arduino Pin |
|----------|-------------|
| VCC | 5V |
| GND | GND |
| OUT | A0 |

### Relay Module Connections

| Relay Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| IN (Signal)| D7        |
+-----+
                | USB |
           +----+-----+----+
           |    Arduino    |
           |      Uno      |
LM35       |               |       Relay Module
+-----+    | D7 +-------+ IN
| OUT +-----+ A0 | |
| VCC +-----+ 5V 5V +-------+ VCC
| GND +-----+ GND GND +-------+ GND
+-----+ | | +-------+
+---------------+ | COM +--- To Load
| NO +--- To Load
+-------+

The code includes several practical features worth noting. The averaging of multiple sensor readings helps reduce noise and provides more stable temperature values. The hysteresis implementation prevents the relay from rapidly switching on and off when the temperature hovers around the threshold, which would cause that annoying clicking sound and reduce relay lifespan. I also included support for both active-LOW and active-HIGH relay modules since different manufacturers use different logic levels.

The F() macro wraps the string literals to store them in flash memory instead of RAM, which is helpful on memory-constrained Arduino boards.
When you open the Serial Monitor at 9600 baud, you'll see output like this:

========================================
  Arduino Temperature Controller v1.0
========================================

Temperature Threshold: 30.0 C
Hysteresis: 2.0 C
Relay turns OFF below: 28.0 C
Relay Type: Active-LOW

----------------------------------------
  Temp (C)  |  Relay  |  Status
----------------------------------------
   24.5     |   OFF   |  Below threshold - Idle
   26.2     |   OFF   |  Below threshold - Idle
   30.3     |   ON    |  Above threshold - Cooling
   29.1     |   ON    |  Hysteresis zone - Holding
   27.5     |   OFF   |  Below threshold - Idle 

## Installation

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/arduino-temperature-controller.git

