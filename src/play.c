/* User inputs*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#include "../include/common.h"

int8_t parse_cell_input(const char *buf){
    int cell_input;
    char extra;

    //White space check
    if (strspn(buf, " \t\n") == strlen(buf))
        return -1;

    //Check for extra characters, spaces in between, enter
    if (sscanf(buf, "%d %c", &cell_input, &extra) != 1 ||
        cell_input < 1 ||
        cell_input > board_size) {
        if(cell_input == 0){
            return 0; // restart or end game
        }
        return -1;
    } 
    
    if (gameboard[(int8_t)cell_input-1]==1 || gameboard[(int8_t)cell_input-1]==2){
        return -2; // Cell already played
    }

    return (int8_t)(cell_input - 1); // Valid input
}

int8_t input_cell(void){
    char buf[32];
    int8_t ok = 1;
    while (ok == 1){

        printf("Player %c! Enter a cell number: ", PLAYER_NAME(player));

        //Empty inputs
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        int8_t result = parse_cell_input(buf);
        //printf("Parsed cell input: %d\n", result); // Debugging line

        if (result > 0) {
            cell = result;
            ok = 0;
            return 2; // to checker
        }
        if (result == 0) {
            printf("Exiting game...\n");
            return 0; // restart or end game
        }
        if (result == -2){
            printf("Cell is already played.\n");
            continue;
        }else{
            printf("Invalid input.\n");
            continue;
        }
    }
    return -1; //Error
}
