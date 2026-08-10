/* Print game board */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "print.h"

void print_gameboard(void) {
    printf("***********************************\n");
    printf(GREEN "*         Game Board              *\n" RESET);
    printf("***********************************\n");
    for (int r = 0; r < board_width; r++) {
        printf("  ");
        for (int c = 0; c < board_width; c++) {
            int8_t cell_idx = r * board_width + c;
            int8_t cell_value = gameboard[cell_idx];
            char display_char[10]; // Buffer to hold the display string
            switch (cell_value) {
                case 0:
                    if (cell_idx <9) {
                        snprintf(display_char, sizeof(display_char), "%d  ", cell_idx+1);
                    } else {
                        snprintf(display_char, sizeof(display_char), "%d ", cell_idx+1);
                    }
                    break;
                case 1:
                    strcpy(display_char, "X  ");
                    break;
                case 2:
                    strcpy(display_char, "O  ");
                    break;
                default:
                    strcpy(display_char, "?  "); // Unknown value
            }
            if (cell_value == 1){
                printf(RED "%s" RESET, display_char);
            }else if (cell_value == 2){
                printf(GREEN "%s" RESET, display_char);
            }else{
                printf("%s", display_char);
            }
        }
        printf("\n");
    }
    printf("***********************************\n");
    printf("\n");
}