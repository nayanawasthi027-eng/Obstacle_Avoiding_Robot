# 📘 **1. Project Overview**

This project is a self‑driving mobile robot that detects obstacles using an ultrasonic sensor and automatically chooses the best path to move forward. The robot uses:

* **Ultrasonic sensor (HC‑SR04)** → to measure distance
* **Servo motor** → to rotate the sensor and scan Left, Front, Right
* **L298N/L293D motor driver** → to drive DC motors
* **Arduino** → to process signals, make decisions, and control the robot

The robot continuously scans its surroundings and decides whether to:

* Move **forward**
* Move **backward**
* Turn **left**
* Turn **right**
* **Stop** when too close to an obstacle

---

# 🧠 **2. Key Features**

### ✔ Servo‑based environmental scanning

The ultrasonic sensor is mounted on a servo motor, allowing the robot to scan 3 directions:

* **Left** (150°)
* **Center** (90°)
* **Right** (30°)

### ✔ Intelligent decision‑making

Robot chooses direction based on:

* Maximum free distance
* Safe threshold

### ✔ Smooth motor control

Motors are controlled using PWM for smooth turning and movement.

### ✔ Automatic obstacle detection

If an object is detected within **25 cm**, the robot:

1. Stops
2. Moves backward
3. Turns towards the direction with more space

### ✔ Clean, modular code

All major functions are separated:

* Motor control
* Distance measurement
* Servo scanning
* Decision making

---

# 🔧 **3. Components Required**

| Component                 | Quantity | Purpose              |
| ------------------------- | -------- | -------------------- |
| Arduino Uno/Nano          | 1        | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 1        | Distance measurement |
| Servo Motor (SG90)        | 1        | Rotating the sensor  |
| L298N/L293D Motor Driver  | 1        | Motor control        |
| DC Motors + Robot Chassis | 2        | Locomotion           |
| 9V/12V Battery            | 1        | Power supply         |
| Jumper Wires              | —        | Connections          |

---

# 🛠️ **4. Wiring Guide (Simple Explanation)**

## 🔷 **Ultrasonic Sensor → Arduino**

* Trig → D2
* Echo → D3
* VCC → 5V
* GND → GND

## 🔷 **Servo → Arduino**

* Signal → D11
* VCC → 5V
* GND → GND

## 🔷 **Motor Driver → Arduino**

**Left Motor:**

* IN1 → D6
* IN2 → D7
* ENA → D5 (PWM)

**Right Motor:**

* IN3 → D8
* IN4 → D9
* ENB → D10 (PWM)

Power:

* +12V → Battery
* GND → Common ground (battery + Arduino must share GND)

---

# 🧩 **5. How the Robot Works (Simple Logic)**

1. Servo rotates ultrasonic sensor to **Left → Center → Right**.
2. Distances from all three directions are stored.
3. If **front distance > safe distance (25 cm)** → robot moves forward.
4. If obstacle detected:

   * Robot stops.
   * Moves backward slightly.
   * Compares **Left vs. Right**.
   * Turns toward the direction with more space.
5. Servo comes back to the center.
6. Loop repeats.

---

# 📂 **6. File Structure**

```
Obstacle_Avoiding_Robot/
│
├── Advanced_Obstacle_Avoiding_Robot.ino
├── README.md
└── images/ (optional)
```

---

# 💻 **7. Full Code Used**

The complete Arduino C++ code used in this project is inside the `Advanced_Obstacle_Avoiding_Robot.ino` file. It includes:

* Motor control functions
* Servo scanning functions
* Distance measurement function
* Intelligent decision‑making system

---

# 🚀 **8. How to Run the Project**

1. Install Arduino IDE.
2. Connect Arduino to your PC using USB.
3. Open the `.ino` file.
4. Select **Board → Arduino Uno**.
5. Select the correct **COM Port**.
6. Upload the code.
7. Connect battery to power the motors.
8. Place the robot on the ground → it starts moving automatically.

---

# 🔍 **9. Troubleshooting Guide**

### ✔ Robot not moving forward

* Check motor polarity.
* Check motor driver wiring.

### ✔ Servo not rotating

* Check 5V supply.
* Make sure GND is common.

### ✔ Distance always reading 0

* Incorrect trig/echo wiring.
* Ultrasonic sensor damaged.

### ✔ Robot behaves randomly

* Battery might be low.
* Loose wires.

---

# 🧪 **10. Possible Improvements**

You can upgrade this robot easily:

* Add **Bluetooth** for manual control
* Use **PID control** for smoother turns
* Add **Infrared sensors** for better detection
* Add **speed encoders** for accuracy
* Add **Li‑ion battery pack** for longer run time

---

# 🎓 **11. What You Learn From This Project**

This project builds strong mechatronics foundations:

### ✔ Embedded C/C++ programming

### ✔ Robotics basics

### ✔ Sensor integration

### ✔ Motor control with PWM

### ✔ Servo control

### ✔ Decision-making algorithms

### ✔ Real-time systems

This is excellent to add on your **Mechatronics CV**.

---

# ⭐ **12. Credits**

Project designed for students learning:

* Mechatronics Engineering
* Robotics
* Embedded Systems
* Arduino Programming

You are free to modify and improve this project.

---

If you want, I can also:

* Add **images** to the README
* Generate a **PDF project report**
* Write **circuit diagrams**
* Add **flowchart and algorithm**
