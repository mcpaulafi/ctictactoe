/* Set game board */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "settings.h"

void set_game(void) {
    int cell_input;
    int8_t ok = 0;
    while (ok != 1){

        printf("Enter gameboard width (3-%d): ", MAX_BOARD_WIDTH);
        
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
        cell_input < 3 ||
        cell_input > MAX_BOARD_WIDTH) {
            printf("Invalid input.\n");
            continue;
        }else{
            if(debug){printf("  Played cell: %d\n", cell_input);}
            ok = 1;
            board_width = cell_input;
            board_size = cell_input*cell_input;
            win_length = cell_input;
        }
    }
}