/* Function to extract lines from the game board for checking */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "extract_lines.h"
#include "location.h"

Location give_location(int8_t localcell){
    if (localcell <=0 || localcell >= BOARD_WIDTH*BOARD_WIDTH) {
        if(debug) {printf("Invalid cell index: %d\n", localcell);}
        Location invalid_location = {-1, -1};
        return invalid_location; // Invalid cell index
    }
    Location loc = {
        .col = localcell % BOARD_WIDTH,
        .row = localcell / BOARD_WIDTH
    };
    return loc;
}
