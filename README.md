# Frog Puzzle

## Overview

Frog Puzzle is a one-player, multi-level game where the goal is to swap two sets of frogs across a pond.  
This **embedded systems** project, written in C and tested on an FPGA, integrates **PS/2 keyboard** input, **VGA display** control with **double buffering**, and **audio** playback.

![Overview](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/10252cb1-fbec-4ee6-9bcd-ea694f2d2ff6)

## How to Run
1. Open the `FrogPuzzle.c` file in CPULator or the Intel Monitor Program.
    - Our project is combined into a single C file [FrogPuzzle.c](https://github.com/WilliamJWen/FrogPuzzle/blob/main/FrogPuzzle.c)
    - CPULator link: [CPULator Nios DE1-SoC](https://cpulator.01xz.net/?sys=nios-de1soc)

3. Game logic:
    - Frogs can only jump **forward** to an **adjacent** empty stone or **over one frog**.
    - The player controls the frogs by pressing alphanumeric keys on a PS/2 keyboard.

### Initial State:
![Initial State](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/10252cb1-fbec-4ee6-9bcd-ea694f2d2ff6)

### Win State:
![Win State](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/8036c682-3625-4564-adaf-b7f97e7828ec)

## Key Learning Outcomes

* Managed PS/2 keyboard input, learning how low-level devices communicate with the CPU and real-time hardware handling.
* Worked with VGA display control, manipulating pixels directly via memory-mapped I/O and understanding display hardware.
* Implemented double buffering to eliminate flickering and ensure smooth animations, crucial for real-time graphics.
* Gained experience in memory management, using arrays to represent game elements and handling data efficiently in a constrained system.
* Synchronized drawing with the VGA’s refresh rate using wait_for_vsync(), learning the importance of timing and CPU-peripheral synchronization.
* Integrated audio playback using the audio controller, learning basic audio signal processing.

## One Problem-Solving Scenario
- **Problem**: We encountered an issue where, after pressing a key (e.g., "3") to complete a move in one level, the game would automatically execute the same move in the next level if the move of that key is valid in the new level. This happened because the PS/2 keyboard buffer continued to store the last key press (**Input Debouncing: Buffer Overflow**).
- **Initial Idea**: Add a begin page that requires clicking SPACE to start to avoid overflowed keys are valid.
- **Final Solution**: To resolve this more robustly, we cleared the PS/2 keyboard FIFO buffer after each move to prevent lingering key presses from affecting future gameplay.
  ```c
    // Clear the PS/2 Keyboard FIFO
    int RAVAIL = 0;
    do {
        PS2_data = *(PS2_ptr);        // read the Data register in the PS/2 port
        RAVAIL = (PS2_data & 0xFFFF0000) >> 16;  // extract the RAVAIL field
    } while (RAVAIL > 0);  // Continue until FIFO is empty
  ```

## Features
- **Audio and Animation**: Integrated sound effects and frog jump animations.
- **Reset**: Press `R` to reset the game.
- **Lose State**: The game displays a lost message if no more valid moves exist. Press `R` to retry or `T` to enter Tutorial Mode.
  ![Lose State](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/844c88b7-1b4b-42a7-86b0-70c26272c800)
- **Tutorial Mode**: A guided mode with three levels to help players learn the mechanics.
    - Press `Q` to exit Tutorial Mode and return to Play Mode.
    - **Level 1**:  
      ![Tutorial Level 1](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/23b63573-afa4-4db0-a536-e2574f223363)
    - **Level 3**:  
      ![Tutorial Level 3](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/56a129f6-a099-44db-87ee-0fd868eab0b4)

## Controls
- Alphanumeric keys: Select frogs to jump.
- `R`: Reset the game.
- `T`: Enter Tutorial Mode.
- `Q`: Exit Tutorial Mode.

## Developer Attribution

| Jiahan William Wen                | Kexin (Alissa) Xiang            |
| --------------------------------- | ------------------------------- |
| - Implemented game logic in C     | - Created frog and dock graphics |
| - Managed PS/2 keyboard handling  | - Restructured double buffering  |
| - Integrated audio for jumps and game states | - Frog jump animations       |
| - Developed background drawing in C arrays | - Displayed move counts and messages |

Enjoy solving the Frog Puzzle!
