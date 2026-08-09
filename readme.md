# Tic-Tac-Toe in C
### About
This is a simple text-based Tic-Tac-Toe game written in C programming language.

### Lyhyesti suomeksi
Tämä on yksinkertainen tekstipohjainen ristinollapeli kirjoitettuna C-ohjelmointikielellä.

## Documentation
- [Architecture](docs/architecture.md)

## Known bugs and issues
- Tests missing
- UX need improvement
- Make compiling

## Releases
None yet.

## Installation on Linux

    git clone ctictactoe
    cd ctictactoe

### Run compiler

    gcc main.c common.c checker.c extract_lines.c location.c row.c col.c diag_asc.c diag_desc.c print.c play.c update.c -o program


## Running
After installation

    ./program

## Testing

    gcc -Wall -Wextra -o testrun_col tests/test_col.c src/col.c src/common.c
    ./testrun_col