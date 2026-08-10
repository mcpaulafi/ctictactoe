/* Update cell value */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "../include/common.h"

int8_t update_board(void){
    if (debug) {printf("Update board[%d]\n", cell);}
    //TODO: Error handling
    gameboard[cell] = player;
    return 3; //Check result
}