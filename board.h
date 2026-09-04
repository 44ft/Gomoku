#ifndef BOARD_H
#define BOARD_H

extern char *board[16][16];

// 声明三个函数
void InitBoard();
void PrintBoard();
int PlacePiece(int row, int col, int player);

#endif