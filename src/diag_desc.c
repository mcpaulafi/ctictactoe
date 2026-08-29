/* Function to extract diagonal ascending of the cell */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "../include/common.h"
#include "../include/diag_desc.h"
#include "../include/checker.h"
#include "../include/location.h"

int8_t extract_diagonal_descending(int8_t row_idx, int8_t col_idx){
    if (debug) {printf("Checking diagonal descending: \n");}
    memset(line, 0, sizeof(line)); // Reset line array
    if (row_idx < 0 || col_idx<0 || row_idx >= board_width || col_idx >= board_width){
        if (debug) {printf("Checking diagonal descending: invalid row or column\n");}
        return -1;
    }
    int8_t start_cell;
    if (row_idx == col_idx) {
        start_cell = 0; // Top-left corner
    } else if (row_idx > col_idx) {
        start_cell = (row_idx - col_idx) * board_width; // Move up to the first row
    } else {
        start_cell = col_idx - row_idx; // Move left to the first column
    }
    if (debug) {printf("Start cell: %d\n", start_cell);}

    for (int i = 0; i < board_width; i++) {
        int8_t cell_idx = start_cell + i * (board_width + 1);
        if (cell_idx >= board_size) {
            break; // Stop if we go out of bounds
        }
        line[i] = gameboard[cell_idx];
        if (debug) {printf("  Cell: %d Value: %d\n", cell_idx, line[i]);}

        Location location_check = give_location(cell_idx); // Column, Row

        if (location_check.row >= board_width-1 || location_check.col >= board_width-1) {
            
            break; // Stop if we go out of the diagonal
        }
    }
    if (sizeof(line) < (size_t)win_length) {
        return 0; // Diagonal line is too short to check for a win
    }
    return check_line();
}