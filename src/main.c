
/**************************************
* Tic-tac-toe
* Ristinolla (fin)
* mcpaulafi 10th August 2026
**************************************/
// version 0.2

#include <stdio.h>  // RW, files
#include <inttypes.h> // Variable types int8_t
#include <string.h> 
#include <stdlib.h> // Type conversions, memo, sys commands
//#include <math.h> add -lm option to linker

#include "common.h"
#include "settings.h"
#include "extract_lines.h"
#include "print.h"
#include "play.h"
#include "update.h"
#include "new.h"

int main(void) {
    int8_t running = 1; //Loop
    int8_t status = 0; //start game with settings
    while(running){
        switch(status){
            case 0:
                printf("Settings for the new game.\n");
                status = set_game();
                break;
            case 1:
                if(debug) {printf("Print board and input cell\n");}
                print_gameboard();
                status = input_cell();
                break;
            case 2:
                if(debug) {printf("Update board\n");}
                status = update_board();
                break;
            case 3:
                if(debug) {printf("Check result\n");}
                int8_t result = extract_lines();
                if (result == 1) {
                    status = 4; //Win
                }else if (result == 0) {
                    status = 5; //Continue
                    break;
                }else{
                    status = 6; //Tie
                    break;
                }
                break;
            case 4:
                if (player == 1){
                    printf(RED "WIN to player %c!!!!\n" RESET, PLAYER_NAME(player));
                }else{
                    printf(GREEN "WIN to player %c!!!!\n" RESET, PLAYER_NAME(player));
                }
                print_gameboard();
                status = 7;
                break;
            case 5:
                printf("No win yet. Continue.\n\n");
                if (player == 1) { //Switch player
                    player = 2;
                }else{
                    player = 1;
                }
                status = 1;
                break;
            case 6:
                printf("TIE! Game over.\n");
                print_gameboard();
                status = 7;
                break;
            case 7:
                if(debug) {printf("New game?\n");}
                int8_t start_new = new();
                if (start_new == 1){
                    status = 0;
                    break;
                }else{
                    printf("End program.\n");
                    running = 0;
                    break;
                }
            case -1:
                printf("Error\n");
                running = 0;
                break;
            default:
                running = 0;
                break;
        }
    }
    return 0;
}
