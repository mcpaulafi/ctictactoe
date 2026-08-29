/* Unit test for ascending diagonal check */

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/location.h"
#include "../include/diag_asc.h"


int8_t check_line(void){
    return 0; // mock
}

void test_extract_diagonal_ascending(void){
    board_width = 3;
    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,1,2,
    0,2,0,
    1,2,0
    };

    memcpy(gameboard, board, sizeof(board));

    int8_t result = extract_diagonal_ascending(2,0);

    for (int i = 0; i < MAX_BOARD_WIDTH; i++) {
        if (debug) {printf("  Add line: %d\n", line[i]);}
    }


    assert(line[0] == 2);
    assert(line[1] == 2);
    assert(line[2] == 1);
    assert(result == 0);

}

void test_extract_diagonal_ascending_invalid_indices(void){
    board_width = 3;
    assert(extract_diagonal_ascending(0,-1) == -1);
    assert(extract_diagonal_ascending(0,3) == -1);
    assert(extract_diagonal_ascending(10,0) == -1);
}

int main(void) {
    test_extract_diagonal_ascending();
    printf("Test to extract diagonal ascending passed!\n");
    test_extract_diagonal_ascending_invalid_indices();
    printf("Test to check invalid column values passed!\n");
    printf("All tests passed!\n");
    return 0;
}
