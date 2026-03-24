# Ultrasonic Radar ESP32 📡

A smart proximity alert system built with an ESP32 microcontroller and an HC-SR04 ultrasonic sensor. This project acts like a vehicle parking radar, dynamically changing the blink rate of a warning LED based on the distance to the nearest object.

## Features 🚀
* **Real-time distance measurement** using ultrasonic sound waves.
* **Adaptive Alert System:** The LED blink rate increases as objects get closer.
  * `80cm - 100cm`: Slow blink (2Hz)
  * `50cm - 80cm`: Medium blink (4Hz)
  * `20cm - 50cm`: Fast blink (8Hz)
  * `< 20cm`: Solid light (Danger / Stop)
* **Serial Monitor output** for easy debugging and real-time distance tracking.

## Hardware Required 🛠️
* ESP32 Development Board
* HC-SR04 Ultrasonic Sensor
* 1x LED (Red)
* 1x Resistor (220Ω - 1kΩ)
* Breadboard and Jumper Wires

## Wiring Guide 🔌
| Component | ESP32 Pin |
| :--- | :--- |
| HC-SR04 VCC | VIN / 5V |
| HC-SR04 GND | GND |
| HC-SR04 Trig | GPIO 5 |
| HC-SR04 Echo | GPIO 18 |
| LED Anode (+) | GPIO 13 (via resistor) |
| LED Cathode (-) | GND |

## How to Run 💻
1. Clone this repository or download the `ultrasonic_radar.ino` file.
2. Open the file in the Arduino IDE.
3. Select your ESP32 board and the correct COM port.
4. Click **Upload** and open the **Serial Monitor** (set to 115200 baud) to view real-time distance data.

---
*Developed as a hands-on project for embedded systems and firmware development.*
