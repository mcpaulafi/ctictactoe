/* Update cell value */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"

int8_t update_board(void){
    gameboard[cell] = player;
    return 0;
}