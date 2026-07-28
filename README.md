# Dashboard Design Using CAN Bus

## Project Overview

The **Dashboard Design Using CAN Bus** is an Embedded Systems project developed using the **LPC2129 ARM7 Microcontroller** and the **Controller Area Network (CAN) protocol**. The project demonstrates communication between multiple embedded nodes to monitor and display vehicle parameters such as engine temperature, fuel level, and indicator status in real time.

This project was developed as part of my Embedded Systems learning to gain practical experience in CAN communication, Embedded C programming, and ARM7 microcontroller programming.

## Features

- Engine Temperature Monitoring
- Fuel Level Monitoring
- Left and Right Indicator Monitoring
- CAN Transmitter and Receiver Communication
- Real-Time LCD Display
- Modular Node-Based Design
- Embedded C Implementation

## Hardware Used

- LPC2129 ARM7 Microcontroller
- CAN Transceiver(MCP2551)
- LEDS
- LCD Display
- Switches
- DS18B20 Temperature Sensor
- Fuel Guage
- USB to UART Converter 
- Power Supply
## Software Used

- Embedded C
- Keil uVision
- Flash Magic
## Repository Structure
## Repository Structure

DASHBOARD-DESIGN-USING-CAN-BUS/
│
├── CAN_Communication/
│
├── Images/
│
├── Node_1_Engine_Temperature/
│
├── Node_2_Indicator_System/
│
├── Node_3_Fuel_Gauge/
│
└── README.md


## Project Modules

### Node 1 – Engine Temperature
Reads and processes engine temperature data, then transmits it over the CAN Bus.

### Node 2 – Indicator System
Monitors and transmits the left and right indicator status through CAN communication.

### Node 3 – Fuel Gauge
Reads the fuel level and transmits the data over the CAN Bus.

### CAN Communication
Implements CAN Transmitter (TX) and CAN Receiver (RX) modules for reliable communication between the nodes.

---

## Project Workflow

1. Initialize the LPC2129 microcontroller.
2. Read vehicle parameter values.
3. Transmit data using the CAN protocol.
4. Receive CAN messages.
5. Process the received data.
6. Display the information on the LCD.

## Folder Description

- **Node_1_Engine_Temperature** – Engine temperature monitoring module.
- **Node_2_Indicator_System** – Vehicle indicator monitoring module.
- **Node_3_Fuel_Gauge** – Fuel level monitoring module.
- **CAN_Communication** – CAN transmitter and receiver implementation.
- **Images** – Hardware setup, circuit diagrams, LCD outputs, and project photos.



## Learning Outcomes

Through this project, I gained practical experience in:

- Embedded C Programming
- ARM7 LPC2129 Programming
- CAN Bus Communication
- Register-Level Programming
- Keil uVision Project Development
- Embedded System Debugging

## Future Enhancements

- Vehicle Speed Display
- RPM Monitoring
- Battery Voltage Monitoring
- Oil Pressure Monitoring
- Data Logging
- Wireless Monitoring


## Project Images

Project images, hardware setup, LCD outputs, and circuit diagrams are available in the **Images** folder.

## Author

**P. Teja Sri**

Electronics and Communication Engineering Graduate

Embedded Systems Trainee
