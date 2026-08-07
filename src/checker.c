/* Checker functions implementation*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "extract_lines.h"
#include "checker.h"


int8_t check_line(void){
    int8_t counter = 0;
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (line[i] != player) {
            counter = 0; 
        } else {
            if (line[i] != 0) { // Only count non-zero values
                counter++;
            }
            if (counter == win_length) {
                if (debug) {printf("Winner found at index %d\n", i);}
                return 1; // Winner found
            }
        }
    }
    if (debug) {printf("No winner found on the checked line\n");}
    return 0; // No winner
}
