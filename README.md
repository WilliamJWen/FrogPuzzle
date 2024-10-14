# Project Frog Puzzle
Jiahan William Wen 1007956650 <br>
Kexin (Alissa) Xiang 1008140094 <br>
## How to operate our project

1. Open FrogPuzzle.c in CPULator or Intel Monitor Program
    - Our project is combined into a single C file: FrogPuzzle.c
    - CPULator: https://cpulator.01xz.net/?sys=nios-de1soc
2. Game Logic:
    - This is a one player game.
    - The goal is to swapped sides of the two sets of frogs. As pictures show below.
    - Initial State ![image](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/10252cb1-fbec-4ee6-9bcd-ea694f2d2ff6)  Win State ![image](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/8036c682-3625-4564-adaf-b7f97e7828ec)
    - A frog can move by jumping **forward** to an **adjacent** empty stone, or jumping **forward** and **over only one** frog.
    - Player can control a numbered frog to jump by clicking on the corresponding PS/2 Keyboard alphanumeric keys.
3. Features
    1. Well-integrated **Audio** and Animation
    2. Click R to reset the game **whenever** user thinks a mistake was made.
    3. When user enter a state no move can be make, the game enters Lose Page. <br>
        ![image](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/844c88b7-1b4b-42a7-86b0-70c26272c800)
        -  User can then Retry also by clicking R
        -  Or Enter **Tutorial Mode** by clicking T
    4. Tutorial mode
         - Tutroial mode has **three** levels
         - Level 1 ![image](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/23b63573-afa4-4db0-a536-e2574f223363) Level 3 ![image](https://github.com/WilliamJWen/FrogPuzzle/assets/103137385/56a129f6-a099-44db-87ee-0fd868eab0b4)
         - Player can go back to Play Mode by clicking Q after beating any level of Tutorial mode

## Attribution Table 
| Jiahan William Wen:      | Kexin (Alissa) Xiang:  |
|-----------|-------------|
| <ul><li>Build Game Logic in C using terminal I/O </li> <li> Convert .png to C array and draw Background</li>  <li>Handle PS2 Keyboard (clear FIFO buffer) </li> <li>Convert .mp3 to C array and implemented Audio</li> </ul> |  <ul><li>Draw static frog and labeled stones </li> <li>Restructured to Double Buffering </li><li>Frog Jump Animation</li> <li>Display Messages for each game state</li> <li>Display move counts for each move</li> </ul>   |
