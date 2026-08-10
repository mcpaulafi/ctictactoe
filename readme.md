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
None yet.

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

    gcc -Wall -Wextra -o testrun_col tests/test_col.c src/col.c src/common.c
    ./testrun_col