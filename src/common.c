/* Init of common variables */
#include <inttypes.h>
#include "common.h"

//Settings for start
int8_t debug = 0; // debug mode 0=off, 1=on
int8_t board_width = 3;
int16_t board_size = 9;
int8_t cell = -1; // cell id which was last played
int8_t win_length = 3; // amount of consecutive cells needed to win
int8_t player = 1; // current player (1 or 2)
int8_t line[MAX_BOARD_WIDTH] = {0};
int16_t gameboard[MAX_BOARD_SIZE];
