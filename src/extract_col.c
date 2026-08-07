/* Function to extract column of the cell */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "extract_col.h"
#include "checker.h"

int8_t extract_column(int8_t col_idx){
    if (col_idx < 0 || col_idx >= BOARD_WIDTH) {
        if(debug) {printf("Invalid column index: %d\n", col_idx);}
        return -1; // Invalid column index
    }

    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking column: %d\n", col_idx);}
    for (int r = 0; r < BOARD_WIDTH; r++) {
        line[r] = gameboard[r * BOARD_WIDTH + col_idx];
        if (debug) {printf("Cell: %d Value: %d\n", r * BOARD_WIDTH + col_idx, line[r]);}
    }
    return check_line();
}
