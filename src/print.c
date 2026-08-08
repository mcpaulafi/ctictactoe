/* Print game board */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "print.h"

void print_gameboard(void) {
    printf("***********************************\n");
    printf("*         Game Board              *\n");
    printf("***********************************\n");
    for (int r = 0; r < BOARD_WIDTH; r++) {
        printf("  ");
        for (int c = 0; c < BOARD_WIDTH; c++) {
            int8_t cell_idx = r * BOARD_WIDTH + c+1;
            int8_t cell_value = gameboard[cell_idx];
            char display_char[10]; // Buffer to hold the display string
            switch (cell_value) {
                case 0:
                    if (cell_idx <10) {
                        snprintf(display_char, sizeof(display_char), "%d  ", cell_idx);
                    } else {
                        snprintf(display_char, sizeof(display_char), "%d ", cell_idx);
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
            printf("%s", display_char);
        }
        printf("\n");
    }
    printf("***********************************\n");
    printf("* Win with line of: %d             *\n", win_length);
    printf("***********************************\n");
    printf("\n\n");
}