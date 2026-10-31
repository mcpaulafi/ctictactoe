/* Print game board */
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "../include/common.h"
#include "../include/print.h"

void format_cell(int8_t cell_value, int8_t cell_idx, char *display_char) {
    switch (cell_value) {
        case 0:// Empty cell
            if (cell_idx <9) {
                snprintf(display_char, sizeof(display_char), "%d  ", cell_idx+1);
            } else {
                snprintf(display_char, sizeof(display_char), "%d ", cell_idx+1);
            }
            break;
        case 1:
            strcpy(display_char, "X  "); // Player 1
            break;
        case 2:
            strcpy(display_char, "O  "); // Player 2
            break;
        default:
            strcpy(display_char, "?  "); // Unknown value
    }
}

void print_line(void){
    int8_t line_width = board_width * 3 + 2; // Each cell takes 3 spaces, plus 2 for the borders
    if (line_width < 14) {
        line_width = 20; // At least 20 characters
    }
    for (int i = 0; i < line_width; i++) {
        printf("*");
    }
    printf("\n");
}

void print_gameboard(void) {
    print_line();
    printf(GREEN "* Game Board *\n" RESET);
    print_line();
    for (int r = 0; r < board_width; r++) {
        printf("  ");
        for (int c = 0; c < board_width; c++) {
            int8_t cell_idx = r * board_width + c;
            int8_t cell_value = gameboard[cell_idx];
            char display_char[10]; // Buffer to hold the display string
            format_cell(cell_value, cell_idx, display_char);
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
    print_line();
    printf("\n");
}