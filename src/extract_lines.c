/* Function to extract lines from the game board for checking */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "extract_lines.h"
#include "checker.h"
#include "location.h"

int8_t extract_lines(void){
    if (cell <=0 || cell >= BOARD_WIDTH*BOARD_WIDTH) {
        if (debug) {printf("Invalid cell index: %d\n", cell);}
        return -1; // Invalid cell index
    }

    Location location = give_location(cell); // Column, Row

    if (debug) {printf("Location: Column: %d, Row: %d\n", location.col, location.row);}

    //Check row, column, and diagonals
    if (extract_row(location.row) == 1) {
        return 1;
    }
    else if (extract_column(location.col) == 1) {
        return 1;
    }else if (extract_diagonal_descending(location.row, location.col) == 1) {
        return 1;
    }else if (extract_diagonal_ascending(location.row, location.col) == 1) {
        return 1;
    }else {
        return 0;
    }
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
    if (debug) {printf("Checking column: %d\n", col_idx);}
    for (int r = 0; r < BOARD_WIDTH; r++) {
        line[r] = gameboard[r * BOARD_WIDTH + col_idx];
        if (debug) {printf("Cell: %d Value: %d\n", r * BOARD_WIDTH + col_idx, line[r]);}
    }
    return check_line();
}

//Check diagonal descending function
int8_t extract_diagonal_descending(int8_t row_idx, int8_t col_idx){
    if (debug) {printf("Checking diagonal descending: \n");}
    memset(line, 0, sizeof(line)); // Reset line array
    int8_t start_cell;
    if (row_idx == col_idx) {
        start_cell = 0; // Top-left corner
    } else if (row_idx > col_idx) {
        start_cell = (row_idx - col_idx) * BOARD_WIDTH; // Move up to the first row
    } else {
        start_cell = col_idx - row_idx; // Move left to the first column
    }
    if (debug) {printf("Start cell: %d\n", start_cell);}

    for (int i = 0; i < BOARD_WIDTH; i++) {
        int8_t cell_idx = start_cell + i * (BOARD_WIDTH + 1);
        if (cell_idx >= BOARD_WIDTH * BOARD_WIDTH) {
            break; // Stop if we go out of bounds
        }
        line[i] = gameboard[cell_idx];
        if (debug) {printf("Cell: %d Value: %d\n", cell_idx, line[i]);}

        Location location_check = give_location(cell_idx); // Column, Row

        if (location_check.row >= BOARD_WIDTH-1 || location_check.col >= BOARD_WIDTH-1) {
            break; // Stop if we go out of the diagonal
        }
    }
    if (sizeof(line) < win_length) {
        return 0; // Diagonal line is too short to check for a win
    }
    return check_line();
}

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