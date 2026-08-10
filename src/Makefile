CC = gcc
WINCC = x86_64-w64-mingw32-gcc

# CFLAGS = -Wall -Wextra -Wpedantic -std=c11
CFLAGS =

SRC = main.c common.c settings.c checker.c extract_lines.c location.c row.c col.c diag_asc.c diag_desc.c print.c play.c update.c new.c

all: cttt

OBJ = $(SRC:.c=.o)

cttt: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o cttt

windows: $(SRC)
	$(WINCC) $(CFLAGS) $(SRC) -o ../windows/w_cttt.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) cttt ../windows/w_cttt.exe
