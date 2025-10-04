# Bill of Materials (BOM)

## Required Components

### Option 1: DC Motor Version (slap_hand_alarm.ino)

| Component | Quantity | Description | Example Part | Approx. Cost |
|-----------|----------|-------------|--------------|--------------|
| Arduino Uno/Nano | 1 | Main microcontroller | Arduino Uno R3 | $20-25 |
| DC Motor | 1 | 3-12V DC motor | TT Motor, N20 gear motor | $3-8 |
| L298N Motor Driver | 1 | H-bridge motor driver | L298N Module | $3-5 |
| DS3231 RTC Module | 1 | Real-time clock with battery | DS3231 I2C RTC | $3-5 |
| Power Supply | 1 | 9-12V DC adapter | 9V 1A power adapter | $5-10 |
| Foam Hand | 1 | Slap hand attachment | Party foam hand | $2-5 |
| Jumper Wires | 1 set | Male-to-male and male-to-female | Dupont wires | $5 |
| Breadboard | 1 | For prototyping (optional) | 400-point breadboard | $3-5 |

**Total Cost: ~$45-70**

### Option 2: Servo Version (slap_hand_alarm_servo.ino)

| Component | Quantity | Description | Example Part | Approx. Cost |
|-----------|----------|-------------|--------------|--------------|
| Arduino Uno/Nano | 1 | Main microcontroller | Arduino Uno R3 | $20-25 |
| Continuous Rotation Servo | 1 | Servo motor that rotates continuously | FS90R, SpringRC SM-S4303R | $6-10 |
| DS3231 RTC Module | 1 | Real-time clock with battery | DS3231 I2C RTC | $3-5 |
| Foam Hand | 1 | Slap hand attachment | Party foam hand | $2-5 |
| Jumper Wires | 1 set | Male-to-male and male-to-female | Dupont wires | $5 |

**Total Cost: ~$35-50**

**Note**: The servo version is recommended for beginners as it requires fewer components and simpler wiring.

## Optional Components

| Component | Purpose | Cost |
|-----------|---------|------|
| 9V Battery + Connector | Portable power for Arduino | $5-8 |
| USB Power Bank | Alternative portable power | $10-20 |
| Mounting Hardware | Screws, standoffs, enclosure | $5-15 |
| Switch | Power on/off control | $1-2 |
| Additional Batteries | Backup RTC battery (CR2032) | $2-5 |

## Shopping Links

### Online Retailers
- **Amazon**: Search for "Arduino starter kit" for bundles
- **SparkFun**: Electronics.sparkfun.com
- **Adafruit**: Adafruit.com
- **AliExpress**: Cheaper alternatives (longer shipping)
- **eBay**: Used/surplus components

### Local Options
- Electronics hobby shops
- RadioShack (if still available in your area)
- University surplus stores

## Notes

1. **Motor Choice**: 
   - DC motors provide more torque but need motor driver
   - Continuous rotation servos are simpler but may have less power
   - Choose based on weight of your slap hand attachment

2. **Power Supply**:
   - Arduino can be powered via USB (5V)
   - DC motors may need separate 6-12V supply
   - Servos typically run on 5V from Arduino

3. **RTC Battery**:
   - DS3231 modules usually include CR2032 battery
   - Battery keeps time when main power is off
   - Can last 1-2 years

4. **Safety First**:
   - Always use a soft, lightweight slap hand
   - Test thoroughly before actual use
   - Keep away from face and sensitive areas
