/* User inputs*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#include "../include/common.h"

int8_t input_cell(void){
    int cell_input;
    int ok = 1;
    while (ok == 1){

        printf("Player %c! Enter a cell number: ", PLAYER_NAME(player));
        
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
            continue;
        }else{
            if(debug){printf("  Played cell: %d\n", cell_input);}
            cell = (int8_t)cell_input-1; //User gives values from 1 to width, board is 0 to w-1
            ok = 0;
            return 2; // Checker
        }
    }
    return -1; //Error
}
