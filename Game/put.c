#include <stdio.h>

#define height 20
#define len 100

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

extern int table[2][height + 2][len + 2];

void put()
{
    // 打印表 : 人物
    table[0][player.loc[0][0]][player.loc[0][1]] = player.asc_arr[0];
    table[0][player.loc[1][0]][player.loc[1][1]] = player.asc_arr[1];
    table[0][player.loc[2][0]][player.loc[2][1]] = player.asc_arr[2];

    // 打印表 : 劍
    table[0][player.loc_sword[0][0]][player.loc_sword[0][1]] = player.asc_sword_arr[0];
    table[0][player.loc_sword[1][0]][player.loc_sword[1][1]] = player.asc_sword_arr[1];
    table[0][player.loc_sword[2][0]][player.loc_sword[2][1]] = player.asc_sword_arr[2];

    // 狀態表 : 人物
    table[1][player.loc[0][0]][player.loc[0][1]] = player.man_sta;
    table[1][player.loc[1][0]][player.loc[1][1]] = player.man_sta;
    table[1][player.loc[2][0]][player.loc[2][1]] = player.man_sta;

    // 狀態表 : 劍
    table[1][player.loc_sword[0][0]][player.loc_sword[0][1]] = player.sword_sta;
    table[1][player.loc_sword[1][0]][player.loc_sword[1][1]] = player.sword_sta;
    table[1][player.loc_sword[2][0]][player.loc_sword[2][1]] = player.sword_sta;
}
