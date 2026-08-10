/* Function to extract lines from the game board for checking */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "../include/common.h"
#include "../include/extract_lines.h"
#include "../include/location.h"

Location give_location(int8_t localcell){
    Location invalid_location = {-1, -1};

    if(debug) {printf("Local cell: %d\n", localcell);}
    if (localcell <0 || localcell >= board_size) {
        if(debug) {printf("Invalid cell index: %d\n", localcell);}
        return invalid_location; // Invalid cell index
    }
    Location loc = {
        .col = localcell % board_width,
        .row = localcell / board_width
    };

    if (loc.col < 0 || loc.row < 0) {
        if(debug) {printf("Invalid location for cell index: %d\n", localcell);}
        return invalid_location; // Invalid location
    }
    
    return loc;
}
