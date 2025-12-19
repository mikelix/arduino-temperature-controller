/*
 * Arduino Temperature Controller with LM35 Sensor
 * 
 * Description:
 * A simple temperature monitoring and control system that reads temperature
 * from an LM35 sensor and controls a relay based on configurable threshold.
 * Includes hysteresis to prevent relay chattering.
 * 
 * Hardware:
 * - Arduino Uno (or compatible)
 * - LM35 Temperature Sensor connected to A0
 * - Relay Module connected to D7
 * 
 * Author: Your Name
 * Date: December 2025
 * Version: 1.0
 * License: MIT
 * 
 * GitHub: https://github.com/yourusername/arduino-temperature-controller
 */

// ============================================
// CONFIGURATION - Modify these values as needed
// ============================================

// Temperature threshold in Celsius - relay activates above this value
const float TEMP_THRESHOLD = 30.0;

// Hysteresis value to prevent relay chattering
// Relay turns OFF when temp falls below (TEMP_THRESHOLD - HYSTERESIS)
const float HYSTERESIS = 2.0;

// Pin definitions
const int LM35_PIN = A0;      // Analog pin for LM35 sensor
const int RELAY_PIN = 7;      // Digital pin for relay control

// Reading interval in milliseconds
const unsigned long READ_INTERVAL = 1000;

// Set to true if your relay module is active-LOW (most common)
// Set to false if your relay module is active-HIGH
const bool RELAY_ACTIVE_LOW = true;

// Number of samples to average for stable readings
const int NUM_SAMPLES = 10;

// Serial communication baud rate
const long SERIAL_BAUD = 9600;

// ============================================
// GLOBAL VARIABLES
// ============================================

bool relayState = false;
unsigned long previousMillis = 0;
float currentTemperature = 0.0;

// ============================================
// SETUP
// ============================================

void setup() {
  // Initialize serial communication
  Serial.begin(SERIAL_BAUD);
  
  // Configure pin modes
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LM35_PIN, INPUT);
  
  // Ensure relay is OFF at startup
  setRelay(false);
  
  // Allow sensor to stabilize
  delay(500);
  
  // Print startup message
  printHeader();
}

// ============================================
// MAIN LOOP
// ============================================

void loop() {
  unsigned long currentMillis = millis();
  
  // Check if it's time to read temperature
  if (currentMillis - previousMillis >= READ_INTERVAL) {
    previousMillis = currentMillis;
    
    // Read temperature from sensor
    currentTemperature = readTemperature();
    
    // Control relay based on temperature with hysteresis
    controlRelay(currentTemperature);
    
    // Print status to serial monitor
    printStatus(currentTemperature, relayState);
  }
}

// ============================================
// FUNCTIONS
// ============================================

/*
 * Reads temperature from LM35 sensor
 * Takes multiple samples and averages them for stability
 * 
 * LM35 outputs 10mV per degree Celsius
 * Arduino ADC: 5V / 1024 steps = 4.88mV per step
 * Temperature = (ADC_value * 5000 / 1024) / 10 = ADC_value * 0.4883
 * 
 * Returns: Temperature in Celsius as float
 */
float readTemperature() {
  long total = 0;
  
  // Take multiple samples
  for (int i = 0; i < NUM_SAMPLES; i++) {
    total += analogRead(LM35_PIN);
    delay(10);
  }
  
  // Calculate average
  float average = (float)total / NUM_SAMPLES;
  
  // Convert to temperature in Celsius
  // Using Arduino's 5V reference: (reading * 5000mV / 1024) / 10mV per degree
  float temperatureC = (average * 500.0) / 1024.0;
  
  return temperatureC;
}

/*
 * Controls relay based on temperature with hysteresis
 * 
 * Relay turns ON when temperature exceeds TEMP_THRESHOLD
 * Relay turns OFF when temperature falls below (TEMP_THRESHOLD - HYSTERESIS)
 * 
 * Parameters:
 *   temperature - Current temperature reading in Celsius
 */
void controlRelay(float temperature) {
  if (!relayState && temperature >= TEMP_THRESHOLD) {
    // Temperature exceeded threshold, turn relay ON
    setRelay(true);
  } 
  else if (relayState && temperature < (TEMP_THRESHOLD - HYSTERESIS)) {
    // Temperature fell below threshold minus hysteresis, turn relay OFF
    setRelay(false);
  }
  // If temperature is between (THRESHOLD - HYSTERESIS) and THRESHOLD,
  // maintain current relay state (hysteresis zone)
}

/*
 * Sets relay to specified state
 * Handles both active-HIGH and active-LOW relay modules
 * 
 * Parameters:
 *   state - true to activate relay, false to deactivate
 */
void setRelay(bool state) {
  relayState = state;
  
  if (RELAY_ACTIVE_LOW) {
    // Active-LOW: LOW turns relay ON, HIGH turns relay OFF
    digitalWrite(RELAY_PIN, state ? LOW : HIGH);
  } else {
    // Active-HIGH: HIGH turns relay ON, LOW turns relay OFF
    digitalWrite(RELAY_PIN, state ? HIGH : LOW);
  }
}

/*
 * Prints startup header to serial monitor
 */
void printHeader() {
  Serial.println();
  Serial.println(F("========================================"));
  Serial.println(F("  Arduino Temperature Controller v1.0"));
  Serial.println(F("========================================"));
  Serial.println();
  Serial.print(F("Temperature Threshold: "));
  Serial.print(TEMP_THRESHOLD, 1);
  Serial.println(F(" C"));
  Serial.print(F("Hysteresis: "));
  Serial.print(HYSTERESIS, 1);
  Serial.println(F(" C"));
  Serial.print(F("Relay turns OFF below: "));
  Serial.print(TEMP_THRESHOLD - HYSTERESIS, 1);
  Serial.println(F(" C"));
  Serial.print(F("Relay Type: "));
  Serial.println(RELAY_ACTIVE_LOW ? F("Active-LOW") : F("Active-HIGH"));
  Serial.println();
  Serial.println(F("----------------------------------------"));
  Serial.println(F("  Temp (C)  |  Relay  |  Status"));
  Serial.println(F("----------------------------------------"));
}

/*
 * Prints current status to serial monitor
 * 
 * Parameters:
 *   temperature - Current temperature reading
 *   relay - Current relay state
 */
void printStatus(float temperature, bool relay) {
  // Print temperature with formatting
  Serial.print(F("   "));
  if (temperature < 10.0) Serial.print(F(" "));
  Serial.print(temperature, 1);
  Serial.print(F("     |   "));
  
  // Print relay state
  Serial.print(relay ? F("ON ") : F("OFF"));
  Serial.print(F("   |  "));
  
  // Print descriptive status
  if (temperature >= TEMP_THRESHOLD) {
    Serial.println(F("Above threshold - Cooling"));
  } 
  else if (temperature >= (TEMP_THRESHOLD - HYSTERESIS)) {
    Serial.println(F("Hysteresis zone - Holding"));
  } 
  else {
    Serial.println(F("Below threshold - Idle"));
  }
}

// ============================================
// OPTIONAL: Additional utility functions
// ============================================

/*
 * Converts Celsius to Fahrenheit
 * 
 * Parameters:
 *   celsius - Temperature in Celsius
 * Returns: Temperature in Fahrenheit
 */
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}

/*
 * Gets the current relay state
 * 
 * Returns: true if relay is active, false otherwise
 */
bool getRelayState() {
  return relayState;
}

/*
 * Gets the last temperature reading
 * 
 * Returns: Last recorded temperature in Celsius
 */
float getLastTemperature() {
  return currentTemperature;
}