#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <string.h>

void GameStart();
void Settings();
void Help();

int mode = 1;
int forbid = 2;
int player;

int main(){
    while(1){
        system("cls");
        system("chcp 65001");
        //system("color 70");
        printf("================================\n");
        printf("        欢迎来到 五子棋          \n");
        printf("================================\n");
        printf("  1. 开始游戏                    \n");
        printf("  2. 游戏设置                    \n");
        printf("  3. 游戏帮助                    \n");
        printf("================================\n");
        printf("输入数字（1/2/3）以继续");
        printf("\n");
        char input[100];
        int select = 0;
        fgets(input, sizeof(input), stdin);
        sscanf(input,"%d",&select);
        switch(select){
            case 1: GameStart(); break;
            case 2: Settings(); break;
            case 3: Help(); break;
            default: 
                printf("输入非法，输入任意键返回");
                system("pause");
        }   
    }
}

void GameStart(){
    InitBoard();
    system("cls");
    player = 1;
    int choose_player;
    if(mode == 2){
        printf("执黑请输入1，执白请输入2");
        char input4[100];
        int select4;
        fgets(input4, sizeof(input4), stdin);
        sscanf(input4, "%d", & select4);
        switch(select4){
            case 1: choose_player = 1; break;
            case 2: choose_player = 2; break;
            default:
                printf("输入非法，按任意键返回");
                system("pause");
                return;
        }
    }
    while(1){
        int row,col;
        int num_col;
        system("cls"); 
        if(mode == 1){
            PrintBoard();
            printf("重新开始请输入again，回到菜单请输入menu\n");
            char input5[100];
            fgets(input5, sizeof(input5), stdin);
            input5[strcspn(input5, "\n")] = 0;
            if (strcmp(input5, "again") == 0){
                GameStart();
            }
            if(strcmp(input5, "menu") == 0){
                return;
            }
            if (sscanf(input5, "%d %c", &row, &col) == 2) {
                row = 16 - row;
                if(row <1 || row > 15){
                    printf("输入非法，输入任意键以重新输入");
                    system("pause");
                    continue;
                }
                else{
                    if(col >= 'a' && col <= 'o'){
                        num_col = col - 'a' + 1;
                    }
                    else if(col >= 'A' && col <= 'O'){
                        num_col = col - 'a' + 1;
                    }
                    else{
                        printf("输入非法，输入任意键以重新输入");
                        system("pause");
                        continue;
                    }
                    if(GetPiece(row,num_col) != 0){
                        printf("输入非法，输入任意键以重新输入");
                        system("pause");
                        continue;
                    }
                }
            }
            else{
                printf("输入非法，输入任意键以重新输入");
                system("pause");
                continue;
            }
            PlacePiece(row,num_col,player);
        }
        if(mode == 2){

        }

        if(ifsuccess(row,num_col,player) == 1){
            system("cls");
            PrintBoard();
            if(player == 1){
                printf("游戏结束，黑棋胜利\n");
                printf("输入任意键返回\n");
                system("pause");
                return;
            }
            else{
                printf("游戏结束，白棋胜利\n");
                printf("输入任意键返回\n");
                system("pause");
                return;
            }
        }
        else{
            if(ifdraw() == 1){
                printf("游戏结束，平局\n");
                printf("输入任意键返回\n");
                system("pause");
                return;
            }
            else{
                if(forbid == 1){
                    if(ifforbid() == 1){
                        printf("禁手判负，游戏结束\n");
                        printf("输入任意键返回\n");
                        system("pauser");
                        return;
                    }
                }
            }
        }
        if(player == 1) player = 2;
        else player = 1;
    }
}




void Settings(){
    system("cls");
    char input2[100] = {};
    int select2;
    char input3[100] = {};
    int select3;
    printf("  模式                    \n");
    printf("  1. 同屏对战模式                    \n");
    printf("  2. ai模式                    \n");
    printf("请选择数字：\n");
    fgets(input2, sizeof(input2), stdin);
    sscanf(input2,"%d",&select2);
    switch(select2){
        case 1:
            mode = 1;break;
        case 2:
            mode = 2;break;
        default:
            printf("输入非法，按任意键返回\n");
            system("pause");
            return;
    }
    printf("\n");
    printf("  是否启用禁手                    \n");
    printf("  1. 是                    \n");
    printf("  2. 否                    \n");
    printf("请选择数字：\n");
    fgets(input3, sizeof(input3), stdin);
    sscanf(input3,"%d",&select3);
    switch(select3){
        case 1:
            forbid = 1;break;
        case 2:
            forbid = 2;break;
        default:
            printf("输入非法，按任意键返回\n");
            system("pause");
    }
}






void Help(){
    system("cls");
    printf("该程序为作者2026秋季学期C语言程序设计课程大作业\n");
    printf("注意禁手情况下下禁手会直接判负\n");
    printf("默认为同屏对战模式，不开启禁手\n");
    printf("\n");
    printf("按任意键返回\n");
    system("pause");
}