
/**************************************
* Tic-tac-toe
* Ristinolla (fin)
* mcpaulafi 10th August 2026
**************************************/
// version 0.1

#include <stdio.h>  // RW, files
#include <inttypes.h> // Variable types int8_t
#include <string.h> 
#include <stdlib.h> // Type conversions, memo, sys commands
//#include <math.h> add -lm option to linker

#include "common.h"
#include "settings.h"
#include "extract_lines.h"
#include "print.h"
#include "play.h"
#include "update.h"

int main(void) {
    //printf("* Win with line of: %d             *\n", win_length);
    set_game();
    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board
    while(1){
        char player_name = PLAYER_NAME(player);

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
