
/**************************************
* Tic-tac-toe
* Ristinolla (fin)
* mcpaulafi 10th August 2026
**************************************/
// version 1.0.1

#include <inttypes.h> // Variable types int8_t

#include "../include/common.h"
#include "../include/game_state.h"

int main(void) {
    int8_t running = 1; //Loop
    int8_t status = 0; 

    while (running) {
        status = process_state(status);
        if (status == -1){
            running = 0;
        }
    }
    return 0;
}
