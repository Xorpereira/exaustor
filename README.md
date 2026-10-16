# DIY Stove Vent Controller — Archive

Arduino controller for a DIY stove vent (range hood). Runs a 3-speed fan and a light
through a 4-channel relay board, using four push buttons.

This is an archived, working version of the firmware. Minimum changes only — made to
compile. No refactors or modernizations.

## Hardware

| Function          | Arduino Pin | Relay / Input  |
|-------------------|-------------|----------------|
| Fan speed 1 (low) | 3           | Relay 1        |
| Fan speed 2 (med) | 4           | Relay 2        |
| Fan speed 3 (high)| 5           | Relay 3        |
| Light             | 6           | Relay 4        |
| ON/OFF button     | 7           | INPUT_PULLUP   |
| MORE (+) button   | 8           | INPUT_PULLUP   |
| LESS (–) button   | 9           | INPUT_PULLUP   |
| LIGHT button      | 10          | INPUT_PULLUP   |

- Board: Arduino Uno / Nano (or equivalent)
- Relay module: 4-channel, active-LOW (LOW = energised)
- Buttons: pin to GND, internal pull-ups (pressed = LOW)
- Serial: 9600 baud, prints `power` each loop
- Low-voltage side is isolated from mains side
- Each motor winding is individually fused (specs from original design)

## Operation

- power = onoffstate + morestate + lessstate
- 0 = off, 1 = low, 2 = medium, 3 = high
- Only one fan relay energised at a time
- 300 ms delay between switching off one winding and switching on another
- Light relay follows the light button directly (momentary: hold = on)

## Changes Made for Compilation

Original line:

    if (power == ) {

changed to:

    if (power == 0) {

That is the only change. Intended behaviour, matches the state table.

## Safety

- Mains voltage is dangerous. Keep low-voltage and mains sides physically separated.
- Do not remove or shorten the 300 ms coil-switchover delay.
- Motor windings are individually fused. Refer to the physical build for specs.

## Files

- placaexaustor.ino — the archived firmware
