/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/common.h"
#include "../src/col.h"
#include "../src/checker.h"

int8_t debug = 0; // debug mode 0=off, 1=on
int8_t cell = 2; // cell id which was last played
int8_t win_length = 3; // amount of consecutive cells needed to win
int8_t player = 1; // current player (1 or 2)
int8_t line[BOARD_WIDTH] = {0};
int8_t gameboard[BOARD_WIDTH*BOARD_WIDTH];

int8_t check_line(void){
    return 0; // mock
}

void test_extract_column(void){
    int8_t board[] = {
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