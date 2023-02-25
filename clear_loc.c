#include <stdio.h>
#define height 20
#define len 100

extern int table[2][height + 2][len + 2];

extern struct man  // 代表玩家的位置 拆成頭身腳三部分
{           // Index 0 代表 y 軸, 1代表 x 軸
    int loc_head[2];
    int loc_body[2];
    int loc_feet[2];
    int loc_sword_head[2];
    int loc_sword_body[2];
    int loc_sword_feet[2];
    int asc_arr[3];
    int asc_sword_arr[3];
    int man_sta;
    int sword_sta;
    int hp;
    char face_dir; // 人物面對方向(劍所在的方向)
} player;


void clear_loc()
{
    for(int i = 0; i < 2; i++)
    {
        // 打印表 : 人物 位置歸 0
        // 狀態表 : 人物 歸 0
        table[i][player.loc_head[0]][player.loc_head[1]] = 0;
        table[i][player.loc_body[0]][player.loc_body[1]] = 0;
        table[i][player.loc_feet[0]][player.loc_feet[1]] = 0;

        // 打印表 : 劍 位置歸 0
        // 狀態表 : 劍 歸 0
        table[i][player.loc_sword_head[0]][player.loc_sword_head[1]] = 0;
        table[i][player.loc_sword_body[0]][player.loc_sword_body[1]] = 0;
        table[i][player.loc_sword_feet[0]][player.loc_sword_feet[1]] = 0;
    }
}
