/* User inputs*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

int8_t input_cell(void){
    int cell_input;
    int8_t ok = 0;
    int8_t has_empty_cell = 0;
    while (ok != 1){

        //Check if game is a tie
        for (int i = 0; i < board_size; i++) {
            if (debug){printf("Board[%d] %d\n",i, gameboard[i]);}  
            if (gameboard[i] == 0) {
                has_empty_cell = 1;
                break;
            }
        }
        if (has_empty_cell == 0){
            if (debug) {printf("Game is a tie.");}
            return -1;
        }
        if (debug){printf("Empty cell found: %d\n",has_empty_cell);}

        has_empty_cell = 0;

        printf("Player %c! Enter a cell number: ", player_name);
        
        char buf[32];
        char extra;

        //Empty inputs
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        //White space inputs
        if (strspn(buf, " \t\n") == strlen(buf)) {
            printf("Empty input.\n");
            continue;
        }


        //Extra characters, spaces in between, enter
        if (sscanf(buf, "%d %c", &cell_input, &extra) != 1 ||
        cell_input < 1 ||
        cell_input > board_size) {
            printf("Invalid input.\n");
            continue;
        }else if (gameboard[(int8_t)cell_input-1]==1 || gameboard[(int8_t)cell_input-1]==2){
            printf("Cell is already played.\n");
        }else{
            if(debug){printf("  Played cell: %d\n", cell_input);}
            ok = 1;
            return (int8_t)cell_input-1; //User gives values from 1 to width, board is 0 to w-1
        }
    }
}
