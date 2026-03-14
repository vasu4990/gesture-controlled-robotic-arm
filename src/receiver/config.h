/**
 * @file config.h
 * @brief Receiver (Robotic Arm) Configuration
 *
 * Gesture-Controlled Robotic Arm
 * Receiver Side — Arduino Uno + PCA9685 + nRF24L01
 */

#ifndef CONFIG_H
#define CONFIG_H

// ─── nRF24L01 Radio ──────────────────────────────────────────────────────────
#define RF_CHANNEL 100              // Must match transmitter
#define RF_READ_PIPE 0xE8E8F0F0E1LL // Must match transmitter write pipe

// ─── PCA9685 PWM Driver (I2C)
// ─────────────────────────────────────────────────
#define PCA9685_ADDR 0x40
#define PWM_FREQUENCY 50 // 50Hz standard servo frequency

// Servo channel assignments on PCA9685
#define SERVO_BASE 0     // Base rotation
#define SERVO_SHOULDER 1 // Shoulder joint
#define SERVO_ELBOW 2    // Elbow joint
#define SERVO_GRIPPER 3  // Gripper open/close

// ─── Servo PWM Pulse Widths (microseconds)
// ──────────────────────────────────── MG996R servo: 500µs = 0°, 2400µs = 180°
#define SERVO_MIN_US 500
#define SERVO_MAX_US 2400

// ─── Joint Angle Limits (degrees) ────────────────────────────────────────────
#define BASE_MIN 0
#define BASE_MAX 180
#define SHOULDER_MIN 30
#define SHOULDER_MAX 150
#define ELBOW_MIN 0
#define ELBOW_MAX 160
#define GRIPPER_OPEN 30
#define GRIPPER_CLOSED 120

// ─── Arm Geometry (mm)
// ─────────────────────────────────────────────────────────
#define LINK1_LEN 120.0f // Upper arm length
#define LINK2_LEN 100.0f // Forearm length

// ─── Motion Smoothing
// ───────────────────────────────────────────────────────── Interpolation step
// (degrees per loop). Smaller = smoother, slower.
#define INTERP_STEP 2.0f

// ─── Timing
// ───────────────────────────────────────────────────────────────────
#define LOOP_INTERVAL_MS 20 // 50 Hz control loop

#endif // CONFIG_H
