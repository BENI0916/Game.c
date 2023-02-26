#include <stdio.h>
#define height 20
#define len 100

extern int table[2][height + 2][len + 2];

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


void clear_loc()
{
    // ���L�� : �H�� ��m�k 0, �C ��m�k 0
    // ���A�� : �H�� �k 0, �C �k 0
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            table[i][player.loc[j][0]][player.loc[j][1]] = 0;
            table[i][player.loc_sword[j][0]][player.loc_sword[j][1]] = 0;
        }
    }
}
