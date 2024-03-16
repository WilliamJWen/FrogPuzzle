#include <stdbool.h>
#include <stdio.h>

//******* Named Constants *******//
const int MAX = 11;
const int UNUSED = -1;
const int EMPTY = 0;
const int LEFT = 1;
const int RIGHT = 2;

//******* Global Variables *******//
int array[MAX] = {0};
int g_num_stones = 5;

//******* Function Declaration *******//
void clear_array();
void initialize_array(int num_stones);
void print_array();
void print_game_state();
int validate_move(int frog_to_move);
int make_move(int to_move, int move);
int get_input();
bool check_win();
bool check_lose();

int main() {
  // printf() displays the string inside quotation
  printf("Hello, World!\n");
  clear_array();
  // printf("%d \n", array[0]);
  initialize_array(g_num_stones);
  // print_array();
  // print_game_state();
  printf("This is a game in honor of Frog!\n");
  printf("You win by getting all LEFT to the right side, and vice versa\n");
  printf("You can only move foward or jump forward over one frog\n");
  printf(
      "There are four levels of the game, you are now on level one with 5 "
      "stones!\n");
  printf("Type in the number to select the frog to move!\n");
  printf("BTW, please only type the number displayed in the terminal!\n");
  printf(
      "Oh! Actually! You can type in -1 to restart game at your level in case "
      "you made a stupid move!\n");
  while (1) {
    print_game_state();
    int to_move = get_input();
    printf("You haved selected %d\n", to_move);
    if (to_move == -1) {  // mistake restart the game
      initialize_array(g_num_stones);
      continue;
    }
    int move = validate_move(to_move);
    // printf("Player move is %d\n", move);
    if (move == 0) {
      continue;  // don't make a change
    } else {
      make_move(to_move, move);
    }
    if (check_win()) {
      printf("now! try a more difficult one!\n");
      if (g_num_stones == MAX) {
        printf("You have nailed it all! \n");
        break;
      }
      g_num_stones += 2;
      initialize_array(g_num_stones);
      continue;
    } else if (check_lose()) {
      initialize_array(g_num_stones);
    }
  }
  return 0;
}

void clear_array() {
  for (int i = 0; i < MAX; i++) {
    array[i] = UNUSED;
  }
}

void initialize_array(int num_stones) {
  int num_each_side = (int)(num_stones - 1) / 2;
  for (int i = 0; i < num_each_side; i++) {
    array[i] = LEFT;
  }
  array[num_each_side] = EMPTY;
  for (int i = num_each_side + 1; i < num_stones; i++) {
    array[i] = RIGHT;
  }
}

void print_array() {
  for (int i = 0; i < MAX; i++) {
    printf("%d", array[i]);
  }
  printf("\n");
}

void print_game_state() {
  for (int i = 1; i < g_num_stones + 1; i++) {  // notice 1 and +1
    printf("%d ", i);
  }
  printf("\n");

  for (int i = 0; i < MAX; i++) {
    if (array[i] == UNUSED) {
      break;
    }
    if (array[i] == 1) {
      printf("L ");  // Left frog
    } else if (array[i] == 2) {
      printf("R ");  // Right frog
    } else {
      printf("_ ");  // Empty stone
    }
  }
  printf("\n");
}

int validate_move(int to_move) {
  to_move -= 1;  // to align user input with array
  //** assume user input will be in range, otherwise need some handler here **//
  if (array[to_move] == EMPTY) {
    // printf("This is an empty stone, can't move!\n");
    return 0;  // empty stone
  }
  if (array[to_move] == LEFT) {
    if (to_move == g_num_stones - 1) {
      // printf("Can't move, Left has jumped to the right most\n");
      return 0;
    } else if (to_move == g_num_stones - 2) {
      if (array[g_num_stones - 1] != EMPTY) {
        // printf("Can't move, Left has jumped to the second right most\n");
        return 0;
      } else {
        return 1;
      }
    }

    if (array[to_move + 1] == EMPTY) {
      return 1;  // can move one right
    } else if (array[to_move + 2] == EMPTY) {
      return 2;  // can jump two right
    } else {
      // printf("can't move\n");
      return 0;  // can't move
    }
  } else if (array[to_move] == RIGHT) {
    if (to_move == 0) {
      // printf("Can't move, Right has jumped to the left most\n");
      return 0;
    } else if (to_move == 1) {
      if (array[0] != EMPTY) {
        // printf("Can't move, Right has jumped to the second left most\n");
        return 0;
      } else {
        return -1;
      }
    }

    if (array[to_move - 1] == EMPTY) {
      return -1;  // can move one right
    } else if (array[to_move - 2] == EMPTY) {
      return -2;  // can jump two right
    } else {
      // printf("can't move\n");
      return 0;  // can't move
    }
  }
  return 0;
}

int make_move(int to_move, int move) {
  to_move -= 1;
  array[to_move + move] = array[to_move];
  array[to_move] = EMPTY;
  // printf("Made a move\n");
  return 1;
}

int get_input() {
  int number = -1;
  scanf("%d", &number);
  return number;
}

bool check_win() {
  int num_each_side = (int)(g_num_stones - 1) / 2;
  for (int i = 0; i < num_each_side; i++) {
    if (array[i] != RIGHT) return false;
  }
  if (array[num_each_side] != EMPTY) return false;
  for (int i = num_each_side + 1; i < g_num_stones; i++) {
    if (array[i] != LEFT) return false;
  }
  printf("Hey! You solved this puzzle!\n");
  return true;
}

bool check_lose() {
  for (int i = 0; i < g_num_stones; i++) {
    if (validate_move(i)) return false;
  }
  printf("you lost! Try again!\n");
  return true;
}
