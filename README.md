# Programming in C - Coursework Assignment

## Overview
This repository contains the source code and related documentation for a four-part C programming coursework assignment. The project demonstrates applied proficiency in core C programming concepts, including control flow mechanisms, user-defined modular functions, array manipulation, recursion, and embedded systems simulation.

## Repository Structure
The project is divided into four primary directories, each corresponding to a specific problem statement from the assignment rubric:

* `Q1_water_quality/` - Source code and output for the environmental sensor data processor.
* `Q2_mobile_money/` - Source code and output for the transactional state machine.
* `Q3_logistics/` - Source code and output for array-based statistical analysis and recursive operations.
* `Q4_smart_parking/` - Arduino source code, circuit diagrams, and simulation screenshots for the hardware monitoring system.

## Module Descriptions

### Question 1: Sensor Monitoring System
A C program designed to process environmental sensor readings (temperature and turbidity) and output a standardized water-quality index. 
* **Key Concepts:** Standard input/output processing, floating-point arithmetic, custom functional logic, and standard library usage.
* **Execution:** Compiles to standard output and categorizes the water quality as Good, Warning, or Critical based on internal mathematical thresholds.

### Question 2: Mobile Money Transaction System
A continuous-execution command-line application that simulates a transaction processing interface for a mobile money agent.
* **Key Concepts:** Infinite `while` loops, `switch-case` control structures, input validation, state management, and the precise use of `break` and `continue` statements.
* **Execution:** Supports deposit additions, conditional withdrawal subtractions (with insufficient funds validation), balance inquiries, and session summaries.

### Question 3: Logistics Delivery Distance Analysis
An analytical program that processes a dataset of delivery route distances to extract key metrics.
* **Key Concepts:** Integer arrays, modular function reuse, pointer-based input validation, and recursive algorithms.
* **Execution:** Calculates total distance, average distance, identifies the maximum value in the dataset, and uses a recursive function to compute the total sum of the array elements down to a zero-element base case.

### Question 4: Arduino-Based Smart Parking System
An embedded systems simulation designed using Tinkercad Circuits, representing a proximity-based parking sensor.
* **Key Concepts:** Hardware integration, microcontrollers (Arduino Uno), ultrasonic sensor data (HC-SR04) interpretation, and digital output control.
* **Execution:** The C++ (Arduino-style C) code reads distance timing via trigger/echo pins, converts it to centimeters, and triggers conditional digital writes to a red LED and piezo buzzer if an object breaches the 30 cm threshold, or a green LED if the space remains available.

## Compilation and Execution Instructions
 
For standard C programs (Q1, Q2, and Q3), compile the code with the GNU Compiler Collection (GCC).
 
Go to the folder of the question and run these commands.
 
**1. Compile the source code:**
 
```bash
gcc filename.c -o output_name
```
 
**2. Run the compiled program:**
 
```bash
./output_name
```
 
> **Note:** The code for Q4 (`smart_parking.ino`) is designed to run in the Arduino IDE or in a Tinkercad simulation. It cannot be compiled and run with GCC on the command line.