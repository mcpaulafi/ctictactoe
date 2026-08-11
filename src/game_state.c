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
            if(debug) {printf("Start new?\n");}
             if (new()){
                printf("Settings for the game.\n");
                return set_game(); //Returns 1
            }else{
                printf("End program.\n");
                return -1;
            }
        case 1:
            if(debug) {printf("Print board and input cell\n");}
            print_gameboard();
            return input_cell();  //Returns 2
        case 2:
            if(debug) {printf("Update board\n");}
            return update_board(); // Returns 3
        case 3:
            if(debug) {printf("Check result\n");} 
            int8_t result = extract_lines();
            if (result == 1){ // Win
                const char *color = (player == 1) ? RED : GREEN;
                printf("%sWIN to player %c!!!!\n" RESET, color, PLAYER_NAME(player));
                print_gameboard();
                return 0;
            } else if (result == 0){ // Continue game
                printf("No win yet. Continue.\n\n");
                player = 3 - player; //Switch player
                return 1;
            }else{
                printf("TIE! No winners.\n");
                print_gameboard();
                return 0;
            }
        default: // End game or error
            //printf("Error\n");
            return -1; 
        }
    }
