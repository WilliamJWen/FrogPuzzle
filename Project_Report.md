# How to operate our project

1. Open FrogPuzzle.c in CPULator or Intel Monitor Program
    - Our project is combined into a single C file: FrogPuzzle.c
    - CPULator: https://cpulator.01xz.net/?sys=nios-de1soc
  
    - 
We use PS2 Keyboard to operate the entire game. Spave
We use double buffering and have different layers of drawings, we first draw background, and then frogs and stones, then drawing the numbers on top of the docks.
The number corresponds to the PS/2 Keyboard, player can click the corresponding number on ps/2 keyboard to select a frog to perform a move/jump.
The player is only able to select a frog to jump forward to an adjacent empty stone, or jump over only one frog to the empty stone, and the goal is to swap the sides of the two sets of three frogs.
This is controlled by a validate move function to determine if the frog user selected is valid.
And each jump has an animation accompanied with an jump audio. By writing to the VGA controller using double buffering (that is frawing and erasing frogs two buffers ago and we used line estimation of a parabola) while writing to the audio output fifo.

And when there's no frog that can move, a lost music will play with a message. At this state use can click T to enter tutorial mode, which has three level of this game, start with a smaller case so that user can get a handle of, and end with a hard case with 8 frogs to challenge the player. This is implemented by factoring out the entire game logic into a helper function.

Also, we count display the number of steps the player took on the left corner, so player can have a sense how far they went or enable player to figure out the optimal solution.
Another thing is, user can always reset the current level by pressng R at anytime, this is done by continuously polling for R/

We also handled ps2/keyboard buffer overflowing by clearing keyboard buffer every time a valid move is made. 


This is a one player game, where the goal is to 
2. When you lose and get stuck

CPULator
# Attribution Table 
that indicates what fraction of the workeach partner did, with a short description of what work each partner performed. 
| Jiahan William Wen:      | Kexin (Alissa) Xiang:  |
|-----------|-------------|
| <ul><li>Build Game Logic in C using terminal I/O </li> <li>Draw Background</li> <li>Handle PS2 Keyboard (clear FIFO buffer) </li> <li>Audio</li> </ul> |  <ul><li>Draw static frog and labeled stones </li> <li>Restructured to Double Buffering </li><li>Frog Jump Animation</li> <li>Display Messages for each game state</li> <li>Display move counts for each move</li> </ul>   |

