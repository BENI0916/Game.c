#include <stdio.h>

#define height 20
#define len 100

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

extern int table[2][height + 2][len + 2];

void put()
{
    // ���L�� : �H��
    table[0][player.loc_head[0]][player.loc_head[1]] = player.asc_arr[0];
    table[0][player.loc_body[0]][player.loc_body[1]] = player.asc_arr[1];
    table[0][player.loc_feet[0]][player.loc_feet[1]] = player.asc_arr[2];

    // ���L�� : �C
    table[0][player.loc_sword_head[0]][player.loc_sword_head[1]] = player.asc_sword_arr[0];
    table[0][player.loc_sword_body[0]][player.loc_sword_body[1]] = player.asc_sword_arr[1];
    table[0][player.loc_sword_feet[0]][player.loc_sword_feet[1]] = player.asc_sword_arr[2];

    // ���A�� : �H��
    table[1][player.loc_head[0]][player.loc_head[1]] = player.man_sta;
    table[1][player.loc_body[0]][player.loc_body[1]] = player.man_sta;
    table[1][player.loc_feet[0]][player.loc_feet[1]] = player.man_sta;

    // ���A�� : �C
    table[1][player.loc_sword_head[0]][player.loc_sword_head[1]] = player.sword_sta;
    table[1][player.loc_sword_body[0]][player.loc_sword_body[1]] = player.sword_sta;
    table[1][player.loc_sword_feet[0]][player.loc_sword_feet[1]] = player.sword_sta;
}
