# Controlling Snake with an Arduino Controller

This folder contains two versions of the classic game "Snake" written in Processing 3.

<br>

## Snake Standalone

Processing code: [Snake_Standalone](Snake_Standalone)

Play Snake with the keyboard:
| key | action |
|---|---|
| `w` | up |
| `a` | left |
| `s` | down |
| `d` | right |
| `r` | reset |
| `o` | speed down |
| `p` | speed up | 

<br>

## Snake Serial

Processing code: [Snake_Serial](Snake_Serial)

This Processing sketch listens for commands coming over the serial port connected to the Arduino controller. First, look at `line 3` of the code:

```
int serial_port_index = 0;
```
1. Connect the Arduino to the computer.
1. Run the Processing sketch. When it runs, stop it immediately.
1. Look at Processing's console (the black text rectangle at the bottom of the Processing IDE). It should list the different ports in order.
1. The first port in that list has the index `0`, followed by `1` and so forth.
1. Change the value of `serial_port_index` to match the port corresponding to the Arduino. (Still not sure which is the Arduino? Check the serial port list in the Arduino IDE. Or, unplug the Arduino and run the Processing sketch and see which port disappears).

The Arduino microcontroller controls the Snake game in Processing by sending text commands over the serial port, with the `Serial.println("text command")` function. List of text commands:

| text command | action |
|---|---|
| `"1"` | up |
| `"2"` | left |
| `"3"` | down |
| `"4"` | right |
| `"5"` | reset |
| `"6"` | speed down |
| `"7"` | speed up | 

Here is an [example Arduino code](Snake_Arduino) that listens to the state of 5 push buttons and sends a different text command over serial depending on which button is pressed.