#include "board.h"

struct _Board {
  Square *squares[64];
}

struct _Square {
  int row;
  char column;
  char piece;
}

Board *board_create() {
  Board *b = NULL;
  b = (Board *) malloc(siceof(Board));
  if(!b) return NULL;
  
  return b;
}

Void board_destroy(Board *b) {
  if(b) {
    int i;
    for(i=0; i<64; i++) square_destroy(b->squares[i]);
    free(b)
  }
}

Status board_restart(Board *b) {
  if(!b) return ERROR;
  int i, j;
  for(i=0; i<64; i++) {
    b->square[i]=square_create(1, a, R);
    if(!b->square[i]) {
      for(j=0; j<i; j++) free b->square[j];
      return ERROR;
    }
  }

  square_edit(b->square[0], 1, a, R);
  square_edit(b->square[1], 1, b, N);
  square_edit(b->square[2], 1, c, B);
  square_edit(b->square[3], 1, d, Q);
  square_edit(b->square[4], 1, e, K);
  square_edit(b->square[5], 1, f, B);
  square_edit(b->square[6], 1, g, N);
  square_edit(b->square[7], 1, h, R);
  square_edit(b->square[8], 2, a, P);
  square_edit(b->square[9], 2, b, P);
  square_edit(b->square[10], 2, c, P);
  square_edit(b->square[11], 2, d, P);
  square_edit(b->square[12], 2, e, P);
  square_edit(b->square[13], 2, f, P);
  square_edit(b->square[14], 2, g, P);
  square_edit(b->square[15], 2, h, P);
  square_edit(b->square[16], 3, a, .);
  square_edit(b->square[17], 3, b, .);
  square_edit(b->square[18], 3, c, .);
  square_edit(b->square[19], 3, d, .);
  square_edit(b->square[20], 3, e, .);
  square_edit(b->square[21], 3, f, .);
  square_edit(b->square[22], 3, g, .);
  square_edit(b->square[23], 3, h, .);
  square_edit(b->square[24], 4, a, .);
  square_edit(b->square[25], 4, b, .);
  square_edit(b->square[26], 4, c, .);
  square_edit(b->square[27], 4, d, .);
  square_edit(b->square[28], 4, e, .);
  square_edit(b->square[29], 4, f, .);
  square_edit(b->square[30], 4, g, .);
  square_edit(b->square[31], 4, h, .);
  square_edit(b->square[32], 5, a, .);
  square_edit(b->square[33], 5, b, .);
  square_edit(b->square[34], 5, c, .);
  square_edit(b->square[35], 5, d, .);
  square_edit(b->square[36], 5, e, .);
  square_edit(b->square[37], 5, f, .);
  square_edit(b->square[38], 5, g, .);
  square_edit(b->square[39], 5, h, .);
  square_edit(b->square[40], 6, a, .);
  square_edit(b->square[41], 6, b, .);
  square_edit(b->square[42], 6, c, .);
  square_edit(b->square[43], 6, d, .);
  square_edit(b->square[44], 6, e, .);
  square_edit(b->square[45], 6, f, .);
  square_edit(b->square[46], 6, g, .);
  square_edit(b->square[47], 6, h, .);
  square_edit(b->square[48], 7, a, p);
  square_edit(b->square[49], 7, b, p);
  square_edit(b->square[50], 7, c, p);
  square_edit(b->square[51], 7, d, p);
  square_edit(b->square[52], 7, e, p);
  square_edit(b->square[53], 7, f, p);
  square_edit(b->square[54], 7, g, p);
  square_edit(b->square[55], 7, h, p);
  square_edit(b->square[56], 8, a, r);
  square_edit(b->square[57], 8, b, n);
  square_edit(b->square[58], 8, c, b);
  square_edit(b->square[59], 8, d, q);
  square_edit(b->square[60], 8, e, k);
  square_edit(b->square[61], 8, f, b);
  square_edit(b->square[62], 8, g, n);
  square_edit(b->square[63], 8, h, r);
  return OK;
}

Status Board_edit_square(Board *b, Square *s, int i) {
  if(!b||!s||i>63||i<0) return ERROR;
  b->square[i] = square_copy(s);
  if(!b->square[i]) return ERROR;
  return OK;
}

int board_print(Board *b) {}

Square *square_create(int row, char column, char piece) {
  if(row<0||row>8||(column!=a && column!=b && column!=c && column!=d && column!=e && column!=f && column!=g && column!=h)
     ||(piece!=r && piece!=n && piece!=b && piece!=q && piece!=k && piece!=p &&piece!=R && piece!=N && piece!=B && piece!=Q 
        && piece!=K && piece!=P && piece!=.)) return NULL;
  Square *s = NULL;
  s = (Square *) malloc(siceof(Square));
  if(!s) return NULL;
  
  s->row = row;
  s->column = column;
  s->piece = piece;
  return s;
}

Void square_destroy(Square *s) {
  if(s) free(s);
}

int square_get_row(Square *s) {
  if(!s) return NULL;
  return s->row;
}

char square_get_column(Square *s) {
  if(!s) return NULL;
  return s->column;
}

char square_get_piece(Square *s) {
  if(!s) return NULL;
  return s->piece;
}
Status square_set_row(Square *s, int i) {
  if(!s||i<0||i>8) return ERROR;
  s->row = i;
  return OK;
}

Status square_set_column(Square *s, char i) {
  if(!s||(i!=a && i!=b && i!=c && i!=d && i!=e && i!=f && i!=g && i!=h)) return ERROR;
  s->column = i;
  return OK;
}

Status square_set_piece(Square *s, char i) {
  if(!s||(piece!=r && piece!=n && piece!=b && piece!=q && piece!=k && piece!=p &&piece!=R && piece!=N && piece!=B && piece!=Q 
        && piece!=K && piece!=P && piece!=.)) return ERROR;
  s->piece = i;
  return OK;
}

Square square_copy(Square *s) {
  if(!s) return NULL;
  Square *s1 = NULL;
  s1 = square_create(s->row, s->column, s->piece);
  if(!s1) return NULL;
  return s1;
}

Status square_edit(Square *s, int i, char j, char k){
   if(!s||row<0||row>8||(column!=a && column!=b && column!=c && column!=d && column!=e && column!=f && column!=g && column!=h)
     ||(piece!=r && piece!=n && piece!=b && piece!=q && piece!=k && piece!=p &&piece!=R && piece!=N && piece!=B && piece!=Q 
        && piece!=K && piece!=P && piece!=.)) return ERROR;
  s->row = i;
  s->column = j;
  s->piece = k;
  return OK;
}

int square_print(Square *s) {
}

Square *board_get_black_king(Board *b) {
  if(!b) return NULL;
  int i;
  for(i=0; i<64; i++) if(square_get_piece(b->square[i]==K)) return b->square[i];
  
  return NULL;
}

Square *board_get_white_king(Board *b) {
  if(!b) return NULL;
  int i;
  for(i=0; i<64; i++) if(square_get_piece(b->square[i]==k)) return b->square[i];
  
  return NULL;
}

