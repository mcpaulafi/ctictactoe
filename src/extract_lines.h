/* Extract lines functions */

#ifndef EXTRACT_LINES_H
#define EXTRACT_LINES_H

#include <inttypes.h>
#include "common.h"
#include "checker.h"


int8_t extract_lines(int8_t cell);
int8_t extract_row(int8_t row_idx);
int8_t extract_column(int8_t col_idx);

#endif