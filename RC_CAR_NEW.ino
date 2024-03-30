#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1); // RX, TX

// Define the pins connected to the L298N module
const int ENA = 9;  // Enable motor A
const int IN1 = 2;  // Motor A input 1
const int IN2 = 3;  // Motor A input 2
const int ENB = 12; // Enable motor B
const int IN3 = 4;  // Motor B input 1
const int IN4 = 5;  // Motor B input 2

void setup() {
  // Set the motor control pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set up Bluetooth communication
  BTSerial.begin(9600);
}

void loop() {
  // Check if data is available from Bluetooth module
  if (BTSerial.available()) {
    char command = BTSerial.read();

    // Control the motors based on received commands
    switch (command) {
      case 'F': // Move forward
        moveForward();
        break;
      case 'B': // Move backward
        moveBackward();
        break;
      case 'L': // Turn left
        turnLeft();
        break;
      case 'R': // Turn right
        turnRight();
        break;
      case 'S': // Stop
        stopMotors();
        break;
    }
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 258);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255);
}

void stopMotors() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}
