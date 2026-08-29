# Tic-Tac-Toe in C
### About
This is a simple text-based Tic-Tac-Toe game written in C programming language.

### Lyhyesti suomeksi
Tämä on yksinkertainen tekstipohjainen ristinollapeli kirjoitettuna C-ohjelmointikielellä.

## Documentation
- [Architecture](docs/architecture.md)
- [User manual](docs/manual.md)

## Known issues
- Many unit tests missing

## Development ideas
- Add also Win_length for user to set

## Releases
- [Version 1.0.0](releases/tag/release)

## Installation on Windows

Copy [w_cttt.exe](windows/w_cttt.exe) on your computer.

## Installation on Linux

    git clone ctictactoe
    cd ctictactoe

### Run Gnu compiler

    cd src

Run Makefile for linux build

    make

Run Makefile for Windows build

    make windows

Clean *.o files and exe after running

    make clean

OR shell command (debuging with warnings, additional and extra for C version c11)

    gcc -Wall -Wextra -Wpedantic -std=c11 *.c -o cttt

OR without debuging

    gcc *.c -o cttt

## Running 
Linux

    ./cttt

Windows

    Run w_cttt.exe and ignore warning

## Testing
Compiling individual test

    gcc -Wall -Wextra -o testrun tests/test_col.c src/col.c src/common.c
    gcc -Wall -Wextra -o testrun tests/test_row.c src/row.c src/common.c
    gcc -Wall -Wextra -o testrun tests/test_state.c src/print.c src/common.c src/game_state.c
    gcc -Wall -Wextra -o testrun tests/test_diag_asc.c src/diag_asc.c src/common.c src/location.c
    gcc -Wall -Wextra -o testrun tests/test_diag_desc.c src/diag_desc.c src/common.c src/location.c

Run test

    ./testrun

All tests

    gcc test/*.c src/game.c -o testrun
    ./testrun
