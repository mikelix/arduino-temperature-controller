# Arduino Temperature Controller with LM35 Sensor

A simple temperature monitoring and control system using Arduino Uno, LM35 temperature sensor, and a relay module. The system reads ambient temperature and activates a relay when the temperature exceeds a configurable threshold, making it suitable for cooling fan control, heater control, or other temperature-dependent applications.

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

