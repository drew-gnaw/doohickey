# Assembly and Setup Guide

## Step-by-Step Instructions

### Option 1: DC Motor Version

#### Step 1: Prepare Components
- Unbox all components from the BOM list
- Ensure Arduino IDE is installed on your computer
- Download the RTClib library (see main README)

#### Step 2: Wire the RTC Module
```
DS3231 RTC → Arduino
-----------------------
VCC → 5V
GND → GND
SDA → A4 (SDA)
SCL → A5 (SCL)
```

#### Step 3: Wire the L298N Motor Driver
```
L298N → Arduino
-----------------------
IN1 → Pin 7
IN2 → Pin 8
ENA → Pin 9 (PWM)

L298N → Power Supply
-----------------------
12V Input → +9-12V DC
GND → GND (Common ground with Arduino)

L298N → Motor
-----------------------
OUT1 → Motor Wire 1
OUT2 → Motor Wire 2
```

**Important**: Make sure Arduino GND and motor driver GND are connected together (common ground).

#### Step 4: Upload the Code
1. Connect Arduino to computer via USB
2. Open `slap_hand_alarm.ino` in Arduino IDE
3. Select correct board: Tools → Board → Arduino Uno (or your board)
4. Select correct port: Tools → Port → COMx or /dev/ttyUSBx
5. Click Upload button
6. Wait for "Done uploading" message

#### Step 5: Test the System
1. Open Serial Monitor (Tools → Serial Monitor)
2. Set baud rate to 9600
3. Verify you see initialization messages
4. Check current time is displayed
5. For immediate testing, modify ALARM_HOUR and ALARM_MINUTE to trigger in 1-2 minutes
6. Re-upload and watch for alarm trigger

#### Step 6: Attach the Slap Hand
1. Secure motor to a stable base
2. Attach foam hand or slapping mechanism to motor shaft
3. Ensure hand can rotate freely without obstruction
4. Test rotation is smooth and safe

### Option 2: Servo Version (Recommended for Beginners)

#### Step 1: Prepare Components
- Same as DC motor version

#### Step 2: Wire the RTC Module
```
DS3231 RTC → Arduino
-----------------------
VCC → 5V
GND → GND
SDA → A4 (SDA)
SCL → A5 (SCL)
```

#### Step 3: Wire the Servo
```
Servo → Arduino
-----------------------
Signal (Yellow/White) → Pin 9
Power (Red) → 5V
Ground (Brown/Black) → GND
```

**Note**: This is much simpler than the DC motor version!

#### Step 4: Upload the Code
1. Connect Arduino to computer via USB
2. Open `slap_hand_alarm_servo.ino` in Arduino IDE
3. Select correct board: Tools → Board → Arduino Uno (or your board)
4. Select correct port: Tools → Port → COMx or /dev/ttyUSBx
5. Click Upload button
6. Wait for "Done uploading" message

#### Step 5: Test the System
1. Open Serial Monitor (Tools → Serial Monitor)
2. Set baud rate to 9600
3. Verify you see initialization messages
4. Check current time is displayed
5. For immediate testing, modify ALARM_HOUR and ALARM_MINUTE to trigger in 1-2 minutes
6. Re-upload and watch for alarm trigger

#### Step 6: Attach the Slap Hand
1. Attach servo horn (included with servo) to servo shaft
2. Use hot glue or zip ties to attach foam hand to servo horn
3. Mount servo to stable base or enclosure
4. Ensure hand can rotate freely without hitting anything

## Configuration

### Setting the Alarm Time

Edit these lines in the code:
```cpp
const int ALARM_HOUR = 7;         // Change to your wake-up hour (0-23)
const int ALARM_MINUTE = 0;       // Change to your wake-up minute (0-59)
```

### Adjusting Motor/Servo Speed

**DC Motor Version:**
```cpp
const int MOTOR_SPEED = 200;      // Change value (0-255)
```

**Servo Version:**
```cpp
const int SERVO_ROTATE_SPEED = 180;  // Try values between 90-180
```

### Adjusting Alarm Duration
```cpp
const int SLAP_DURATION = 30000;  // Time in milliseconds (30000 = 30 seconds)
```

## Troubleshooting

### Arduino not detected
- Try different USB cable
- Install CH340 drivers if using clone Arduino
- Check Device Manager (Windows) or ls /dev/tty* (Linux/Mac)

### RTC not found error
- Check I2C connections (SDA/SCL)
- Verify RTC module has power (LED should be on)
- Try running I2C scanner sketch to detect devices

### Motor/Servo doesn't move
- Check all connections are secure
- Verify power supply is adequate
- Test motor/servo separately with simple sketch
- Check Serial Monitor for error messages

### Wrong time displayed
- RTC battery may be dead
- Re-upload sketch to reset time to compile time
- Manually set time in code if needed

### Alarm triggers repeatedly
- This is normal behavior - it will trigger every day at set time
- To disable, upload blank sketch or disconnect power
- Consider adding a physical on/off switch

## Safety Checklist

- [ ] Used soft, lightweight slap hand material
- [ ] Motor/servo is securely mounted
- [ ] All connections are insulated
- [ ] Tested at low speed first
- [ ] Positioned away from face/eyes
- [ ] Power supply has correct voltage
- [ ] Common ground established for all components
- [ ] Alarm time is set correctly
- [ ] Tested full alarm cycle while awake

## Next Steps

1. Build a proper enclosure for the electronics
2. Add a physical button to snooze or disable alarm
3. Add LED indicators for alarm status
4. Implement multiple alarm times
5. Add buzzer for audio alarm in addition to slapping
6. Create a 3D printed mounting system

Enjoy your slap hand alarm! 👋⏰
