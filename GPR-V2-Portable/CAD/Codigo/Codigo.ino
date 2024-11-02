#include <AccelStepper.h>

// Define the stepper motor connections
#define ENABLE_PIN 2
#define DIR_PIN 3
#define STEP_PIN 4

// Create an instance of the AccelStepper class
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  // Set up the motor properties
  stepper.setMaxSpeed(200.0);     // Maximum speed in steps per second
  stepper.setAcceleration(1000.0); // Acceleration in steps per second per second

  // Set up the motor control pins
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, HIGH); // Enable the motor

  // Set up the serial communication
  Serial.begin(9600);
}

void loop() {
  // Move the motor one revolution in one direction
  stepper.move(1000);  // 200 steps per revolution for full-step mode

  // Run the motor in the background
  while (stepper.run()) {
    // You can perform other non-blocking tasks here
  }

  delay(1000); // Wait for a moment before moving in the other direction

  // Move the motor one revolution in the opposite direction
  stepper.move(-1000);

  // Run the motor in the background
  while (stepper.run()) {
    // You can perform other non-blocking tasks here
  }

  delay(1000); // Wait for a moment before the next iteration
}
