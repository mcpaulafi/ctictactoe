#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "../include/game_state.h"
#include "../include/common.h"
#include "../include/print.h"

int8_t set_game(void) { return 1; }
int8_t input_cell(void) { return 2; }
int8_t update_board(void) { return 3; } 
int8_t extract_lines(void) { return 1; } //Can also return 0, -1
int8_t new(void) { return 1; } //Can also return -1

void test_process_state(void){
    assert(process_state(0) == 1);
    assert(process_state(1) == 2);
    assert(process_state(2) == 3);
    assert(process_state(3) == 4);
    assert(process_state(4) == 7);
    assert(process_state(5) == 1);
    assert(process_state(6) == 7);
    assert(process_state(7) == 0); //Can also return -1
    assert(process_state(8) == -1);
    assert(process_state(99) == -1);
}

int main(void){
    test_process_state();
    printf("All process state tests passed!\n");
    return 0;
}
