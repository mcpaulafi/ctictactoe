
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
*  Main function
*/
int main(void) {
    printf("* Win with line of: %d             *\n", win_length);

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
