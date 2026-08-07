/* Common variables */

#ifndef COMMON_H
#define COMMON_H

#include <inttypes.h>

extern int8_t debug; // debug mode 0=off, 1=on
extern int8_t board_width; // amount of cells in a row/column of the gameboard
extern int8_t cell; // cell id which was last played
extern int8_t win_length; // amount of consecutive cells needed to win

#define BOARD_WIDTH 10 

#endif