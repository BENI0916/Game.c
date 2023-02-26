#include <stdio.h>

#define height 20
#define len 100

extern struct man  // �N���a����m
{           // loc[0][]:�Y, loc[1][]:��, loc[2][]:�}, loc[][0]:y�b��m, loc[][1]:x�b��m
    int loc[3][2];
    int loc_sword[3][2];
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
    table[0][player.loc[0][0]][player.loc[0][1]] = player.asc_arr[0];
    table[0][player.loc[1][0]][player.loc[1][1]] = player.asc_arr[1];
    table[0][player.loc[2][0]][player.loc[2][1]] = player.asc_arr[2];

    // ���L�� : �C
    table[0][player.loc_sword[0][0]][player.loc_sword[0][1]] = player.asc_sword_arr[0];
    table[0][player.loc_sword[1][0]][player.loc_sword[1][1]] = player.asc_sword_arr[1];
    table[0][player.loc_sword[2][0]][player.loc_sword[2][1]] = player.asc_sword_arr[2];

    // ���A�� : �H��
    table[1][player.loc[0][0]][player.loc[0][1]] = player.man_sta;
    table[1][player.loc[1][0]][player.loc[1][1]] = player.man_sta;
    table[1][player.loc[2][0]][player.loc[2][1]] = player.man_sta;

    // ���A�� : �C
    table[1][player.loc_sword[0][0]][player.loc_sword[0][1]] = player.sword_sta;
    table[1][player.loc_sword[1][0]][player.loc_sword[1][1]] = player.sword_sta;
    table[1][player.loc_sword[2][0]][player.loc_sword[2][1]] = player.sword_sta;
}
