# Transmitter Wiring Guide — Gesture Glove

## Overview

The glove transmitter reads hand orientation from an **MPU6050 IMU** and sends servo commands wirelessly via a **nRF24L01** module, both controlled by an **Arduino Nano**.

---

## Components

| Component | Qty | Notes |
|---|---|---|
| Arduino Nano | 1 | ATmega328P, 5V logic |
| MPU6050 IMU | 1 | 6-axis (accel + gyro), I2C |
| nRF24L01 module | 1 | 2.4GHz wireless, SPI |
| 100µF capacitor | 1 | Across nRF24L01 VCC–GND |
| 9V battery + clip | 1 | Power supply |
| Jumper wires | — | — |
| Glove | 1 | Mount all components on back-of-hand |

---

## Wiring Diagram

### MPU6050 → Arduino Nano

| MPU6050 Pin | Arduino Nano Pin | Notes |
|---|---|---|
| VCC | 3.3V | **Use 3.3V, NOT 5V** |
| GND | GND | |
| SDA | A4 | I2C data |
| SCL | A5 | I2C clock |
| AD0 | GND | Sets I2C address to 0x68 |
| INT | — | Not used |

### nRF24L01 → Arduino Nano

| nRF24L01 Pin | Arduino Nano Pin | Notes |
|---|---|---|
| VCC | 3.3V | **Use 3.3V, NOT 5V** |
| GND | GND | |
| CE | D9 | Chip Enable |
| CSN | D10 | Chip Select (SPI SS) |
| SCK | D13 | SPI Clock |
| MOSI | D11 | SPI Data OUT |
| MISO | D12 | SPI Data IN |
| IRQ | — | Not used |

> ⚠️ **IMPORTANT:** Place a **100µF electrolytic capacitor** between nRF24L01 VCC and GND. Motor/servo power spikes can brown-out the nRF24L01 without it.

---

## Power

Power the Arduino Nano via its **VIN pin** from a 9V battery. The onboard regulator will produce 5V for logic. The Nano's 3.3V pin powers both the MPU6050 and nRF24L01.

---

## Mounting Tips

- Secure the MPU6050 flat on the **back of the hand** using double-sided tape
- Mount the Arduino Nano and nRF24L01 on a small piece of perf board on the **wrist**
- Route wires along the fingers using cable ties or tape
- Keep total wrist-unit weight under 50g for comfortable wear
