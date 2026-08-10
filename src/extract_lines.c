/* Function to extract lines from the game board for checking */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "../include/common.h"
#include "../include/row.h"
#include "../include/col.h"
#include "../include/diag_asc.h"
#include "../include/diag_desc.h"
#include "../include/extract_lines.h"
#include "../include/checker.h"
#include "../include/location.h"

int8_t tie(void){
        //Check if game is a tie
        int8_t has_empty_cell = 0;
        for (int i = 0; i < board_size; i++) {
            if (debug){printf("Empty cells? Board[%d] %d\n",i, gameboard[i]);}  
            if (gameboard[i] == 0) {
                has_empty_cell = 1;
                return 0;
            }
        }
        if (has_empty_cell == 0){
            if (debug) {printf("Game is a tie.");}
            return 1;
        }
        return -1; //error
}

int8_t extract_lines(void){
    if (cell < 0 || cell >= board_size) {
        if (debug) {printf("Extract lines: Invalid cell index: %d\n", cell);}
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
    }else if (tie()){
        return -1;
    }else {
        return 0;
    }
}
