
/**************************************
* Tic-tac-toe
* Ristinolla (fin)
* mcpaulafi 8th August 2026
**************************************/
// version 0.1

/*
* Precompiler instructions
*/
#include <stdio.h>  // RW, files
#include <inttypes.h> // Variable types int8_t
#include <string.h> 
#include <stdlib.h> // Type conversions, memo, sys commands
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
        if (player == 1) {
            player_name = 'X';
        }else{
            player_name = '0';
        }
        print_gameboard();
        cell = input_cell(); //play.c
        if (cell == -1){
            printf("***********************************\n");
            printf("*****  Tie - no wins!!!   *****\n");
            print_gameboard();
            return 0;
        }
        int update = update_board();
        int8_t result = extract_lines();

        if (result==1) {
            printf("***********************************\n");
            printf("*****  Win to player: %c !!!   *****\n", player_name);
            print_gameboard();
            return 0;
        } else if (result==-1){
            printf("Error\n");
            return 0;
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
