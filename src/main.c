
/**************************************
* Ristinolla
* Tic-tac-toe
* mcpaulafi 6.8.2026
**************************************/
// version 0.1
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h> add -lm option to linker

int8_t debug = 1; // debug mode 0=off, 1=on

//Prototypes
int8_t tictactoe_check(int8_t *gameboard, int size);

//Test gameboard for testing the functions
int8_t gameboard_100[100] = {
    1,2,0,0,0,0,0,0,0,2,
    1,1,2,0,0,0,0,0,2,2,
    1,0,0,2,0,0,0,2,0,2,
    1,0,0,0,2,0,2,0,0,2,
    1,0,0,0,0,2,0,0,0,2,
    1,0,0,0,2,0,0,0,0,2,
    2,2,2,2,0,0,0,2,2,2,
    1,0,2,0,0,0,0,2,0,2,
    1,2,0,0,0,0,2,0,0,2,
    2,1,1,1,1,1,1,1,1,1
    };

// Main function
int main() {
    int result = tictactoe_check(gameboard_100, 10);

    if (debug){ printf("Tulos %d\n", result); };
    return 0;
}

//Functions
int8_t tictactoe_check(int8_t * gameboard, int win_len){
    return 0;
}
