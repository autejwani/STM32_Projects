#include <Wire.h>  // Include I2C library for communication with the MPU-6050

// Define the I2C address of the MPU-6050 sensor
const int MPU_ADDR = 0x68;

// Variables to store raw and converted temperature values
int16_t raw_temp;
float temperature_celsius;
float temperature_fahrenheit;

void setup() {
  Serial.begin(9600);    // Start serial communication at 9600 baud for debugging
  Wire.begin();          // Initialize I2C communication (STM32: SDA = PB9, SCL = PB8)

  // Wake up the MPU-6050 by writing 0 to the power management register (0x6B)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);      // Address of the power management register
  Wire.write(0);         // Set register value to 0 to wake the sensor
  Wire.endTransmission(true);
}

void loop() {
  // Request the temperature data starting from TEMP_OUT_H (0x41)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x41);      // Temperature high byte register
  Wire.endTransmission(false); // Send repeated start for read
  Wire.requestFrom(MPU_ADDR, 2, true); // Request 2 bytes: TEMP_OUT_H and TEMP_OUT_L

  // Wait until data is available, then read and process it
  if (Wire.available() >= 2) {
    // Combine high and low bytes into a signed 16-bit integer
    raw_temp = Wire.read() << 8 | Wire.read();

    // Convert raw temperature to degrees Celsius using formula from datasheet
    temperature_celsius = (raw_temp / 340.0) + 36.53;

    // Convert Celsius to Fahrenheit
    temperature_fahrenheit = (temperature_celsius * 9.0 / 5.0) + 32.0;

    // Print temperature in Fahrenheit to Serial Monitor
    Serial.println("Temperature: ");
    Serial.print(temperature_fahrenheit);
    Serial.println(" F");
  }

  delay(1000); // Wait 1 second before next reading
}
