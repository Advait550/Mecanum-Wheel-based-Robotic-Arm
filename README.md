# 🤖 Mecanum Wheel-Based Robotic Arm

<p align="center">
  <img src="https://img.shields.io/badge/Robotics-Mecanum%20Drive-4364F7?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Arduino-C%2B%2B-00878F?style=for-the-badge&logo=arduino&logoColor=white" />
  <img src="https://img.shields.io/badge/Control-PWM-0052D4?style=for-the-badge" />
</p>

## 📌 Overview

A mobile robotic manipulation system combining **mecanum-wheel omnidirectional mobility** with a **servo-driven robotic arm**. The platform is intended for autonomous or remotely controlled material-handling tasks where both mobility and manipulation are required.

The project uses separate control logic for the mobile base and robotic arm. The base controller receives commands over **HC-05 Bluetooth** and drives four motors through a motor-driver interface, while the arm controller receives serial commands and positions multiple servo motors.

## 🏗️ System Architecture

```text
                    ┌─────────────────────┐
                    │   Remote Controller │
                    └──────────┬──────────┘
                               │
                         HC-05 Bluetooth
                               │
                               ▼
                    ┌─────────────────────┐
                    │   Base Controller   │
                    │      Arduino        │
                    └──────────┬──────────┘
                               │
                        Motor Driver
                               │
              ┌────────────────┼────────────────┐
              ▼                ▼                ▼
           Wheel 1          Wheel 2          Wheel 3 ... Wheel 4

                    ┌─────────────────────┐
                    │   Arm Controller   │
                    │      Arduino        │
                    └──────────┬──────────┘
                               │
                              PWM
                               │
                    ┌──────────┴──────────┐
                    │ Servo-driven Arm    │
                    │ + Gripper           │
                    └─────────────────────┘
```

## 🛠️ Hardware

The original project documentation specifies:

- Arduino Uno controllers
- Four mecanum wheels
- Servo-driven robotic arm
- L293D / AFMotor-based motor-control interface
- HC-05 Bluetooth module
- Independent power for motor and logic sections
- Custom mechanical chassis

> **Note:** The original documentation describes the robotic arm as a 4-DOF system, while the current `Arm_control.ino` source exposes seven servo channels. The repository preserves the available source code as provided by the project.

## ⚙️ Key Features

### Mecanum Drive

The four mecanum wheels allow:

- Forward / backward motion
- Sideways (crab) motion
- Diagonal movement
- Rotation in place

Different combinations of wheel directions produce different chassis motions without requiring conventional steering.

### Robotic Arm

The arm controller:

- Controls multiple servo channels using PWM
- Accepts serial commands
- Maps command values to individual servo positions
- Coordinates paired servo movement for one arm joint

### Wireless Base Control

The base controller uses:

- HC-05 Bluetooth
- SoftwareSerial
- Command-based motion control
- Adjustable wheel speed
- Functions for translation, diagonal motion and rotation

## 🧠 Control Logic

### Base controller

Bluetooth commands are converted into motion states such as:

```text
0  → Stop
1  → Forward-right
2  → Forward
3  → Forward-left
4  → Right
5  → Left
6  → Backward-right
7  → Backward
8  → Backward-left
9  → Rotate-left
10 → Rotate-right
```

Values at or above 16 are interpreted as wheel-speed commands by the current implementation.

### Arm controller

The serial command format is interpreted as:

```text
<servo-index> <servo-angle>
```

The controller then maps the requested index to the corresponding servo output.

## 📂 Repository Structure

```text
.
├── Arm_control.ino      # Robotic arm and servo control
├── base_control.ino     # Mecanum base + Bluetooth control
└── README.md
```

## 🚀 Getting Started

### Arm Controller

1. Open `Arm_control.ino` in Arduino IDE.
2. Select the appropriate Arduino board and serial port.
3. Connect the servo control lines to the pins configured in the sketch.
4. Upload the firmware.
5. Send serial commands in the expected format.

### Base Controller

1. Open `base_control.ino` in Arduino IDE.
2. Install the required Arduino libraries:
   - SoftwareSerial
   - AFMotor
   - Wire
3. Connect the HC-05 Bluetooth module according to the configured RX/TX pins.
4. Connect the motor driver and four motors.
5. Upload the firmware.
6. Send motion commands through Bluetooth.

## 🔧 Engineering Concepts Demonstrated

- Embedded C/C++ programming
- PWM-based servo control
- DC motor control
- Mecanum wheel kinematics
- Bluetooth serial communication
- Multi-controller embedded architecture
- Command-based state control
- Hardware-software integration

## 🔬 Future Improvements

- Migrate both controllers to ESP32
- Replace blocking command handling with a cleaner event-driven architecture
- Add inverse kinematics for the robotic arm
- Add encoder feedback for closed-loop wheel control
- Add IMU-based orientation feedback
- Add computer vision for object detection
- Add telemetry and remote monitoring
- Introduce an RTOS for coordinated base/arm tasks

## 🏆 Project Context

This project was developed as an **academic and applied robotics prototype** and demonstrated as a technical project.

---
