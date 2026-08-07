/* Function to extract lines from the game board for checking */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "extract_lines.h"
#include "checker.h"

int8_t extract_lines(int8_t cell){
    if (cell <=0 || cell >= BOARD_WIDTH*BOARD_WIDTH) {
        if(debug) {printf("Invalid cell index: %d\n", cell);}
        return -1; // Invalid cell index
    }
    int8_t line[BOARD_WIDTH] = {0};
    int8_t row_idx = cell / BOARD_WIDTH;
    int8_t col_idx = cell % BOARD_WIDTH;

    //ROW
    if (debug) {printf("Checking row: \n");}
    for (int c = 0; c < BOARD_WIDTH; c++) {
        line[c] = gameboard[row_idx * BOARD_WIDTH + c];
        if (debug) {printf("Cell: %d Value: %d\n", row_idx * BOARD_WIDTH + c, line[c]);}
    }
    if (check_line(line) == 1) {
        return 1;
    }
    //COLUMN
    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking column: \n");}
    for (int r = 0; r < BOARD_WIDTH; r++) {
        line[r] = gameboard[r * BOARD_WIDTH + (cell % BOARD_WIDTH)];
        if (debug) {printf("Cell: %d Value: %d\n", r * BOARD_WIDTH + (cell % BOARD_WIDTH), line[r]);}
    }
    if (check_line(line) == 1) {
        return 1;
    }
    //DIAGONAL DESCENDING
    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking descending diagonal: \n");}

    if (check_line(line) == 1) {
        return 1;
    }

    //DIAGONAL ASCENDING
    memset(line, 0, sizeof(line)); // Reset line array

    if (check_line(line) == 1) {
        return 1;
    }

    return 0;
}