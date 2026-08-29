/* Function to extract diagonal ascending of the cell */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "../include/common.h"
#include "../include/diag_asc.h"
#include "../include/checker.h"
#include "../include/location.h"


//Check diagonal ascending function
int8_t extract_diagonal_ascending(int8_t row_idx, int8_t col_idx){
    if (debug) {printf("Checking diagonal ascending: row %d col %d\n", row_idx, col_idx);}
    memset(line, 0, sizeof(line)); // Reset line array
    int8_t start_cell;
    if (row_idx < 0 || col_idx<0 || row_idx >= board_width || col_idx >= board_width){
        if (debug) {printf("Checking diagonal ascending: invalid row or column\n");}
        return -1;
    }
    if (row_idx + col_idx < board_width) {
        start_cell = row_idx + col_idx; // Move up to the first row
    } else { //Move down to the last column
        for (int i=0;i<board_width;i++){
            row_idx -= 1;
            col_idx += 1;
            if (col_idx == board_width-1){
                start_cell = (row_idx+1)*(col_idx+1)-1; 
            }
        }
    }
    if (debug) {printf("Start cell: %d\n", start_cell);}

    int8_t cell_idx = start_cell;
    for (int i = 0; i < board_width; i++) {
        if (debug) {printf("  Add line Cell: %d Value: %d\n", cell_idx, line[i]);}

        line[i] = gameboard[cell_idx];

        Location location_check = give_location(cell_idx); // Column, Row

        if (location_check.row > board_width || location_check.col <= 0) {
            break; // Stop if we go out of the diagonal
        }

        cell_idx += (board_width - 1); // One row down

        if (cell_idx >= board_size) {
            break; // Stop if we go out of bounds
        }


    }
    if (sizeof(line) < (size_t)win_length) {
        return 0; // Diagonal line is too short to check for a win
    }
    return check_line();

}
