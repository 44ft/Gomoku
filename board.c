#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "game.h"


char *board[16][16];

void InitBoard() {
    board[1][1] = "┌";
    board[1][15] = "┐";
    board[15][1] = "└";
    board[15][15] = "┘";
    for (int i = 2; i < 15; i++) {
        board[1][i] = "┬";
        board[15][i] = "┴";
        board[i][1] = "├";
        board[i][15] = "┤";
    }
    for (int i = 2; i < 15; i++) {
        for (int j = 2; j < 15; j++) {
            board[i][j] = "┼";
        }
    }
}


void PrintBoard() {
    for (int i = 1; i <= 15; i++) {
        printf("%2d ", 16 - i);
        for (int j = 1; j < 15; j++) {
            printf("%s", board[i][j]);
            if(GetPiece(i,j) == 0 && GetPiece(i,j+1) == 0){
                printf("─");
            }
            if(GetPiece(i,j) == 0 && GetPiece(i,j+1) != 0){
                printf(" ");
            }
        }
        printf("%s",board[i][15]);
        printf("\n");
    }
    printf("  ");
    for(int i = 0; i < 15; i ++){
        printf(" ");
        printf("%c", 'a' + i);
    }
    printf("\n");
}

void PlacePiece(int row, int col, int player){
    if(player == 1){
        board[row][col] = "●";
    }
    if(player == 2){
        board[row][col] = "○";
    }
}

/*
int main() {
    system("chcp 65001");   // 解决中文乱码，不需要就删掉
    InitBoard();

    // 落几个不同的位置，全部都是合法的
    PlacePiece(7, 7, 1);    // 中央黑棋
    PlacePiece(8, 8, 2);    // 右下白棋
    PlacePiece(5, 3, 1);    // 左上黑棋
    PlacePiece(12, 10, 2);  // 左下白棋
    PlacePiece(3, 14, 1);   // 右上黑棋

    PrintBoard();           // 打印最终棋盘
    system("pause");
    return 0;
}
*/