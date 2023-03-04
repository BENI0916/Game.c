#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define height 20
#define len 80
// 高 20 長 80
extern int table[2][height + 2][len + 2];

extern struct man  // 代表玩家的位置
{           // loc[0][]:頭, loc[1][]:身, loc[2][]:腳, loc[][0]:y軸位置, loc[][1]:x軸位置
    int loc[3][2];
    int loc_sword[3][2];
    int asc_arr[3];
    int asc_sword_arr[3];
    int man_sta;
    int sword_sta;
    int hp;
    char face_dir; // 人物面對方向(劍所在的方向)
} player;

void print()
{
    SetConsoleOutputCP(437);

    for(int i = 0; i < height + 2; i++)
    {
        for(int j = 0; j < len + 2; j++)
        {
            if(table[0][i][j] != 0)
            {
                printf("%c", table[0][i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
