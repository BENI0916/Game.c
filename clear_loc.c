#include <stdio.h>
#define height 20
#define len 100

extern int table[2][height + 2][len + 2];

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


void clear_loc()
{
    for(int i = 0; i < 2; i++)
    {
        // ���L�� : �H�� ��m�k 0
        // ���A�� : �H�� �k 0
        table[i][player.loc_head[0]][player.loc_head[1]] = 0;
        table[i][player.loc_body[0]][player.loc_body[1]] = 0;
        table[i][player.loc_feet[0]][player.loc_feet[1]] = 0;

        // ���L�� : �C ��m�k 0
        // ���A�� : �C �k 0
        table[i][player.loc_sword_head[0]][player.loc_sword_head[1]] = 0;
        table[i][player.loc_sword_body[0]][player.loc_sword_body[1]] = 0;
        table[i][player.loc_sword_feet[0]][player.loc_sword_feet[1]] = 0;
    }
}
