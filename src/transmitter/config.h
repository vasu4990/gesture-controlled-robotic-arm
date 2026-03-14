/**
 * @file config.h
 * @brief Transmitter (Glove) Configuration
 *
 * Gesture-Controlled Robotic Arm
 * Transmitter Side — Arduino Nano + MPU6050 + nRF24L01
 */

#ifndef CONFIG_H
#define CONFIG_H

// ─── nRF24L01 Radio ──────────────────────────────────────────────────────────
#define RF_CHANNEL        100             // 2.4GHz channel (0–125)
#define RF_WRITE_PIPE     0xE8E8F0F0E1LL  // Transmitter pipe address

// ─── MPU6050 IMU ─────────────────────────────────────────────────────────────
#define MPU_ADDR          0x68            // I2C address (AD0 = LOW)
#define GYRO_SCALE        131.0f          // LSB / (°/s) — ±250°/s range
#define ACCEL_SCALE       16384.0f        // LSB / g     — ±2g range

// ─── Complementary Filter ─────────────────────────────────────────────────────
// Alpha close to 1.0 → trusts gyro more (smoother)
// Alpha close to 0.0 → trusts accelerometer more (faster response)
#define COMP_FILTER_ALPHA 0.96f

// ─── Dead-Zone Thresholding ───────────────────────────────────────────────────
// Angles (in degrees) within which no command is sent (prevents jitter at rest)
#define DEAD_ZONE_PITCH   3.0f
#define DEAD_ZONE_ROLL    3.0f

// ─── Angle → Servo Mapping ───────────────────────────────────────────────────
// Raw IMU angle range mapped to servo command range (0–180°)
#define PITCH_MIN_ANGLE  -45.0f
#define PITCH_MAX_ANGLE   45.0f
#define ROLL_MIN_ANGLE   -45.0f
#define ROLL_MAX_ANGLE    45.0f

// ─── Timing ───────────────────────────────────────────────────────────────────
#define LOOP_INTERVAL_MS  20              // 50 Hz control loop

#endif  // CONFIG_H
