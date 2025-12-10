// ------------------------------------------------------
// ADVANCED OBSTACLE AVOIDING ROBOT
// Ultrasonic + Servo Scanning + Direction Decision
// Motors with PWM speed control
// ------------------------------------------------------

#include <Servo.h>

// -----------------------------
// Motor Driver Pins (L298N)
// -----------------------------
int ENA = 5;    // Motor A speed (PWM)
int IN1 = 6;    // Motor A forward
int IN2 = 7;    // Motor A backward

int ENB = 10;   // Motor B speed (PWM)
int IN3 = 8;    // Motor B forward
int IN4 = 9;    // Motor B backward

// -----------------------------
// Ultrasonic Sensor Pins
// -----------------------------
int trigPin = 2;
int echoPin = 3;

// -----------------------------
// Servo Pin
// -----------------------------
Servo sensorServo;
int servoPin = 11;

// -----------------------------
// Variables
// -----------------------------
long duration;
int distance;

// Scan distances
int distLeft = 0;
int distFront = 0;
int distRight = 0;

// Motor speed
int speed = 180;

// ------------------------------------------------------
// Function: Get Distance
// ------------------------------------------------------
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int dist = duration * 0.034 / 2;

  if (dist > 300) dist = 300;
  return dist;
}

// ------------------------------------------------------
// Motor Controls
// ------------------------------------------------------
void forward() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void leftTurn() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void rightTurn() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// ------------------------------------------------------
// Servo Scanning Function
// ------------------------------------------------------
void scanEnvironment() {
  // Left
  sensorServo.write(150);
  delay(400);
  distLeft = getDistance();
  Serial.print("Left: ");
  Serial.println(distLeft);

  // Front
  sensorServo.write(90);
  delay(300);
  distFront = getDistance();
  Serial.print("Front: ");
  Serial.println(distFront);

  // Right
  sensorServo.write(30);
  delay(400);
  distRight = getDistance();
  Serial.print("Right: ");
  Serial.println(distRight);

  // Reset servo to center
  sensorServo.write(90);
}

// ------------------------------------------------------
// Setup
// ------------------------------------------------------
void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  sensorServo.attach(servoPin);
  sensorServo.write(90);

  delay(1000);
}

// ------------------------------------------------------
// Main Loop
// ------------------------------------------------------
void loop() {

  scanEnvironment();  // Scan all directions

  if (distFront > 25) {
    // No obstacle - move forward
    forward();
  } 
  else {
    // Obstacle detected
    stopRobot();
    delay(200);

    // Move back a bit
    backward();
    delay(300);
    stopRobot();
    delay(200);

    // Decide best direction
    if (distLeft > distRight) {
      leftTurn();
      delay(450);
    } else {
      rightTurn();
      delay(450);
    }
  }

  delay(80);
}
