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

void player_loc_move(int coor, int num) // coor 代表X or Y的方向
{
    // 玩家 : 位置移動
    player.loc_head[coor] += num;
    player.loc_body[coor] += num;
    player.loc_feet[coor] += num;
}
