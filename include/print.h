/* Print game board */
#ifndef PRINT_H
#define PRINT_H

#include <inttypes.h>

void format_cell(int8_t cell_value, int8_t cell_idx, char *display_char);
void print_line(void);
void print_gameboard(void);

#endif

