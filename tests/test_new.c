/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/new.h"


void test_parse_new_game_yes(void){
    assert(parse_new_game("Y") == 1);
}

void test_parse_new_game_no(void){
    assert(parse_new_game("n") == 0);
}

void test_parse_new_game_invalid(void){
    assert(parse_new_game("X") == -1);
}



int main(void) {
    test_parse_new_game_yes();
    printf("Test to parse new game yes passed!\n");
    test_parse_new_game_no();
    printf("Test to parse new game no passed!\n");
    test_parse_new_game_invalid();
    printf("Test to parse new game invalid passed!\n");
    return 0;
}
