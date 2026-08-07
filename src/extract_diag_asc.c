/* Function to extract diagonal ascending of the cell */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "extract_diag_asc.h"
#include "checker.h"
#include "location.h"


//Check diagonal ascending function
int8_t extract_diagonal_ascending(int8_t row_idx, int8_t col_idx){
    if (debug) {printf("Checking diagonal ascending: %d %d\n", row_idx, col_idx);}
    memset(line, 0, sizeof(line)); // Reset line array
    int8_t start_cell;
    if (row_idx + col_idx <= BOARD_WIDTH) {
        start_cell = row_idx + col_idx; // Move up to the first row
    } else {
        int8_t start_row = (row_idx - ((BOARD_WIDTH - 1) - col_idx)); //Move down to the last column
        printf("Start row: %d\n", start_row);
        start_cell = BOARD_WIDTH * (start_row + 1)-1; // Move down to the last row
    }
    if (debug) {printf("Start cell: %d\n", start_cell);}

    int8_t cell_idx = start_cell;
    for (int i = 0; i < BOARD_WIDTH; i++) {
        line[i] = gameboard[cell_idx];
        if (debug) {printf("Cell: %d Value: %d\n", cell_idx, line[i]);}

        cell_idx += (BOARD_WIDTH - 1);
        if (cell_idx >= BOARD_WIDTH * BOARD_WIDTH) {
            break; // Stop if we go out of bounds
        }

        Location location_check = give_location(cell_idx); // Column, Row

        if (location_check.row >= BOARD_WIDTH || location_check.col < 0) {
            break; // Stop if we go out of the diagonal
        }
    }
    if (sizeof(line) < win_length) {
        return 0; // Diagonal line is too short to check for a win
    }
    return check_line();

}
