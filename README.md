# Gesture-Controlled Robotic Arm

An Arduino reference implementation for controlling a multi-servo robotic arm from an **MPU6050 gesture transmitter over nRF24L01 wireless**.

> **Evidence status:** the repository contains transmitter/receiver firmware and wiring documentation. It does **not currently include reproducible measured latency/range/payload results, committed demo media, or a hardware-validation dataset**. Those results should be added only after they are measured and archived here.

## System architecture

```text
Hand motion
   ↓
MPU6050 accelerometer + gyroscope
   ↓
Complementary filter
   ↓
Pitch / roll dead-zone and mapping
   ↓
nRF24L01 transmitter
   ↓
2.4 GHz wireless packet
   ↓
nRF24L01 receiver
   ↓
Joint-limit checks + interpolation
   ↓
PCA9685 servo driver
   ↓
Arm servos
```

## What is implemented

### Transmitter

The Arduino Nano transmitter:

- reads raw MPU6050 accelerometer and gyroscope values;
- estimates pitch and roll using a complementary filter;
- applies configurable dead zones;
- maps filtered orientation to target joint angles;
- transmits a compact `ControlPacket` over nRF24L01;
- reports transmit success/failure over Serial.

See [`src/transmitter/transmitter.ino`](src/transmitter/transmitter.ino).

### Receiver

The Arduino Uno receiver:

- receives the same `ControlPacket` structure;
- constrains incoming values to configured joint limits;
- interpolates servo targets to reduce abrupt steps;
- drives the servos through a PCA9685 PWM controller;
- reports commanded joint positions over Serial.

See [`src/receiver/receiver.ino`](src/receiver/receiver.ino).

### Inverse-kinematics helper

The receiver contains a two-link planar inverse-kinematics helper based on the law of cosines. **It is currently an optional helper, not part of the active gesture-control path.** The active packet carries joint-angle targets directly.

That distinction is intentional so the README reflects what the runtime code actually does.

## Reference hardware

| Component | Role |
|---|---|
| Arduino Nano | gesture transmitter controller |
| MPU6050 | 6-axis IMU |
| nRF24L01 ×2 | wireless transmitter / receiver |
| Arduino Uno | arm receiver controller |
| PCA9685 | multi-channel servo PWM |
| hobby servos | arm actuation |
| external servo supply | servo power rail |

The exact servo model, mechanical geometry, power supply and joint calibration must match the real arm before hardware testing.

## Repository structure

```text
gesture-controlled-robotic-arm/
├── src/
│   ├── transmitter/
│   │   ├── transmitter.ino
│   │   └── config.h
│   └── receiver/
│       ├── receiver.ino
│       └── config.h
├── docs/
│   └── wiring/
├── copy-assets.ps1
├── LICENSE
└── README.md
```

## Bring-up sequence

1. Verify the transmitter and receiver pin mappings in the wiring documentation.
2. Power the servo rail separately from logic where appropriate and ensure grounds are common.
3. Test the nRF24L01 link without moving the arm.
4. Verify the receiver joint limits and servo neutral positions with the arm unloaded.
5. Begin with conservative motion limits.
6. Record raw/filtered orientation and commanded joint positions.
7. Measure latency, packet loss, repeatable range and mechanical behavior before publishing performance numbers.

## Validation still needed

The next credible evidence package should include:

- a real hardware photo showing the transmitter and arm;
- a short uncut demo video committed or linked from a stable source;
- test conditions for wireless range;
- timestamped latency measurements and methodology;
- servo supply voltage/current details;
- joint calibration values and mechanical limits;
- repeated payload tests if a payload specification is reported;
- raw data or logs supporting any accuracy/stability percentage.

Until that evidence exists, this repository should be read as a **hardware-oriented firmware/reference project**, not as a measured performance benchmark.

## Possible extensions

- flex-sensor or button-driven gripper input;
- second IMU for additional independent joint control;
- packet sequence numbers and link-health telemetry;
- radio timeout / fail-safe neutral behavior;
- calibration storage in EEPROM;
- measured control-loop and wireless latency tooling;
- Cartesian command mode using the existing IK helper.

## License

MIT — see [`LICENSE`](LICENSE).
