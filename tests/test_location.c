/* Unit test for location */
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/location.h"

void test_get_location_first_cell(void){
    board_width = 3;
    board_size = 9;
    Location loc = give_location(0);
    assert(loc.row == 0);
    assert(loc.col == 0);
}

void test_get_location_negative_index(void){
    board_width = 4;
    board_size = 16;
    Location loc = give_location(-1);
    assert(loc.row == -1);
    assert(loc.col == -1);
}

void test_get_location_index_past_board_size(void){
    board_width = 3;
    board_size = 9;
    Location loc = give_location(10);
    assert(loc.row == -1);
    assert(loc.col == -1);
}

int main(void) {
    test_get_location_first_cell();
    printf("Test to get location of first cell passed!\n");
    test_get_location_negative_index();
    printf("Test to get location of negative index passed!\n");
    test_get_location_index_past_board_size();
    printf("Test to get location of index past board size passed!\n");
    printf("All tests passed!\n");

    return 0;
}
