/* Common global variables */

#ifndef COMMON_H
#define COMMON_H

#include <inttypes.h>


extern int8_t debug; // debug mode (0=off, 1=on)

#define MAX_BOARD_WIDTH 10 // Reserve max size for board
#define MAX_BOARD_SIZE (MAX_BOARD_WIDTH * MAX_BOARD_WIDTH)
extern int8_t board_width; //Size during the game
extern int16_t board_size;

extern int8_t cell; // cell id which was last played
extern int8_t win_length; // amount of consecutive cells needed to win
extern int8_t line[MAX_BOARD_WIDTH]; // array to hold the extracted line for checking
extern int8_t player; // current player (1=X and 2=O)
extern char player_name;
extern int16_t gameboard[MAX_BOARD_SIZE]; //Played cell values, id:s 0-max_width-1

typedef struct {
    int8_t col;
    int8_t row;
} Location;

#endif