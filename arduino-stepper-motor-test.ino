/*
========================================
 Arduino Stepper Motor Test
 Using 28BYJ-48 + ULN2003 Driver
========================================

Components:
- Arduino Uno / Nano
- 28BYJ-48 Stepper Motor
- ULN2003 Driver Module
- Jumper Wires

Wiring:
IN1 -> Pin 8
IN2 -> Pin 9
IN3 -> Pin 10
IN4 -> Pin 11
VCC -> 5V
GND -> GND
========================================
*/

#include <Stepper.h>

// Number of steps per revolution for 28BYJ-48
const int stepsPerRevolution = 2048;

// Initialize the stepper library
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set motor speed (RPM)
  myStepper.setSpeed(10);

  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Stepper Motor Test Started...");
}

void loop() {
  Serial.println("Rotating Clockwise...");
  myStepper.step(stepsPerRevolution); // one full rotation
  delay(1000);

  Serial.println("Rotating Counterclockwise...");
  myStepper.step(-stepsPerRevolution); // reverse rotation
  delay(1000);
}