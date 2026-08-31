/* Unit test for extract lines */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/extract_lines.h"
#include "../include/location.h"

int8_t extract_row(void){
    return 0; // mock
}

int8_t extract_column(void){
    return 1; // mock
}

int8_t extract_diagonal_descending(void){
    return 0; // mock
}

int8_t extract_diagonal_ascending(void){
    return 0; // mock
}


void test_tie_not(void){
    board_width = 3;

    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,1,0,
    0,0,0,
    0,2,0
    };

    memcpy(gameboard, board, sizeof(board));

    int8_t result = tie();

    assert(result == 0);

}

void test_tie_yes(void){
    board_width = 3;
    board_size = 9;

    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,2,1,
    2,1,2,
    2,1,2
    };

    memcpy(gameboard, board, sizeof(board));

    int8_t result = tie();

    assert(result == 1);

}

void test_extract_lines(void){
    board_width = 3;
    board_size = 9;
    win_length = 3;
    player = 1;
    cell = 0;

    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,0,1,
    0,0,0,
    0,2,0
    };

    memcpy(gameboard, board, sizeof(board));

    int8_t result = extract_lines();

    assert(result == 1);

}



int main(void) {
    test_tie_not();
    printf("Test to no tie passed!\n");
    test_tie_yes();
    printf("Test to tie passed!\n");
    test_extract_lines();
    printf("Test to checker in case of win passed!\n");
    printf("All tests passed!\n");
    return 0;
}
