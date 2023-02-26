//Game.c
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define height 20
#define len 100
// 高 20 長 100

int atk_act;
char input;
// 將玩家的輸入站存於此

clock_t start, end;

int table[2][height + 2][len + 2];
// table[0][][] : 打印表
// 最外圈是邊界 要+2
// 此表用來印出
// 0 代表不印東西
// 其他數字則代表要印出的ASCII字元

// table[1][][] : 狀態表
// 此表用來判斷
// 0代表無狀態
// 其他數字各有不同狀態
// Dictionary.txt有完整說明

struct man  // 代表玩家的位置
{           // loc[0][]:頭, loc[1][]:身, loc[2][]:腳, loc[][0]:y軸位置, loc[][1]:x軸位置
    int loc[3][2];
    int loc_sword[3][2];
    int asc_arr[3]; // 0:頭, 1:身, 2:腳
    int asc_sword_arr[3];   // 0:頭, 1:身, 2:腳
    int man_sta; // 未定
    int sword_sta;  // 未定
    int hp; // 血量
    char face_dir; // 人物面對方向(劍所在的方向)
} player;

void put();
// 打印表與狀態表 : 人物 劍 放置

void initialization();
// 初始化

void print();
// 將打印表的東西印出
// 必須在其他動作結束後才執行

void ResetScreenPosition();
// 將打印的游標位置返回(0,0)

void hidden();
// 隱藏游標閃爍 美觀用途

int getch_noblock();
// 接收玩家輸入
// 若沒輸入也會執行下一個動作

void player_loc_clr();
// 打印表與狀態表 : 人物 劍 位置清空

void player_loc_move(int coor, int num);
// 打印表與狀態表 : 人物 位置移動

void sword_loc_move(int coor, int head_num, int body_num, int feet_num);
// 打印表與狀態表 : 劍 位置移動

void move();
// 判斷移動可行性及移動

int check_empty(int x, int y);

void set_obstable();

int main(void)
{
    SetConsoleOutputCP(437);
    // 使程式可輸出 ASCII 256

    initialization();
    // 先做初始化 設定好各方面的數值

    while(((float)(end - start) / CLK_TCK) < 30) // 迴圈結束代表遊戲結束
    {
        ResetScreenPosition();
        hidden();
        move();
        set_obstable();
        print();
    }

    return 0;
}
