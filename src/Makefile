CC = gcc
# CFLAGS = -Wall -Wextra -Wpedantic -std=c11
CFLAGS =

SRC = main.c common.c settings.c checker.c extract_lines.c location.c row.c col.c diag_asc.c diag_desc.c print.c play.c update.c new.c

OBJ = $(SRC:.c=.o)

cttt: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o cttt

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) cttt
