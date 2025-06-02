# I2C Temperature Reader (STM32 Nucleo-F411RE + GY-521 Module)

This project reads temperature data from a **GY-521** module using I2C communication on an **STM32 Nucleo-F411RE**.

## Requirements

- STM32 Nucleo-F411RE board  
- GY-521 (Temperature, Gyroscope, Accelerometer) module  
- Jumper wires  
- Arduino IDE

## Wiring
Pin Diagram can be found here: https://www.oreilly.com/library/view/arm-based-microcontroller-projects/9780081029701/B978008102969509995X.xhtml

| GY-521 | STM32 Nucleo-F411RE |
|--------|---------------------|
| VCC    | 5V                  |
| GND    | GND                 |
| SDA    | PB9                 |
| SCL    | PB8                 |

## How It Works

- Initializes I2C on STM32 (PB9 = SDA, PB8 = SCL).
- Wakes up the MPU-6050 by writing `0x00` to register `0x6B` (PWR_MGMT_1).
- Requests 2 bytes from temperature registers `0x41` (TEMP_OUT_H) and `0x42` (TEMP_OUT_L).
- Combines the two bytes into a 16-bit signed integer `raw_temp`.
- Converts the raw value to Celsius using: `(raw_temp / 340.0) + 36.53`
- Converts the Celsius measurement to Fahrenheit using: `(temperature_celsius * 9.0 / 5.0) + 32.0`

