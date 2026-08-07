/* Function to extract row of the cell */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "extract_row.h"
#include "extract_lines.h"
#include "checker.h"

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