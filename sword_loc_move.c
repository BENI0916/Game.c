#include <stdio.h>

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

void sword_loc_move(int coor, int head_num, int body_num, int feet_num)
{
    // 劍 : 位置移動
    player.loc_sword_head[coor] += head_num;
    player.loc_sword_body[coor] += body_num;
    player.loc_sword_feet[coor] += feet_num;
}
