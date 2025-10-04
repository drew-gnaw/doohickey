/*
 * Slap Hand Alarm - Servo Version
 * 
 * Simplified version using a continuous rotation servo instead of DC motor.
 * This is easier for beginners as it doesn't require a motor driver.
 * 
 * Hardware Requirements:
 * - Arduino board (Uno, Nano, etc.)
 * - Continuous rotation servo (FS90R or similar)
 * - RTC module (DS3231 or similar) for accurate timekeeping
 * - 5V power supply or USB power for Arduino
 * 
 * Wiring:
 * - Servo signal wire (yellow/white) to Arduino pin 9
 * - Servo power wire (red) to Arduino 5V
 * - Servo ground wire (brown/black) to Arduino GND
 * - RTC module connected via I2C (SDA/SCL)
 */

#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

// Servo control
Servo slapServo;
const int SERVO_PIN = 9;

// Servo settings (90 = stop, 0 = full reverse, 180 = full forward)
const int SERVO_ROTATE_SPEED = 180;  // Continuous rotation speed
const int SERVO_STOP = 90;            // Stop position
const int SLAP_DURATION = 30000;      // Duration to run servo (30 seconds)

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
  Serial.println("Slap Hand Alarm (Servo Version) Initializing...");
  
  // Attach and stop servo
  slapServo.attach(SERVO_PIN);
  stopServo();
  
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
    startServo();
  }
  
  // If alarm is triggered, run servo for specified duration
  if (alarmTriggered) {
    unsigned long elapsed = millis() - alarmStartTime;
    
    if (elapsed >= SLAP_DURATION) {
      Serial.println("Alarm cycle complete");
      stopServo();
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

void startServo() {
  // Start continuous rotation
  slapServo.write(SERVO_ROTATE_SPEED);
  Serial.println("Servo started - Slapping engaged!");
}

void stopServo() {
  // Stop servo
  slapServo.write(SERVO_STOP);
  Serial.println("Servo stopped");
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
