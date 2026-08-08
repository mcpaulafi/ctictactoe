/* Init of common variables */
#include <inttypes.h>
#include "common.h"


int8_t debug = 0; // debug mode 0=off, 1=on
int8_t cell = 2; // cell id which was last played
int8_t win_length = 3; // amount of consecutive cells needed to win
int8_t player = 1; // current player (1 or 2)
int8_t line[BOARD_WIDTH] = {0};
int8_t gameboard[BOARD_WIDTH*BOARD_WIDTH];
