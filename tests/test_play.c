/* Unit test for column */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/common.h"
#include "../include/play.h"


void test_parse_cell_input_valid(void){
    assert(parse_cell_input("1") == 0);
}

void test_parse_cell_input_invalid(void){
    assert(parse_cell_input("Y") == -1);
}

void test_parse_cell_input_out_of_bounds(void){
    assert(parse_cell_input("101") == -1);
}

void test_parse_cell_input_already_played(void){
    gameboard[0] = 1; // Mark cell 1 as played
    assert(parse_cell_input("1") == -2);
}

int main(void) {
    test_parse_cell_input_valid();
    printf("Test to parse cell input valid passed!\n");
    test_parse_cell_input_invalid();
    printf("Test to parse cell input invalid passed!\n");
    test_parse_cell_input_out_of_bounds();
    printf("Test to parse cell input out of bounds passed!\n");
    test_parse_cell_input_already_played();
    printf("Test to parse cell input already played passed!\n");
    return 0;
}
