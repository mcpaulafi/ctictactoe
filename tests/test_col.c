/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/common.h"
#include "../src/col.h"
#include "../src/checker.h"

int8_t check_line(void){
    return 0; // mock
}

void test_extract_column(void){
    board_width = 3;
    board_size = 9;
    win_length = 3; 
    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,1,0,
    0,0,0,
    0,2,0
    };

    memcpy(gameboard, board, sizeof(board));

    int8_t result = extract_column(1);
    assert(line[0] == 1);
    assert(line[1] == 0);
    assert(line[2] == 2);
    assert(result == 0);
}

int main(void) {
    test_extract_column();
    printf("All tests passed!\n");
    return 0;
}