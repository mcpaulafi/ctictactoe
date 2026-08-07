/* Checker functions */
#ifndef CHECKER_H
#define CHECKER_H

#include <inttypes.h>
#include "common.h"

int8_t extract_lines(int8_t cell);
int8_t check_line(int8_t line[BOARD_WIDTH]);

#endif