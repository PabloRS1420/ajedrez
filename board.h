#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

typedef struct _Board Board;

Board *board_create();
Void board_destroy(Board *b);
Status board_restart(Board *b);
Status Board_edit_square(Board *b, Square *s, int i);
int board_print(Board *b);
Square *square_create(int row, char column, char piece);
Void square_destroy(Square *s);
int square_get_row(Square *s);
char square_get_column(Square *s);
char square_get_piece(Square *s);
Status square_set_row(Square *s, int i);
Status square_set_column(Square *s, char i);
Status square_set_piece(Square *s, char i);
Square square_copy(const Square *s);
int square_print(const Square *s);
Square *board_get_black_king(const Board *b);
Square *board_get_white_king(const Board *b);

#endif
