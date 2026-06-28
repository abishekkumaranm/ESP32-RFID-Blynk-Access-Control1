# ESP32 RFID Access Control with Blynk

## Project Overview

This project implements an RFID-based access control system using an ESP32 and RC522 RFID reader. Authorized RFID tags are granted access, while unauthorized tags are denied. The access status and scanned UID are displayed on the Blynk IoT dashboard.

## Hardware Used

- ESP32 Development Board
- RC522 RFID Reader
- RFID Card
- RFID Keychain Tag
- Jumper Wires
- USB Cable

## Software

- Arduino IDE
- ESP32 Board Package
- MFRC522 Library
- Blynk IoT

## Connections

| RC522 | ESP32 |
|--------|-------|
| SDA | GPIO5 |
| SCK | GPIO18 |
| MOSI | GPIO23 |
| MISO | GPIO19 |
| RST | GPIO22 |
| 3.3V | 3.3V |
| GND | GND |

## Features

- RFID card detection
- Authorized user verification
- Access Allow/Deny logic
- UID display
- Blynk IoT integration
- Real-time monitoring

## Future Improvements

- Servo-based smart door lock
- OLED display
- Attendance logging
- Google Sheets integration
- Firebase database
