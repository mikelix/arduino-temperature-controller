# Arduino Temperature Controller with LM35 Sensor

A simple temperature monitoring and control system using Arduino Uno, LM35 temperature sensor, and a relay module. The system reads ambient temperature and activates a relay when the temperature exceeds a configurable threshold, making it suitable for cooling fan control, heater control, or other temperature-dependent applications.

## About the LM35 Temperature Sensor
The LM35 is a precision integrated-circuit temperature sensor (PTAT; proportional to absolute temperature) manufactured by Texas Instruments. It provides an analog voltage output that is linearly proportional to temperature, with a scale factor of 10 millivolts per degree Celsius. This means at 25°C, the sensor outputs 250mV, and at 100°C, it outputs 1V. The LM35 operates over a temperature range of -55°C to 150°C, requires no external calibration, and draws only about 60 microamps from its power supply, making it ideal for battery-powered applications. Unlike thermistors, the LM35 produces a linear output, which simplifies the code needed to convert its readings to actual temperature values. The sensor has three pins: VCC (4V to 30V supply), GND, and OUT (analog voltage output), making it extremely easy to interface with Arduino's analog input pins.

## About the Relay Module
A relay is an electrically operated switch that allows a low-power signal from the Arduino (5V, a few milliamps) to control a much higher power circuit, such as a 120V/240V AC appliance or a high-current DC load. Arduino-compatible relay modules typically include the relay itself along with a driver circuit featuring an optocoupler for electrical isolation and a transistor to provide sufficient current to energize the relay coil, since Arduino pins cannot supply enough current directly. Most modules have three output terminals: COM (common), NO (normally open), and NC (normally closed). When the relay is not energized, COM is connected to NC; when energized, COM switches to NO. Many relay modules are active-LOW, meaning they activate when the Arduino pin is set to LOW rather than HIGH, though some modules are active-HIGH. Common specifications for single-channel modules include 5V coil voltage, 10A switching capacity at 250VAC or 30VDC, and trigger current of 15-20mA. These modules make it safe and simple to control fans, heaters, lights, pumps, or other devices based on sensor readings from your Arduino.





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

