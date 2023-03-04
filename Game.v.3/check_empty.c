#include <stdio.h>
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

int check_empty(int x, int y)   // 根據給定的x, y值 判定玩家移動的方向是否可行
{                               // 0: 不行, 1: 可以
    if(x)
    {
        for(int i = 0; i < 4; i++)
        {
            if(table[1][player.loc_sword[0][0] + i][player.loc_sword[0][1] + x] != 0)
                return 0;
        }
    }

    if(y > 0)
    {
        if(table[1][player.loc_sword[2][0] + 1 + y][player.loc_sword[2][1]] != 0)
            return 0;

        if(table[1][player.loc[2][0] + y][player.loc[2][1]] != 0)
            return 0;
    }
    else if(y < 0)
    {
        if(table[1][player.loc_sword[0][0] + y][player.loc_sword[0][1]] != 0)
            return 0;

        if(table[1][player.loc[0][0] - 1 + y][player.loc[0][1]] != 0)
            return 0;
    }

    return 1;
}
