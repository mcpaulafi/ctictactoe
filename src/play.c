/* User inputs*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

int8_t input_cell(void){
    int cell;
    int8_t ok = 0;
    while (ok != 1){
        printf("Player %d, Enter a cell number: ", player);
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
        if (sscanf(buf, "%d %c", &cell, &extra) != 1 ||
        cell < 1 ||
        cell > BOARD_WIDTH * BOARD_WIDTH) {
            printf("Invalid input.\n");
            continue;
        }else if (gameboard[(int8_t)cell]==1 || gameboard[(int8_t)cell]==2){
            printf("Cell is already played.\n");
        }else{
            ok = 1;
            return (int8_t)cell;
        }
    }
}