/* Function to handle game states */
#include <inttypes.h>
#include <stdio.h>

#include "../include/common.h"
#include "../include/settings.h"
#include "../include/extract_lines.h"
#include "../include/print.h"
#include "../include/play.h"
#include "../include/update.h"
#include "../include/new.h"
#include "../include/game_state.h"

int8_t process_state(int8_t status){
    switch(status) {
        case 0:
            printf("Settings for a new TicTacToe-game.\n");
            return set_game();
        case 1:
            if(debug) {printf("Print board and input cell\n");}
            print_gameboard();
            return input_cell();
        case 2:
            if(debug) {printf("Update board\n");}
            return update_board();
        case 3:
            if(debug) {printf("Check result\n");} 
            int8_t result = extract_lines();
            if (result == 1){
                return 4; // Win
            } else if (result == 0){
                return 5; // Continue
            }else{
                return 6; // Tie
            }
        case 4:
            if (player == 1){
                printf(RED "WIN to player %c!!!!\n" RESET, PLAYER_NAME(player));
            }else{
                printf(GREEN "WIN to player %c!!!!\n" RESET, PLAYER_NAME(player));
            }
            print_gameboard();
            return 7;
        case 5:
            printf("No win yet. Continue.\n\n");
            if (player == 1) { //Switch player
                player = 2;
            }else{
                player = 1;
            }
            return 1;
        case 6:
            printf("TIE! Game over.\n");
            print_gameboard();
            return 7;
        case 7:
            if(debug) {printf("New game?\n");}
            int8_t start_new = new();
             if (start_new == 1){
                return 0;
            }else{
                printf("End program.\n");
                return -1;
            }
        default:
            printf("Error\n");
            return -1; //error
        }
    }
