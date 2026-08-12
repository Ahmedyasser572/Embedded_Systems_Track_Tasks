# Ultrasonic Parking Sensor

An embedded parking-assistance project written in C for an AVR microcontroller. The application uses an HC-SR04 ultrasonic sensor to measure the distance to an object and gives the driver three types of feedback:

- Distance shown on an LCD.
- Distance level shown on an LED bar.
- Warning buzzer whose activity increases as the object gets closer.

## How the Application Works

1. The application sends a short trigger pulse from the microcontroller to the HC-SR04.
2. The sensor returns an echo pulse whose width represents the distance.
3. Timer1 input capture measures the echo pulse.
4. Timer1 overflow interrupts extend the measurement when the pulse is longer than one timer cycle.
5. The timer result is converted to centimeters.
6. The distance is displayed on the LCD.
7. When the distance is less than or equal to 105 cm, the LED bar and buzzer are enabled.
8. When the distance is greater than 105 cm, the warning indicators are turned off.

## Project Structure

```text
Parking_sensor_Project/
├── APP/
│   ├── App_main.h       Application-level driver includes
│   └── CFile4.c         Main ultrasonic-sensor application
├── HAL/                 Hardware abstraction layer drivers
│   ├── LCD/              LCD driver
│   ├── Led_bar/          LED-bar driver
│   └── ...               Other reusable hardware drivers
├── MCAL/                Microcontroller abstraction layer drivers
│   ├── Dio/              Digital input/output driver
│   ├── GIE/              Global interrupt driver
│   ├── Timer0/           Timer0 driver for buzzer timing
│   ├── Timer1/           Timer1 driver and private registers
│   └── ...               Other MCU peripheral drivers
├── LIB/                 Common project libraries
│   ├── Std_Types.h       Project integer and floating-point types
│   └── Bit_Math.h       Bit manipulation macros
└── Debug/               Generated build files and output
```

## Main Application File

The main application is located in [APP/CFile4.c](APP/CFile4.c). It contains:

- `main()` for initialization and the continuous measurement loop.
- `Toggle_Buzzzer()` for periodically toggling the buzzer.
- `TIMER1_OVF_vect` for counting Timer1 overflows.
- LCD output logic.
- LED-bar warning logic.
- HC-SR04 trigger and echo timing logic.

## Used Libraries and Drivers

### AVR standard libraries

| Include | Purpose |
|---|---|
| `<avr/io.h>` | Defines AVR hardware registers and peripheral bit names. |
| `<avr/interrupt.h>` | Provides `ISR()` and interrupt-related declarations. |
| `<util/delay.h>` | Provides `_delay_us()` and `_delay_ms()` delays. |
| `<stdlib.h>` | Provides `dtostrf()` for converting the measured distance to text. |
| `<string.h>` | Provides `strcat()` for adding the `cm` unit to the LCD text. |

### Project libraries

| Header or driver | Purpose |
|---|---|
| `App_main.h` | Central application header that includes the required project drivers. |
| `Dio.h` | Configures pins, writes pins, reads pins, and toggles outputs. |
| `Gie.h` | Enables global interrupts. |
| `Timer0.h` | Configures Timer0 in CTC mode and calls the buzzer callback. |
| `timer1.h` | Supports Timer1 operation and input-capture measurement. |
| `Lcd.h` | Initializes the LCD and displays text. |
| `ledBar.h` | Initializes the LED bar and displays a warning level. |
| `Std_Types.h` | Defines project types such as `u8` and `u16`. |
| `Bit_Math.h` | Provides common bit set, clear, toggle, and read macros. |

The project is organized into two driver layers:

- **MCAL:** Microcontroller Abstraction Layer. It communicates directly with AVR peripherals such as DIO, Timer0, Timer1, and interrupts.
- **HAL:** Hardware Abstraction Layer. It provides reusable drivers for external hardware such as the LCD and LED bar.

## Hardware Connections Used by the Application

| Signal | Microcontroller connection | Function |
|---|---|---|
| HC-SR04 trigger | Port D, Pin 0 | Sends the 10-microsecond trigger pulse. |
| HC-SR04 echo | Port D, Pin 6 | Receives the echo pulse. |
| Buzzer | Port D, Pin 7 | Warning output controlled by Timer0. |
| LCD data/control | Ports A and C | Displays the measured distance. |
| LED bar | Configured by `ledBar` driver | Displays the warning level. |

> Confirm the exact wiring and microcontroller pin mapping with the circuit schematic before powering the hardware.

## Requirements

- AVR microcontroller board or simulator.
- AVR-GCC toolchain.
- `avr-libc` headers and libraries.
- Programmer, simulator, or supported embedded build environment.
- HC-SR04 ultrasonic sensor.
- LCD module.
- LED bar and buzzer.

The application currently assumes a CPU frequency of `16 MHz` through `F_CPU`. This value must match the actual microcontroller clock so that the delays and distance calculation remain accurate.

## Build Notes

This is an AVR embedded project. It should be compiled with an AVR compiler for the selected microcontroller, not with normal desktop GCC alone.

The build must include:

- `APP/CFile4.c`.
- The required MCAL source files.
- The required HAL source files.
- The project include directories.
- The correct AVR device option for the selected microcontroller.

A typical AVR-GCC build configuration also needs a device flag such as `-mmcu=<target-device>` and an output format suitable for flashing to the microcontroller. Replace `<target-device>` with the actual MCU model used by the project.

## Important Configuration Notes

- `F_CPU` must match the real CPU clock.
- Timer1 capture settings must match the selected AVR device.
- The LCD and LED-bar configuration files must match the physical wiring.
- The HC-SR04 echo signal must not exceed the voltage supported by the MCU input pin.
- The project uses blocking waits while waiting for the rising and falling echo edges.

## Possible Improvements

- Add a timeout to the echo waiting loops so the application cannot block forever.
- Replace raw Timer1 register values with named configuration macros.
- Rename `Toggle_Buzzzer()` to `Toggle_Buzzer()` for consistent spelling.
- Add a moving-average filter to reduce unstable distance readings.
- Separate the ultrasonic sensor logic into its own HAL driver.
- Add a warning-level configuration file instead of hard-coding `105 cm`.
- Add a proper AVR build configuration or Makefile.

## License

This project is provided for educational and embedded-systems practice purposes.
