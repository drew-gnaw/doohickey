# Quick Start Guide

Get your slap hand alarm running in 5 minutes!

## Choose Your Version

### 🟢 **Beginners**: Use `slap_hand_alarm_servo.ino`
- Simpler wiring (only 3 wires for servo)
- Fewer components needed
- No motor driver required
- Perfect for first-time Arduino users

### 🔵 **Advanced**: Use `slap_hand_alarm.ino`
- More powerful motor control
- Better for heavier slap hands
- Requires motor driver
- More customization options

## Absolute Minimum Setup (Test Without RTC)

If you want to test the basic motor/servo function without the RTC:

1. Connect just the motor/servo:
   - **Servo**: Signal→Pin9, Red→5V, Black→GND
   - **DC Motor**: Use motor driver as described in ASSEMBLY.md

2. Comment out RTC code in the sketch (lines with `rtc.`)

3. Add manual trigger for testing:
   ```cpp
   void loop() {
     startMotor();  // or startServo()
     delay(5000);   // Run for 5 seconds
     stopMotor();   // or stopServo()
     delay(5000);   // Wait 5 seconds
   }
   ```

## Full Setup - 5 Steps

### 1. Install Software
- Download [Arduino IDE](https://www.arduino.cc/en/software)
- Install RTClib: Sketch → Include Library → Manage Libraries → Search "RTClib"

### 2. Get Hardware
- See **BOM.md** for shopping list
- Choose servo version if you're new to Arduino

### 3. Wire It Up
- Follow wiring in **ASSEMBLY.md**
- Double-check all connections
- Make sure grounds are connected (common ground)

### 4. Upload Code
```
1. Plug Arduino into computer via USB
2. Open slap_hand_alarm_servo.ino (or slap_hand_alarm.ino)
3. Tools → Board → Select your Arduino
4. Tools → Port → Select your port
5. Click Upload (→) button
6. Wait for "Done uploading"
```

### 5. Test It!
```
1. Open Serial Monitor (Tools → Serial Monitor)
2. Set to 9600 baud
3. Verify time is shown
4. Change alarm to trigger in 2 minutes
5. Re-upload and watch it work!
```

## Customization

### Change Alarm Time
```cpp
const int ALARM_HOUR = 7;    // Your wake time (0-23)
const int ALARM_MINUTE = 0;  // Minutes (0-59)
```

### Change Slap Duration
```cpp
const int SLAP_DURATION = 30000;  // Milliseconds (30000 = 30 sec)
```

### Adjust Speed
**Servo:**
```cpp
const int SERVO_ROTATE_SPEED = 180;  // Try 90-180
```

**DC Motor:**
```cpp
const int MOTOR_SPEED = 200;  // Try 100-255
```

## Common Issues

| Problem | Solution |
|---------|----------|
| Upload fails | Check USB cable, try different port, install drivers |
| Motor doesn't move | Check power supply, verify connections |
| Wrong time | RTC battery dead, re-upload to reset time |
| Can't find RTC | Check I2C connections (SDA/SCL) |

## Safety Reminders

⚠️ **IMPORTANT**:
- Use SOFT foam hand only
- Keep away from face/eyes
- Test thoroughly while awake first
- Secure all parts - nothing should fly off
- Use proper power supply

## Need More Help?

- **Full instructions**: See README.md
- **Wiring details**: See ASSEMBLY.md
- **Parts list**: See BOM.md
- **Troubleshooting**: See ASSEMBLY.md troubleshooting section

## Pro Tips

💡 **Make it better**:
- Add a physical on/off switch
- Use a project enclosure for clean look
- Add LED to show when alarm is active
- Mount to adjustable arm for perfect positioning
- Add snooze button (extra challenge!)

---

**Ready to wake up?** Start with the servo version and have fun! 👋⏰
