#include <stdio.h>

extern struct man  // �N���a����m ��Y���}�T����
{           // Index 0 �N�� y �b, 1�N�� x �b
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
    char face_dir; // �H�������V(�C�Ҧb����V)
} player;

void sword_loc_move(int coor, int head_num, int body_num, int feet_num)
{
    // �C : ��m����
    player.loc_sword_head[coor] += head_num;
    player.loc_sword_body[coor] += body_num;
    player.loc_sword_feet[coor] += feet_num;
}
