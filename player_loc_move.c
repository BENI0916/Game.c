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

void player_loc_move(int coor, int num) // coor �N��X or Y����V
{
    // ���a : ��m����
    player.loc_head[coor] += num;
    player.loc_body[coor] += num;
    player.loc_feet[coor] += num;
}
