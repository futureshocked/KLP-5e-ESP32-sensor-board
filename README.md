## Project Summary: Custom IoT PCB with ESP32-C3-02 and TP4056 Li-ion Charger

This project involves the design and development of a custom PCB for an IoT application powered by the ESP32-C3-02 SoC. The board includes integrated power management features using the TP4056 Li-ion battery charger IC, enabling efficient and safe charging of a single-cell Li-ion battery.

### Key Features

- **Microcontroller**: ESP32-C3-02 SoC for Wi-Fi and BLE connectivity.
- **Power Management**: TP4056 IC for single-cell Li-ion battery charging with thermal regulation.
- **Battery Protection**: Integrated under-voltage lockout and trickle charging.
- **Sensors and Modules**:
  - BME280 for temperature, humidity, and pressure sensing.
  - Ambient light and sound sensors.
  - Mini SD card reader for data storage.
  - Flash memory for additional storage.
- **Display**: I2C OLED for real-time data visualization.
- **Power Inputs**:
  - USB-C connector for charging and data transfer.
  - LiPo battery connector with onboard charging circuitry.
- **Indicators**: LED indicators for charge status (charging and full).

### Design Highlights

1. **Power Supply Integration**:
   - USB-C provides power for both charging and system operation.
   - TP4056 handles battery charging and protection.
   - Power supplied to the ESP32-C3-02 is regulated for stability.

2. **Modular Architecture**:
   - Supports various sensors and peripherals for IoT applications.
   - Expandable via additional I2C devices.

3. **Safe and Efficient Charging**:
   - Programmable charging current using an external resistor.
   - Automatic charge termination and battery protection.

4. **Compact and Reliable Layout**:
   - Optimized PCB traces for minimal power loss.
   - Thermal management for the TP4056 and other components.

### Applications

- IoT edge devices for environmental monitoring.
- Battery-powered data logging systems.
- Prototyping platform for ESP32-based projects.

### Repository Contents

- **Schematic and PCB Layout**: KiCad files for the board design.
- **Firmware**: Source code for the ESP32-C3-02 to interface with sensors and peripherals.
- **Documentation**:
  - Datasheets for the TP4056 and other components.
  - Assembly instructions.
  - Testing procedures.
- **License**: MIT License.

This repository is a complete resource for designing and building a robust IoT solution with integrated power management and ESP32 connectivity.
