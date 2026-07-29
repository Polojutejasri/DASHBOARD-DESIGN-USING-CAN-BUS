## 🚗 DASHBOARD DESIGN USING CAN BUS
## 📖 Table of Contents

📌 Project Overview

🎯 Objectives

🖼️ Block Diagram

🏗️ System Architecture

⚙️ Hardware Requirements

💻 Software Requirements

📂 Repository Structure

📨 CAN Message IDs

🚀 Features

🖥️ LCD Output Gallery

▶️ Build Instructions

📈 Future Enhancements

👩‍💻 Author

## 📌 Project Overview

The **Dashboard Design Using CAN Bus** project is an Embedded Systems application developed using the **LPC2129 ARM7 microcontroller** and the **Controller Area Network (CAN) protocol**. The project simulates a vehicle dashboard by displaying real-time engine temperature, fuel level, and left/right turn indicator status.

The system is implemented using three independent CAN nodes that communicate with each other over the CAN bus:

- **Main Node** – Displays engine temperature, fuel percentage, and indicator status on a 20x4 LCD while coordinating communication with the other nodes.
- **Fuel Gauge Node** – Reads the fuel sensor value using the on-chip ADC and transmits the fuel percentage to the Main Node through the CAN network.
- **Indicator Node** – Receives commands from the Main Node and controls the left and right turn indicators using LEDs.
## 🎯 Objectives

- Develop a CAN Bus-based automotive dashboard system.
- Display engine temperature and fuel level on the LCD.
- Control left and right turn indicators using CAN communication.
- Enable communication between multiple LPC2129 nodes.
- Interface sensors using Embedded C programming.
- Learn CAN protocol and ARM7 microcontroller programming.
- Build a reliable and real-time embedded system for automotive applications.
## 🖼️ Block Diagram

<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/d2f06b4c-257a-4e35-bd06-e1f06e4cc58a" />

## 🏗️ System Architecture

The system is designed using three LPC2129-based nodes connected through a CAN Bus.

### 🔹 Main Node
- Reads engine temperature from the DS18B20 sensor.
- Receives fuel percentage from the Fuel Gauge Node.
- Sends indicator commands to the Indicator Node.
- Displays all information on the 20x4 LCD.

### 🔹 Fuel Gauge Node
- Reads the fuel sensor value using the on-chip ADC.
- Converts the value into fuel percentage.
- Transmits the fuel data to the Main Node through CAN.

### 🔹 Indicator Node
- Receives CAN messages from the Main Node.
- Controls the Left and Right indicator LEDs based on the received data.

### 🔹 CAN Bus
- Provides reliable communication between all three nodes using the MCP2551 CAN transceiver.
- Uses CANH and CANL lines with **120 Ω termination resistors** at both ends of the bus for stable communication.
## ⚙️ Hardware Requirements

| Hardware | Quantity | Purpose |
|----------|:--------:|---------|
| LPC2129 | 3 | ARM7 Microcontroller (Main, Fuel, Indicator Nodes) |
| MCP2551 | 3 | CAN Transceiver|
| DS18B20 Temperature Sensor | 1 | Engine Temperature Measurement |
| Fuel Gauge Sensor | 1 | Fuel Level Measurement |
| 20X4 LCD | 1 | Display Engine Temperature, Fuel Percentage, and Indicator Status |
| LEDs | 8 | Left and Right Indicators |
| Push Buttons | 2 | Left and Right Indicator Control |
| USB to UART Converter | 1 | Program Download and Serial Communication |
| CAN Bus | 1 | Communication Between Nodes |
| Power Supply (5V) | 1 | Power Source |
## 💻 Software Requirements

| Software | Purpose |
|----------|---------|
| Keil µVision | Development |
| Embedded C | Programming |
| Flash Magic | Programming LPC2129 |
| Proteus | Simulation |
## 🚀 Features

- Real-time engine temperature monitoring using the DS18B20 sensor.
- Fuel level monitoring using the on-chip ADC.
- CAN Bus communication between three LPC2129 nodes.
- Left and Right indicator control through CAN messages.
- Real-time display of engine temperature, fuel percentage, and indicator status on a 16×2 LCD.
- Reliable and high-speed data transmission using the MCP2551 CAN transceiver.
- Modular design with separate Main, Indicator, and Fuel Gauge nodes.
- Developed using Embedded C on the ARM7 LPC2129 microcontroller.

  ## 🖥️ Project Output

The dashboard successfully displays real-time vehicle information received through the CAN Bus communication network.

### Dashboard Display

- Engine Temperature Monitoring
- Fuel Percentage Display
- Left Indicator ON
- Right Indicator ON
<img width="1774" height="887" alt="image" src="https://github.com/user-attachments/assets/b70431d0-728f-46bb-8253-0ea43249f628" />

## ▶️ Build Instructions

1. Open the project in **Keil µVision**.
2. Build the project.
3. Flash the LPC2129 using **Flash Magic**.
4. Connect all CAN nodes.
5. Power ON the system.
6. Observe the dashboard output on the LCD.
## 📈 Future Enhancements

- Add speed monitoring.
- Display warning messages.
- Support more CAN nodes.
- Improve the dashboard interface.
## 👨‍💻 Author

**Teja Sri Poloju**

Embedded Systems | Embedded C | ARM7 | CAN | LPC2129
