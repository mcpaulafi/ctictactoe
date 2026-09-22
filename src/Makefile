CC = gcc
WINCC = x86_64-w64-mingw32-gcc

# CFLAGS = -Wall -Wextra -Wpedantic -std=c11
CFLAGS =

SRC = main.c common.c settings.c checker.c extract_lines.c location.c row.c col.c diag_asc.c diag_desc.c print.c play.c update.c new.c game_state.c

all: cttt

OBJ = $(SRC:.c=.o)

cttt: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o cttt

windows: $(SRC)
	$(WINCC) $(CFLAGS) $(SRC) -o ../windows/w_cttt.exe

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# TESTS

TESTS = \
	test_col \
	test_row \
	test_state \
	test_diag_asc \
	test_diag_desc \
	test_checker \
	test_extract_lines \
	test_location

test: $(TESTS)
	@echo "All tests built"
	./test_col
	./test_row
	./test_state
	./test_diag_asc
	./test_diag_desc
	./test_checker
	./test_extract_lines
	./test_location

test_col: ../tests/test_col.c col.c common.c
	$(CC) $(CFLAGS) -o $@ $^

test_row: ../tests/test_row.c row.c common.c
	$(CC) $(CFLAGS) -o $@ $^

test_state: ../tests/test_state.c print.c common.c game_state.c
	$(CC) $(CFLAGS) -o $@ $^

test_diag_asc: ../tests/test_diag_asc.c diag_asc.c common.c location.c
	$(CC) $(CFLAGS) -o $@ $^

test_diag_desc: ../tests/test_diag_desc.c diag_desc.c common.c location.c
	$(CC) $(CFLAGS) -o $@ $^

test_checker: ../tests/test_checker.c checker.c common.c
	$(CC) $(CFLAGS) -o $@ $^

test_extract_lines: ../tests/test_extract_lines.c extract_lines.c common.c location.c
	$(CC) $(CFLAGS) -o $@ $^

test_location: ../tests/test_location.c location.c common.c
	$(CC) $(CFLAGS) -o $@ $^

tests: $(TESTS)

run-tests: tests
	./test_col
	./test_row
	./test_state
	./test_diag_asc
	./test_diag_desc
	./test_checker
	./test_extract_lines
	./test_location

# CLEAN UP TEST FILES and OBJECT FILES

clean:
	rm -f $(OBJ) cttt ../windows/w_cttt.exe $(TESTS)
