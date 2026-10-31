/* Update cell value */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "../include/common.h"

int8_t update_board(void){
    if (debug) {printf("Update board[%d]\n", cell);}
    if(cell>=board_size || cell<0){
        //printf("Invalid cell index: %d\n", cell);
        return -1;
    }
    //printf("Cell index: %d Board size: %d\n", cell, board_size);

    gameboard[cell] = player;
    return 3; //Check result
}