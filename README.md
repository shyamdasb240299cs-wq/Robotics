# Robotics - Arduino PID Control System

A robotics control system featuring PID-based speed control and safety cutoff logic for multi-thruster systems.

## Project Structure

```
├── Safty_cutoff_logic/
│   └── safty.c              # Safety validation module for thruster control
├── Speed_controll/
│   ├── pid.c                # C implementation of PID speed controller
│   └── pid.ino              # Arduino sketch for PID speed control via Serial
└── README.md                # This file
```

## Features

### 1. Safety Cutoff Logic (`Safty_cutoff_logic/safty.c`)
Validates thruster/motor input values with the following constraints:
- **Max Threshold**: Individual thruster values cannot exceed 230
- **Rate of Change**: Difference between consecutive thrusters is limited to 80
- **Total Power Limit**: Sum of all thruster values cannot exceed 900
- Automatically clamps violating values to 90% of original

**Input**: 6 thruster values (T1-T6)  
**Output**: Clamped and validated thruster values

### 2. PID Speed Controller
Implements Proportional-Integral-Derivative control algorithm for precise speed regulation.

**Parameters**:
- Kp (Proportional gain): 1.2
- Ki (Integral gain): 0.02
- Kd (Derivative gain): 0.5

#### C Implementation (`Speed_controll/pid.c`)
- Console-based speed control simulator
- Accepts user input for target and initial speed
- Simulates 20 control cycles with real-time feedback
- Displays P, I, D error components and control output

#### Arduino Implementation (`Speed_controll/pid.ino`)
- Serial communication interface for hardware integration
- Real-time PID control loop (500ms update rate)
- Arduino-compatible for embedded robotics applications
- Expects target and current speed via Serial input

## Usage

### Safety Cutoff Logic
```bash
gcc -o safty Safty_cutoff_logic/safty.c
./safty
# Enter 6 thruster values when prompted
```

### PID Controller (C)
```bash
gcc -o pid Speed_controll/pid.c
./pid
# Enter target speed and initial speed when prompted
```

### PID Controller (Arduino)
1. Upload `Speed_controll/pid.ino` to your Arduino board
2. Open Serial Monitor (9600 baud)
3. Send target speed and initial speed values
4. Monitor real-time PID control feedback

## Control Loop

The system continuously:
1. Calculates position error (target - current)
2. Accumulates integral error over time
3. Computes derivative of error
4. Outputs control signal: `output = Kp×error + Ki×∫error + Kd×d(error)`
5. Updates current speed based on control output

## Requirements

- GCC compiler (for C implementations)
- Arduino IDE or compatible uploader
- Arduino board (for .ino deployment)

## Author
Shyamdas N

## License
Open source - Feel free to use and modify for your robotics projects
