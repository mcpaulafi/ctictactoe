/* Extract lines functions */

#ifndef EXTRACT_LINES_H
#define EXTRACT_LINES_H

#include <inttypes.h>


int8_t extract_lines(void);
int8_t extract_column(int8_t col_idx);
int8_t extract_diagonal_descending(int8_t row_idx, int8_t col_idx);
int8_t extract_diagonal_ascending(int8_t row_idx, int8_t col_idx);

typedef struct {
    int8_t col;
    int8_t row;
} Location;

#endif