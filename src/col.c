/* Function to extract column of the cell */
#include <stdio.h>
#include <inttypes.h>
#include <string.h> //memset

#include "../include/common.h"
#include "../include/col.h"
#include "../include/checker.h"

int8_t extract_column(int8_t col_idx){
    // Check that column index is valid
    if (col_idx < 0 || col_idx >= board_width) {
        if(debug) {printf("Invalid column index: %d\n", col_idx);}
        return -1; // Invalid column index
    }

    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking column: %d\n", col_idx);}
    // Pick all cells of the column to the line variable
    for (int r = 0; r < board_width; r++) {
        line[r] = gameboard[r * board_width+ col_idx];
        if (debug) {printf("  Cell: %d Value: %d\n", r * board_width + col_idx, line[r]);}
    }
    return check_line();
}
