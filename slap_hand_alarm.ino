/*
 * Slap Hand Alarm
 * 
 * This Arduino project controls a slap hand attached to a rotation motor.
 * It continuously rotates the hand to slap someone when it's time to wake up.
 * 
 * Hardware Requirements:
 * - Arduino board (Uno, Nano, etc.)
 * - DC motor or continuous rotation servo
 * - Motor driver (L298N or similar) if using DC motor
 * - Power supply appropriate for motor
 * - RTC module (DS3231 or similar) for accurate timekeeping
 * 
 * Wiring:
 * - Motor control pin connected to digital pin 9 (PWM)
 * - Motor direction pins (if using motor driver) to pins 7 and 8
 * - RTC module connected via I2C (SDA/SCL)
 */

#include <Wire.h>
#include <RTClib.h>

// Motor control pins
const int MOTOR_PWM_PIN = 9;      // PWM pin for motor speed control
const int MOTOR_DIR_PIN1 = 7;     // Direction control pin 1
const int MOTOR_DIR_PIN2 = 8;     // Direction control pin 2

// Motor settings
const int MOTOR_SPEED = 200;      // Motor speed (0-255)
const int SLAP_DURATION = 30000;  // Duration to run motor (30 seconds)

// Alarm settings
const int ALARM_HOUR = 7;         // Wake up hour (24-hour format)
const int ALARM_MINUTE = 0;       // Wake up minute

// State variables
bool alarmTriggered = false;
unsigned long alarmStartTime = 0;

RTC_DS3231 rtc;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Slap Hand Alarm Initializing...");
  
  // Initialize motor control pins
  pinMode(MOTOR_PWM_PIN, OUTPUT);
  pinMode(MOTOR_DIR_PIN1, OUTPUT);
  pinMode(MOTOR_DIR_PIN2, OUTPUT);
  
  // Stop motor initially
  stopMotor();
  
  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  // Check if RTC lost power and if so, set the time
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting time to compile time");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  Serial.println("Slap Hand Alarm Ready!");
  printCurrentTime();
  Serial.print("Alarm set for: ");
  Serial.print(ALARM_HOUR);
  Serial.print(":");
  if (ALARM_MINUTE < 10) Serial.print("0");
  Serial.println(ALARM_MINUTE);
}

void loop() {
  // Get current time
  DateTime now = rtc.now();
  
  // Check if it's time to trigger the alarm
  if (!alarmTriggered && now.hour() == ALARM_HOUR && now.minute() == ALARM_MINUTE) {
    Serial.println("WAKE UP! Alarm triggered!");
    alarmTriggered = true;
    alarmStartTime = millis();
    startMotor();
  }
  
  // If alarm is triggered, run motor for specified duration
  if (alarmTriggered) {
    unsigned long elapsed = millis() - alarmStartTime;
    
    if (elapsed >= SLAP_DURATION) {
      Serial.println("Alarm cycle complete");
      stopMotor();
      alarmTriggered = false;
      
      // Wait until the minute changes to avoid retriggering
      while (rtc.now().minute() == ALARM_MINUTE) {
        delay(1000);
      }
    }
  }
  
  // Print time every 10 seconds for monitoring
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 10000) {
    printCurrentTime();
    lastPrint = millis();
  }
  
  delay(100);  // Small delay to avoid excessive polling
}

void startMotor() {
  // Set motor direction (forward)
  digitalWrite(MOTOR_DIR_PIN1, HIGH);
  digitalWrite(MOTOR_DIR_PIN2, LOW);
  
  // Set motor speed
  analogWrite(MOTOR_PWM_PIN, MOTOR_SPEED);
  
  Serial.println("Motor started - Slapping engaged!");
}

void stopMotor() {
  // Stop motor
  digitalWrite(MOTOR_DIR_PIN1, LOW);
  digitalWrite(MOTOR_DIR_PIN2, LOW);
  analogWrite(MOTOR_PWM_PIN, 0);
  
  Serial.println("Motor stopped");
}

void printCurrentTime() {
  DateTime now = rtc.now();
  Serial.print("Current time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  if (now.minute() < 10) Serial.print("0");
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  if (now.second() < 10) Serial.print("0");
  Serial.println(now.second(), DEC);
}
