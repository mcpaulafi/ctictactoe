
/**************************************
* Ristinolla
* Tic-tac-toe
* mcpaulafi 6.8.2026
**************************************/
// version 0.1

/*
* Precompiler instructions
*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h> add -lm option to linker
/* 
* Include my own libraries
*/
#include "common.h"
//#include "check_win.h"
//#include "extract_lines.h"

/* 
* Global variables
*/
int8_t debug = 1; // debug mode 0=off, 1=on
int8_t board_width = BOARD_WIDTH; // amount of cells in a row/column of the gameboard
int8_t cell = 1; // cell id which was last played
int8_t win_length = 4; // amount of consecutive cells needed to win

/* 
* Prototypes
*/
int8_t extract_lines(int8_t cell);
int8_t check_line(int8_t line[BOARD_WIDTH]);

//Test gameboard for testing the functions
int8_t gameboard[100] = {
    2,2,1,1,1,0,1,2,2,2,
    1,1,2,0,0,0,0,0,2,2,
    1,0,0,2,0,0,0,2,0,2,
    1,0,0,0,2,0,2,0,0,2,
    1,0,0,0,0,2,0,0,0,2,
    1,0,0,0,2,0,0,0,0,2,
    2,2,2,2,0,0,0,2,2,2,
    1,0,2,0,0,0,0,2,0,2,
    1,2,0,0,0,0,2,0,0,2,
    2,1,1,1,1,1,1,1,1,1
    };

    //  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    // 10,11,12,13,14,15,16,17,18,19,
    // 20,21,22,23,24,25,26,27,28,29,
    // 30,31,32,33,34,35,36,37,38,39,
    // 40,41,42,43,44,45,46,47,48,49,
    // 50,51,52,53,54,55,56,57,58,59,
    // 60,61,62,63,64,65,66,67,68,69,
    // 70,71,72,73,74,75,76,77,78,79,
    // 80,81,82,83,84,85,86,87,88,89,
    // 90,91,92,93,94,95,96,97,98,99

/* 
*  Main function
*/
int8_t main() {

    int8_t result = extract_lines(cell);

    if (result==1) { 
        printf("Win to player: %d\n", gameboard[cell]); 
    }else { 
        printf("No win yet\n"); 
    } 

    return 0;
}

/* 
* Functions
*/


int8_t extract_lines(int8_t cell){
    if (cell <=0 || cell >= BOARD_WIDTH*BOARD_WIDTH) {
        if(debug) {printf("Invalid cell index: %d\n", cell);}
        return -1; // Invalid cell index
    }
    int8_t line[BOARD_WIDTH] = {0};
    int8_t row_idx = cell / BOARD_WIDTH;
    int8_t col_idx = cell % BOARD_WIDTH;

    //ROW
    if (debug) {printf("Checking row: \n");}
    for (int c = 0; c < BOARD_WIDTH; c++) {
        line[c] = gameboard[row_idx * BOARD_WIDTH + c];
        if (debug) {printf("Cell: %d Value: %d\n", row_idx * BOARD_WIDTH + c, line[c]);}
    }
    if (check_line(line) == 1) {
        return 1;
    }
    //COLUMN
    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking column: \n");}
    for (int r = 0; r < BOARD_WIDTH; r++) {
        line[r] = gameboard[r * BOARD_WIDTH + (cell % BOARD_WIDTH)];
        if (debug) {printf("Cell: %d Value: %d\n", r * BOARD_WIDTH + (cell % BOARD_WIDTH), line[r]);}
    }
    if (check_line(line) == 1) {
        return 1;
    }
    //DIAGONAL DESCENDING
    memset(line, 0, sizeof(line)); // Reset line array
    if (debug) {printf("Checking descending diagonal: \n");}

    if (check_line(line) == 1) {
        return 1;
    }

    //DIAGONAL ASCENDING
    memset(line, 0, sizeof(line)); // Reset line array

    if (check_line(line) == 1) {
        return 1;
    }

    return 0;
}

int8_t check_line(int8_t line[BOARD_WIDTH]){
    if (line == NULL) {
        if (debug) {printf("Line array is NULL\n");}
        return -1; // Invalid line array
    }
    int8_t counter = 0;
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (line[i] != line[cell]) {
            counter = 0; 
        } else {
            if (line[i] != 0) { // Only count non-zero values
                counter++;
            }
            if (counter == win_length) {
                if (debug) {printf("Winner found at index %d\n", i);}
                return 1; // Winner found
            }
        }
    }
    if (debug) {printf("No winner found\n");}
    return 0; // No winner
}
