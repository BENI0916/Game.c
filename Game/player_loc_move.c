#include <stdio.h>

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

void player_loc_move(int coor, int num) // coor �N��X or Y����V
{
    // ���a : ��m����
    for(int i = 0; i < 3; i++)
        player.loc[i][coor] += num;
}
