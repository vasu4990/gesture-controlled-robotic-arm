# Receiver Wiring Guide — Robotic Arm

## Overview

The arm receiver listens for incoming commands from the glove via **nRF24L01**, then drives four **MG996R servos** through a **PCA9685 PWM driver**, all coordinated by an **Arduino Uno**.

---

## Components

| Component | Qty | Notes |
|---|---|---|
| Arduino Uno | 1 | ATmega328P, 5V logic |
| PCA9685 PWM driver | 1 | 16-ch servo driver, I2C, 5V tolerant |
| nRF24L01 module | 1 | 2.4GHz wireless, SPI |
| MG996R servo | 4 | Base, Shoulder, Elbow, Gripper |
| 5V 3A power supply | 1 | **Dedicated** servo power (NOT Arduino 5V) |
| 470µF capacitor | 1 | Across servo power rail on PCA9685 |
| 100µF capacitor | 1 | Across nRF24L01 VCC–GND |
| Jumper wires | — | — |

---

## Wiring Diagram

### PCA9685 → Arduino Uno

| PCA9685 Pin | Arduino Uno Pin | Notes |
|---|---|---|
| VCC | 5V | Logic power |
| GND | GND | |
| SDA | A4 | I2C data |
| SCL | A5 | I2C clock |
| OE | GND | Output Enable (active LOW) |

### nRF24L01 → Arduino Uno

| nRF24L01 Pin | Arduino Uno Pin | Notes |
|---|---|---|
| VCC | 3.3V | **Use 3.3V, NOT 5V** |
| GND | GND | |
| CE | D9 | Chip Enable |
| CSN | D10 | Chip Select (SPI SS) |
| SCK | D13 | SPI Clock |
| MOSI | D11 | SPI Data OUT |
| MISO | D12 | SPI Data IN |

### Servos → PCA9685

| Servo | Joint | PCA9685 Channel | Signal Color |
|---|---|---|---|
| MG996R #1 | Base rotation | 0 | Orange/Yellow |
| MG996R #2 | Shoulder | 1 | Orange/Yellow |
| MG996R #3 | Elbow | 2 | Orange/Yellow |
| MG996R #4 | Gripper | 3 | Orange/Yellow |

> Connect each servo's 3-pin connector to PCA9685 channels 0–3. The pin order on PCA9685 headers is: **GND · VCC · Signal** (from inner to outer edge).

### Servo Power Rail on PCA9685

| PCA9685 Terminal | Connection |
|---|---|
| V+ | 5V from external **5V 3A** power supply |
| GND | GND of external power supply **AND** Arduino GND (common ground) |

> ⚠️ **CRITICAL:** Servos draw 500mA–1A each under load. **Never** power servos from the Arduino's 5V pin — it only supplies ~500mA total and will cause resets or damage. Use a dedicated 5V 3A supply.

> ⚠️ **IMPORTANT:** Place a **470µF capacitor** across the PCA9685 V+ and GND terminals to suppress voltage spikes from servo stall currents.

---

## Power Summary

```
[12V/9V Battery or 5V Adapter] → [Arduino Uno VIN or USB]
[5V 3A Supply] → PCA9685 V+ rail → All 4 Servos
[Arduino 3.3V] → nRF24L01 VCC
All GNDs connected together (common ground)
```

---

## Servo Angle Reference

| Joint | Min (°) | Max (°) | Home (°) |
|---|---|---|---|
| Base | 0 | 180 | 90 |
| Shoulder | 30 | 150 | 90 |
| Elbow | 0 | 160 | 90 |
| Gripper | 30 (open) | 120 (closed) | 30 |
