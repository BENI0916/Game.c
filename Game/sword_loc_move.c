#include <stdio.h>

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

void sword_loc_move(int coor, int head_num, int body_num, int feet_num)
{
    // 劍 : 位置移動
    player.loc_sword[0][coor] += head_num;
    player.loc_sword[1][coor] += body_num;
    player.loc_sword[2][coor] += feet_num;
}
