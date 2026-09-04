#include "board.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int GetPiece(int row, int col){
    if (board[row][col] == "●") return 1;
    if (board[row][col] == "○") return 2;
    return 0;
}

int judge(int row,int col,int player,int dx,int dy){
    int cnt = 1;
    int x = row;
    int y = col;
    for(int i = 1; i < 5; i++){
        x += dx;
        y += dy;
        if(x > 15 || x < 1 || y > 15 || y < 1) break;
        if(GetPiece(x,y) != player) break;
        if(GetPiece(x,y) == player) cnt += 1;
    }
    x = row;
    y = col;
    for(int i = 1; i <= 5; i++){
        x -= dx;
        y -= dy;
        if(x > 15 || x < 1 || y > 15 || y < 1) break;
        if(GetPiece(x,y) != player) break;
        if(GetPiece(x,y) == player) cnt += 1;
    }
    return cnt;
}

int success(int row, int col, int player){
    int dx[4] = {0,1,1,1};
    int dy[4] = {1,0,1,-1};
    for(int i = 0; i < 4; i++){
        if(judge(row,col,player,dx[i],dy[i]) >= 5) return 1;
    }
    return 0;
}