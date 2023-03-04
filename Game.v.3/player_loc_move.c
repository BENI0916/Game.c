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

void player_loc_move(int coor, int num) // coor 代表X or Y的方向
{
    // 玩家 : 位置移動
    for(int i = 0; i < 3; i++)
        player.loc[i][coor] += num;
}
