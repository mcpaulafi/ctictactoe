/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/row.h"
#include "../include/checker.h"

int8_t check_line(void){
    return 0; // mock
}

void test_extract_row(void){
    board_width = 3;
    memset(gameboard, 0, sizeof(gameboard)); //Initialize game board

    int16_t board[] = {
    1,1,0,
    0,0,0,
    0,2,0
    };

    memcpy(gameboard, board, sizeof(board));

    int8_t result = extract_row(1);
    assert(line[0] == 0);
    assert(line[1] == 0);
    assert(line[2] == 0);
    assert(result == 0);

}

void test_extract_row_invalid_indices(void){
    board_width = 3;
    assert(extract_row(-1) == -1);
    assert(extract_row(3) == -1);
    assert(extract_row(10) == -1);
}

int main(void) {
    test_extract_row();
    printf("Test to extract row passed!\n");
    test_extract_row_invalid_indices();
    printf("Test to check invalid row values passed!\n");
    printf("All tests passed!\n");
    return 0;
}
