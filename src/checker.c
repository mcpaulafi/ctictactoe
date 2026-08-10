/* Checker implementation*/
// Calculates consecutive cells in a line and checks for a winner
#include <stdio.h>
#include <inttypes.h>

#include "../include/common.h"
#include "../include/checker.h"


int8_t check_line(void){
    int8_t counter = 0;
    for (int i = 0; i < board_width; i++) { // Go through indexes
        if (line[i] != player) { // Cell with other players value
            counter = 0; 
        } else {
            if (line[i] != 0) { // Only count non-zero values
                counter++;
            }
            if (counter == win_length) { // Player has line of win_lenght
                if (debug) {printf("Winner found at index %d\n", i);}
                return 1; // Winner found
            }
        }
    }
    if (debug) {printf("No winner found on the checked line\n");}
    return 0; // No winner
}
