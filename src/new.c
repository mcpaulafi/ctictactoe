/* User prompt if new game is started */

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/common.h"

int8_t parse_new_game(const char *buf){
    char cell_input;
    char extra;

    //White space check
    if (strspn(buf, " \t\n") == strlen(buf))
        return -1;

    //Check for extra characters, spaces in between, enter
    if (sscanf(buf, "%c %c", &cell_input, &extra) != 1)
        return -1;

    if (cell_input == 'Y' || cell_input == 'y')
        return 1;

    if (cell_input == 'N' || cell_input == 'n')
        return 0;
    return -1; 
}


int8_t new(void){
    int ok = 1;
    char buf[32];

    while (ok == 1){

        printf("Start a new Tic-Tac-Toe game Y/N? ");

        //Empty inputs
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            continue;
        }

        int8_t result = parse_new_game(buf);

        if (result != -1) {
            return result;
        }
        printf("Invalid input. Please enter 'Y' or 'N'.\n");
    }
}
