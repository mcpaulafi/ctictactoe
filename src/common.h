/* Common variables */

#ifndef COMMON_H
#define COMMON_H

#include <inttypes.h>

#define BOARD_WIDTH 10

extern int8_t debug; // debug mode 0=off, 1=on
extern int8_t cell; // cell id which was last played
extern int8_t win_length; // amount of consecutive cells needed to win
extern int8_t line[BOARD_WIDTH]; // array to hold the extracted line for checking
extern int8_t player; // current player (1 or 2)

//Test gameboard for testing the functions
extern int8_t gameboard[100];

typedef struct {
    int8_t col;
    int8_t row;
} Location;

#endif