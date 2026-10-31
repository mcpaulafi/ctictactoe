/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/update.h"


void test_update_board(void){
    board_width = 3;
    board_size = 9;
    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,1,0,
    0,0,0,
    0,2,0
    };

    memcpy(gameboard, board, sizeof(board));
    player=2; // Set player to 2
    cell = 2; // Set cell to update

    assert(update_board() == 3); // Check if update_board returns 3
    assert(gameboard[cell] == player); // Check if the cell is updated correctly
}

void test_update_board_invalid(void){
    board_width = 3;
    board_size = 9;
    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,1,0,
    0,0,0,
    0,2,0
    };

    memcpy(gameboard, board, sizeof(board));
    player=2; // Set player to 2
    cell = 12; // Set cell to update

    assert(update_board() == -1); // Check if update_board returns 3
}


int main(void) {
    test_update_board();
    printf("Test to update board passed!\n");
    test_update_board_invalid();
    printf("Test to update board invalid passed!\n");
    return 0;
}
