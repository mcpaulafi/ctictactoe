/* Init of common global variables */
#include <inttypes.h>
#include "common.h"

//Settings for start
int8_t debug = 0; // debug mode 0=off, 1=on
int8_t board_width = 4;
int16_t board_size = 16;
int8_t cell = -1; // cell id which was last played
int8_t win_length = 4; // amount of consecutive cells needed to win
int8_t player = 1; // current player (1 or 2)
char player_name = 'X';
int8_t line[MAX_BOARD_WIDTH] = {0};  //Reserve max
int16_t gameboard[MAX_BOARD_SIZE]; 
