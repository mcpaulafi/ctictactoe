
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
#include "play.h"
#include "update.h"


/* 
* Global variables, declarations in common.h
*/

int8_t debug = 0; // debug mode 0=off, 1=on
int8_t cell = 2; // cell id which was last played
int8_t win_length = 3; // amount of consecutive cells needed to win
int8_t player = 1; // current player (1 or 2)
int8_t line[BOARD_WIDTH] = {0};
int8_t gameboard[BOARD_WIDTH*BOARD_WIDTH];

/* 
* Prototypes
*/


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


/* 
*  Main function
*/
int main(void) {

    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board
    while(1){
        printf("Player %d\n", player);
        print_gameboard();
        cell = input_cell();
        int update = update_board();
        int8_t result = extract_lines();

        if (result==1) { 
            printf("Win to player: %d\n", player);
            print_gameboard();
            return 0;
        } else if (result==-1){
            printf("Error\n");
        }else { 
            printf("No win yet\n\n");
            if (player == 1) {
                player = 2;
            }else{
                player = 1;
            }
            continue;
        } 
    }
    return 0;
}

/* 
* Functions
*/
