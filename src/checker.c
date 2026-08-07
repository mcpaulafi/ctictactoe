/* Checker functions implementation*/
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "checker.h"


int8_t check_line(int8_t line[BOARD_WIDTH]){
    if (line == NULL) {
        if (debug) {printf("Line array is NULL\n");}
        return -1; // Invalid line array
    }
    int8_t counter = 0;
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (line[i] != line[cell]) {
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
    if (debug) {printf("No winner found\n");}
    return 0; // No winner
}
