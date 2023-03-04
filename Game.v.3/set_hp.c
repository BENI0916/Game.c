#include <stdio.h>

#define height 20
#define len 80
// �� 20 �� 80
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

void set_hp() // �b�ù����W����ܦ��
{
    table[0][1][2] = 'H';
    table[0][1][3] = 'P';
    table[0][1][4] = ':';

    for(int i = 0; i < player.hp * 2; i += 2)
    {
        table[0][1][5 + i] = ' ';
        table[0][1][5 + i + 1] = 178;
    }
}
