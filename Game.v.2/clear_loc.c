#include <stdio.h>
#define height 20
#define len 100

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


void clear_loc()
{
    // 打印表 : 人物 位置歸 0, 劍 位置歸 0
    // 狀態表 : 人物 歸 0, 劍 歸 0
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            table[i][player.loc[j][0]][player.loc[j][1]] = 0;
            table[i][player.loc_sword[j][0]][player.loc_sword[j][1]] = 0;
        }
    }
}
