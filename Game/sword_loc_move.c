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

void sword_loc_move(int coor, int head_num, int body_num, int feet_num)
{
    // �C : ��m����
    player.loc_sword[0][coor] += head_num;
    player.loc_sword[1][coor] += body_num;
    player.loc_sword[2][coor] += feet_num;
}
