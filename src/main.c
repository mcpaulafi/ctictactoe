
/**************************************
* Tic-tac-toe
* Ristinolla (fin)
* mcpaulafi 10th August 2026
**************************************/
// version 0.1

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

int main(void) {
    int8_t running = 1; //Loop
    int8_t status = 0; //start game with settings
    while(running){
        switch(status){
            case 0:
                if(debug) {printf("Set game\n");}
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
                    status = 5;
                    break;
                }else{
                    status = 6; //Tie
                    break;
                }
            case 4:
                if(debug) {printf("Win\n");}
                running = 0;
                break;
            case 5:
                printf("No win yet\n\n");
                if (player == 1) {
                    player = 2;
                }else{
                    player = 1;
                }
                status = 1;
                break;
            case 6:
                if(debug) {printf("Tie\n");}
                running = 0;
                break;
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


//printf("* Win with line of: %d             *\n", win_length);
 
//    set_game();
//     memset(gameboard, 0, sizeof(gameboard)); //Initialize game board
//     while(1){

//         print_gameboard();
//         cell = input_cell(); //play.c
//         if (cell == -1){
//             printf("***********************************\n");
//             printf("*****  Tie - no wins!!!   *****\n");
//             print_gameboard();
//             return 0;
//         }
//         int update = update_board();
//         int8_t result = extract_lines();

//         if (result==1) {
//             printf("***********************************\n");
//             printf("*****  Win to player: %c !!!   *****\n", PLAYER_NAME(player));
//             print_gameboard();
//             return 0;
//         } else if (result==-1){
//             printf("Error\n");
//             return 0;
//         }else { 
//             printf("No win yet\n\n");
//             if (player == 1) {
//                 player = 2;
//             }else{
//                 player = 1;
//             }
//             continue;
//         } 
//     }