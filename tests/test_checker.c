/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/checker.h"


void test_check_line(void){
    board_width = 3;
    win_length = 3;

    int8_t linetest[3] = {0,1,2};

    memcpy(line, linetest, sizeof(linetest));

    int8_t result = check_line();

    assert(line[0] == 0);
    assert(line[1] == 1);
    assert(line[2] == 2);
    assert(result == 0);

}

void test_check_line_win(void){
    board_width = 3;
    win_length = 3;

    int8_t linetest[3] = {1,1,1};

    memcpy(line, linetest, sizeof(linetest));

    int8_t result = check_line();

    assert(line[0] == 1);
    assert(line[1] == 1);
    assert(line[2] == 1);
    assert(result == 1);

}



int main(void) {
    test_check_line();
    printf("Test to checker passed!\n");
    test_check_line_win();
    printf("Test to checker in case of win passed!\n");
    printf("All tests passed!\n");
    return 0;
}
