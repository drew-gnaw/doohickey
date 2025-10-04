# Circuit Diagrams

## Servo Version (Recommended for Beginners)

```
                    Arduino Uno/Nano
                  ┌─────────────────┐
                  │                 │
    RTC Module    │                 │    Continuous Rotation Servo
    ┌──────────┐  │                 │         ┌──────────┐
    │          │  │                 │         │          │
    │  VCC ────┼──┤ 5V              │         │   Red ───┼── 5V (from Arduino)
    │  GND ────┼──┤ GND             │         │   Brown ─┼── GND (from Arduino)
    │  SDA ────┼──┤ A4 (SDA)        │         │   Yellow ┼── Pin 9 (Signal)
    │  SCL ────┼──┤ A5 (SCL)        │         │          │
    │          │  │                 │         └──────────┘
    └──────────┘  │                 │              │
                  │                 │         Servo Horn
                  │                 │              │
                  │                 │         Foam Hand
                  │                 │         Attachment
                  │                 │
                  │                 │
    USB Power ────┤ USB Port        │
    or 5V DC      │                 │
                  └─────────────────┘
```

### Parts Count: 4 components
- 1x Arduino
- 1x RTC Module  
- 1x Continuous Rotation Servo
- 1x Foam Hand

### Connections: 6 wires total

---

## DC Motor Version (Advanced Users)

```
                    Arduino Uno/Nano
                  ┌─────────────────┐
                  │                 │
    RTC Module    │                 │    L298N Motor Driver        DC Motor
    ┌──────────┐  │                 │    ┌──────────────────┐    ┌────────┐
    │          │  │                 │    │                  │    │        │
    │  VCC ────┼──┤ 5V              │    │  OUT1 ───────────┼────┤ +      │
    │  GND ────┼──┤ GND             │    │  OUT2 ───────────┼────┤ -      │
    │  SDA ────┼──┤ A4 (SDA)        │    │                  │    │        │
    │  SCL ────┼──┤ A5 (SCL)        │    │  IN1  ───────────┼────┤ Pin 7  │
    │          │  │                 │    │  IN2  ───────────┼────┤ Pin 8  │
    └──────────┘  │                 │    │  ENA  ───────────┼────┤ Pin 9  │
                  │                 │    │                  │    │        │
                  │                 │    │  12V  ──┐        │    └────────┘
                  │                 │    │  GND  ──┼─┐      │         │
                  │                 │    │         │ │      │    Motor Shaft
                  │                 │    └─────────┼─┼──────┘         │
    USB Power ────┤ USB Port        │              │ │           Foam Hand
    (Arduino)     │                 │              │ │           Attachment
                  └─────────────────┘              │ │
                           │                       │ │
                           └───────────────────────┘ │
                             (Common Ground)         │
                                                      │
                    External Power Supply          ┌──┘
                    (9-12V DC, 1-2A)              │
                    ┌──────────────┐              │
                    │    +    -    │              │
                    └──────┬───┬───┘              │
                           │   │                  │
                           └───┴──────────────────┘
```

### Parts Count: 5+ components
- 1x Arduino
- 1x RTC Module
- 1x L298N Motor Driver
- 1x DC Motor
- 1x External Power Supply (9-12V)
- 1x Foam Hand

### Connections: 11 wires total

---

## Wiring Color Codes (Typical)

### Servo Wiring
- **Brown/Black**: Ground (GND)
- **Red**: Power (5V)
- **Yellow/White/Orange**: Signal (to Arduino Pin)

### RTC Module
- **VCC**: Red wire to 5V
- **GND**: Black wire to Ground
- **SDA**: Blue/Green wire to A4
- **SCL**: Yellow/White wire to A5

### Motor Driver (L298N)
- **IN1, IN2, ENA**: Control signals (any color)
- **12V, GND**: Power input (Red/Black)
- **OUT1, OUT2**: Motor connections (any color)

---

## Power Requirements

### Servo Version
- **Arduino**: 5V @ 500mA (USB or 5V adapter)
- **Servo**: 5V @ 500-1000mA (from Arduino or separate supply)
- **Total**: Can run from single USB connection (2.5W)

### DC Motor Version
- **Arduino**: 5V @ 500mA (USB)
- **Motor**: 6-12V @ 500-2000mA depending on motor
- **Total**: Requires separate power supply for motor (6-24W)

---

## Testing Checklist

### Before Powering On
- [ ] All connections match diagrams
- [ ] No exposed wire contacts touching
- [ ] Common ground connected (DC motor version)
- [ ] Power supply correct voltage
- [ ] Servo/motor can rotate freely

### First Power On
- [ ] Arduino LED lights up
- [ ] No smoke or burning smell
- [ ] RTC module LED on (if equipped)
- [ ] Upload test sketch successful

### Functionality Test
- [ ] Serial monitor shows time
- [ ] Motor/servo responds to commands
- [ ] Alarm triggers at set time
- [ ] Motor stops after duration
- [ ] Slap hand attached securely

---

## Common Wiring Mistakes

❌ **Wrong**: Servo powered from Arduino Pin (not enough current)
✅ **Right**: Servo Red wire to Arduino 5V pin (with common ground)

❌ **Wrong**: Motor driver and Arduino with separate grounds
✅ **Right**: All grounds connected together (common ground)

❌ **Wrong**: RTC SDA/SCL to wrong pins
✅ **Right**: RTC SDA to A4, SCL to A5 (on Uno/Nano)

❌ **Wrong**: Motor powered from Arduino 5V
✅ **Right**: Motor powered from external supply through driver

---

## Mounting Suggestions

```
    Wall/Desk Mount
    ═════════════════
         ║   ║
         ║   ║  ← Mounting bracket
    ┌────┴───┴────┐
    │   Arduino   │
    │   in Case   │
    └─────────────┘
         │
    ┌────┴────┐
    │  Motor  │
    │  Housing│
    └────┬────┘
         │
    ┌────┴────┐
    │  Servo  │
    │  Arm    │
    └────┬────┘
         │
     ___/🖐️\___ 
     Foam Hand
```

### Tips:
- Mount Arduino in plastic case for protection
- Use zip ties or hot glue for securing components
- Keep wires organized with cable ties
- Position motor at appropriate height for slapping
- Use adjustable arm for precise positioning

---

Need help? See ASSEMBLY.md for detailed step-by-step instructions!
