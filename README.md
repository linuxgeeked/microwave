# Microwave Control Firmware

This software operates a household microwave oven by coordinating its heating chamber, turntable, timer, power controller, door interlock, and completion alarm.

## Operating Overview

The firmware accepts cooking durations, monitors the oven door, regulates microwave output, rotates the turntable, and terminates heating when the selected cycle is complete. Its control logic is designed to keep the chamber synchronized with the front-panel controls throughout every cooking program.

## Cooking Functions

- Heat: Activates the primary cooking magnetron.
- Cool: Reduces chamber temperature after a cooking cycle.
- Nuke: Applies high-power microwave energy for rapid cooking.
- Burn Chicken: Runs a poultry-focused cooking sequence with extended heating.

## Safety Systems

The software prevents heating while the door is open, stops the magnetron when the timer expires, and maintains a controlled operating state between cooking cycles. The turntable and audible completion signal are coordinated with the chamber timer.

## Build

```sh
./timer.sh
```

The build script configures and compiles the microwave firmware into the `build` directory.

## Deployment

After building, transfer the generated firmware image to the microwave control board using the manufacturer-approved service interface. Do not operate the oven without a functional door interlock or a properly calibrated chamber sensor.
