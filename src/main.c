
/**************************************
* Tic-tac-toe
* Ristinolla (fin)
* mcpaulafi 8th August 2026
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
#include "extract_lines.h"
#include "print.h"


/* 
* Global variables, declarations in common.h
*/

int8_t debug = 1; // debug mode 0=off, 1=on
int8_t player = 1; // current player (1 or 2)
int8_t cell = 2; // cell id which was last played
int8_t win_length = 3; // amount of consecutive cells needed to win
int8_t line[BOARD_WIDTH] = {0};

/* 
* Prototypes
*/
int8_t gameboard[9] = {
    0,0,0,
    0,0,0,
    0,0,0
};

//  int8_t gameboard[100] = {
//     2,2,1,1,1,0,1,2,2,2,
//     1,1,2,0,0,0,0,0,2,2,
//     1,0,0,2,0,0,0,2,0,2,
//     1,0,0,0,2,0,2,0,0,2,
//     0,0,0,0,0,2,0,0,0,2,
//     1,0,0,0,2,0,0,0,0,2,
//     2,2,2,2,0,0,0,2,2,2,
//     1,0,2,0,0,0,0,2,0,2,
//     1,1,0,0,0,0,2,0,0,2,
//     2,1,1,0,1,1,1,0,1,1
//     };

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

    print_gameboard();
    int8_t result = extract_lines();

    if (result==1) { 
        printf("Win to player: %d\n", player);
    } else if (result==-1){
        printf("Error\n");
    }else { 
        printf("No win yet\n");
    } 

    return 0;
}

/* 
* Functions
*/
