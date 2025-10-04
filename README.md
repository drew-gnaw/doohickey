# Slap Hand Alarm - Arduino Wake Up Device

An Arduino-based alarm system that uses a slap hand attached to a rotation motor to physically wake someone up at a set time. When the alarm goes off, the motor continuously rotates the hand to deliver gentle (or not so gentle) slaps until the alarm duration ends.

## Features

- **Time-based alarm**: Set specific wake-up time (hour and minute)
- **Continuous rotation**: Motor runs continuously during alarm period
- **Adjustable duration**: Configure how long the slapping lasts (default 30 seconds)
- **RTC integration**: Uses Real-Time Clock module for accurate timekeeping
- **Serial monitoring**: Debug output shows current time and alarm status

## Hardware Requirements

- Arduino board (Uno, Nano, Mega, or compatible)
- DC motor or continuous rotation servo
- L298N motor driver (or similar H-bridge driver for DC motors)
- DS3231 RTC module (or compatible I2C RTC)
- Power supply appropriate for your motor (typically 5-12V)
- Slap hand attachment (foam hand, cardboard cutout, etc.)
- Connecting wires and breadboard

## Wiring Diagram

### Motor Driver Connections
- Motor Driver IN1 → Arduino Pin 7
- Motor Driver IN2 → Arduino Pin 8
- Motor Driver ENA/ENB → Arduino Pin 9 (PWM)
- Motor Driver VCC → External Power Supply (+)
- Motor Driver GND → Common Ground
- Motor connections to motor driver output terminals

### RTC Module Connections
- RTC VCC → Arduino 5V
- RTC GND → Arduino GND
- RTC SDA → Arduino SDA (A4 on Uno)
- RTC SCL → Arduino SCL (A5 on Uno)

### Power
- Arduino powered via USB or external supply
- Motor powered from separate supply through motor driver
- **Important**: Connect all grounds together (common ground)

## Software Dependencies

This project requires the RTClib library:

1. Open Arduino IDE
2. Go to Sketch → Include Library → Manage Libraries
3. Search for "RTClib" by Adafruit
4. Click Install

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/drew-gnaw/doohickey.git
   ```

2. Open `slap_hand_alarm.ino` in Arduino IDE

3. Install required libraries (see Software Dependencies)

4. Connect your Arduino and upload the sketch

## Configuration

You can customize the alarm settings by modifying these constants in the code:

```cpp
// Alarm time settings
const int ALARM_HOUR = 7;         // Wake up hour (0-23, 24-hour format)
const int ALARM_MINUTE = 0;       // Wake up minute (0-59)

// Motor settings
const int MOTOR_SPEED = 200;      // Motor speed (0-255)
const int SLAP_DURATION = 30000;  // Duration in milliseconds (30000 = 30 seconds)
```

## Usage

1. Wire up the components according to the wiring diagram
2. Upload the sketch to your Arduino
3. Open Serial Monitor (9600 baud) to see status messages
4. The RTC will be set to compile time on first run
5. Mount the slap hand on the motor shaft
6. Position the device near the sleeping person's bed
7. The alarm will trigger at the configured time
8. Motor will run for the specified duration, rotating the slap hand
9. After the duration, motor stops and waits for the next alarm time

## Safety Notes

⚠️ **Important Safety Considerations**:
- Use a soft foam hand or similar safe material for the slapping mechanism
- Ensure motor and hand assembly is securely mounted to prevent it from flying off
- Test the system while awake to ensure safe operation
- Keep away from face/eyes - aim for arm or shoulder area
- Ensure proper electrical insulation and motor driver heat dissipation
- Always use appropriate power supply with proper voltage/current ratings

## Troubleshooting

**Motor doesn't run:**
- Check motor driver connections and power supply
- Verify motor driver is getting proper voltage
- Check that pins 7, 8, and 9 are correctly connected

**Time is incorrect:**
- RTC battery may be dead or missing
- Re-upload sketch to reset RTC to compile time
- Consider manually setting time in code

**Alarm doesn't trigger:**
- Open Serial Monitor to verify current time
- Check ALARM_HOUR and ALARM_MINUTE settings
- Ensure RTC is functioning correctly

## License

MIT License - Feel free to modify and use for your own wake-up needs!

## Contributing

Contributions welcome! Feel free to submit issues or pull requests.
