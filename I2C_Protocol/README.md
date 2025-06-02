# I2C Communication

**I2C (Inter-Integrated Circuit)** is a two-wire, serial communication protocol commonly used to connect microcontrollers to sensors, displays, and other peripherals.

## I2C Basics

- **Wires**:  
  - `SDA` (Serial Data Line)  
  - `SCL` (Serial Clock Line)

- **Master/Slave Protocol**:  
  - The **master** (microcontroller) initiates communication.  
  - The **slave** (sensor, peripheral, etc) responds to the master's requests.

- **Addressing**:  
  - Each slave device has a unique **7-bit address**.  
  - The master module uses this address to communicate with the device.

## How It Works

1. The master sends a **start condition**.
2. The master sends the **slave address + read/write bit**.
3. The slave **acknowledges**.
4. Data is **transmitted in 8-bit bytes**, followed by the acknowlegement.
5. The master sends a **stop condition** to stop communication.

## Benefits

- Supports multiple devices on a single bus.
- Requires only two wires.
- Well-suited for short-distance communication.

## Use Cases

- IOT (Internet of Things)
- Consumer Electronics
- Industrial Equipment
