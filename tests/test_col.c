/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/col.h"

int8_t check_line(void){
    return 0; // mock
}

void test_extract_column(void){
    board_width = 3;
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

void test_extract_column_invalid_indices(void){
    board_width = 3;
    assert(extract_column(-1) == -1);
    assert(extract_column(3) == -1);
    assert(extract_column(10) == -1);
}

int main(void) {
    test_extract_column();
    printf("Test to extract column passed!\n");
    test_extract_column_invalid_indices();
    printf("Test to check invalid column values passed!\n");
    printf("All tests passed!\n");
    return 0;
}
