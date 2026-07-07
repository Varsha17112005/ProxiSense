# ProxiSense

# ProxiSense

## RSSI-Based Indoor Localization Using Bluetooth Low Energy and Edge Processing

ProxiSense is an IoT-based indoor proximity monitoring system that estimates the distance of nearby Bluetooth Low Energy (BLE) devices using RSSI (Received Signal Strength Indicator). The processed data is transmitted to ThingSpeak through the CC3200 Wi-Fi microcontroller and visualized on a real-time web dashboard.

---

## Features

- Bluetooth Low Energy (BLE) device detection
- RSSI-based distance estimation
- Zone classification (Near, Medium, Far)
- Device count monitoring
- ThingSpeak cloud integration
- Real-time IoT dashboard
- Heatmap visualization
- Live graph updates

---

## Hardware Used

- TI CC3200 LaunchPad
- Arduino Uno
- HM-10 Bluetooth (BLE) Module
- Breadboard
- Jumper Wires
- USB Power Supply

---

## Software Used

- Energia IDE
- Arduino IDE
- HTML
- CSS
- JavaScript
- ThingSpeak Cloud
- Visual Studio Code

---

## Project Architecture
```
BLE Device
↓
HM-10 Bluetooth Module
↓
Arduino Uno
↓
CC3200 LaunchPad
↓
ThingSpeak Cloud
↓
Web Dashboard
↓
Graphs + Heatmap
```
---

## Project Structure

```text
ProxiSense/
│
├── CC3200/
│   └── Energia_Code.ino
│
├── Arduino/
│   └── ArduinoIDE_Code.ino
│
├── ProxiSense.pdf
│
└── README.md
```
---
