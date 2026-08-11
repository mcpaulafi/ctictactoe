/* User prompt if new game is started */

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/common.h"

int8_t new(void){
    char cell_input;
    int ok = 1;
    while (ok == 1){

        printf("Start a new Tic-Tac-Toe game Y/N? ");
        
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
        if (sscanf(buf, "%c %c", &cell_input, &extra) != 1 ||
        (cell_input != 'Y' && cell_input != 'N' &&
        cell_input != 'y' && cell_input != 'n')) {
            printf("Invalid input.\n");
            continue;
        }else{
            if(debug){printf("  Selected: %c\n", cell_input);}
            if (cell_input == 'Y' || cell_input == 'y'){
                return 1;
            }
            return 0;
        }
    }
    return -1; //Error
}
