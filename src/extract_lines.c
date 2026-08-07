/* Function to extract lines from the game board for checking */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "extract_lines.h"
#include "checker.h"


int8_t extract_lines(int8_t cell){
    if (cell <=0 || cell >= BOARD_WIDTH*BOARD_WIDTH) {
        if(debug) {printf("Invalid cell index: %d\n", cell);}
        return -1; // Invalid cell index
    }

    cell--; // Adjust for 0-based indexing
    int8_t row_idx = cell / BOARD_WIDTH;
    int8_t col_idx = cell % BOARD_WIDTH;

    if (extract_row(row_idx) == 1) {
        return 1;
    }
    else if (extract_column(col_idx) == 1) {
        return 1;
    }else {
        return 0;
    }
    //DIAGONAL DESCENDING
    //DIAGONAL ASCENDING


    return 0;
}

//Check row function
int8_t extract_row(int8_t row_idx){
    if (row_idx < 0 || row_idx >= BOARD_WIDTH) {
        if(debug) {printf("Invalid row index: %d\n", row_idx);}
        return -1; // Invalid row index
    }

    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking row: %d\n", row_idx);}
    for (int c = 0; c < BOARD_WIDTH; c++) {
        line[c] = gameboard[row_idx * BOARD_WIDTH + c];
        if (debug) {printf("Cell: %d Value: %d\n", row_idx * BOARD_WIDTH + c, line[c]);}
    }
    return check_line();
}

//Check column function
int8_t extract_column(int8_t col_idx){
    if (col_idx < 0 || col_idx >= BOARD_WIDTH) {
        if(debug) {printf("Invalid column index: %d\n", col_idx);}
        return -1; // Invalid column index
    }

    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking column: \n");}
    for (int r = 0; r < BOARD_WIDTH; r++) {
        line[r] = gameboard[r * BOARD_WIDTH + col_idx];
        if (debug) {printf("Cell: %d Value: %d\n", r * BOARD_WIDTH + col_idx, line[r]);}
    }
    return check_line();
}
