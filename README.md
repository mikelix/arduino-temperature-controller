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

This project can be significantly enhanced by migrating to an Arduino-compatible AIoT (Artificial Intelligence of Things) platform such as open-source Sipeed Maixduino (https://wiki.sipeed.com/soft/maixpy/en/develop_kit_board/maix_duino.html), which combines an ESP32 WiFi/Bluetooth module with a Kendryte K210 AI processor. With such a platform, the basic temperature controller transforms into an intelligent system capable of learning occupancy patterns and adjusting temperature setpoints automatically, predicting temperature trends using machine learning to activate heating or cooling preemptively, recognizing voice commands for hands-free thermostat control, performing facial recognition to apply personalized temperature preferences for different users, and connecting to cloud services for remote monitoring and control via smartphone applications. The K210 processor enables edge AI computing, meaning the device can run neural network models locally without requiring constant internet connectivity. Additional sensors such as humidity, air quality, and motion detectors can feed data into AI models that optimize comfort while minimizing energy consumption. Integration with popular IoT platforms like Home Assistant, Blynk, or AWS IoT further extends capabilities to include scheduling, geofencing, energy usage analytics, and coordination with other smart home devices. This evolution from a simple relay controller to a full AIoT system demonstrates how foundational embedded systems knowledge scales into sophisticated modern applications.



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
## Installation

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/arduino-temperature-controller.git

