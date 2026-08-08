/* Function to extract lines from the game board for checking */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "row.h"
#include "col.h"
#include "diag_asc.h"
#include "diag_desc.h"
#include "extract_lines.h"
#include "checker.h"
#include "location.h"

int8_t extract_lines(void){
    if (cell <=1 || cell >= BOARD_WIDTH*BOARD_WIDTH+1) {
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
