#include <stdio.h>

#define height 20
#define len 100

extern int atk_act;
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

// ��l��
void initialization()
{
    // �]�w�n��ɪ�ASCII�X ��l�� 0
    // ���K�N���A������� 0
    for(int i = 0; i < height + 2; i++)
    {
        for(int j = 0; j < len +2; j++)
        {
            if(j == 0 || j == len + 1)
            {
                table[0][i][j] = 186; // ���
                table[1][i][j] = -1;
            }
            else if(i == 0 || i == height +1)
            {
                table[0][i][j] = 205; // ���
                table[1][i][j] = -1;
            }
            else
            {
                table[0][i][j] = 0;
                table[1][i][j] = 0;
            }
        }
    }

    // ���L�� : �䨤
    table[0][0][0] = 201;
    table[0][0][len + 1] = 187;
    table[0][height + 1][0] = 200;
    table[0][height + 1][len + 1] = 188;

    // ��m : �H��
    player.loc_head[0] = height - 2;
    player.loc_head[1] = 3;

    player.loc_body[0] = height - 1;
    player.loc_body[1] = 3;

    player.loc_feet[0] = height;
    player.loc_feet[1] = 3;

    // ��m : �C
    player.loc_sword_head[0] = height - 3;
    player.loc_sword_head[1] = 4;

    player.loc_sword_body[0] = height - 2;
    player.loc_sword_body[1] = 4;

    player.loc_sword_feet[0] = height - 1;
    player.loc_sword_feet[1] = 4;

    player.asc_arr[0] = 79;
    player.asc_arr[1] = 124;
    player.asc_arr[2] = 65;

    player.asc_sword_arr[0] = 124;
    player.asc_sword_arr[1] = 124;
    player.asc_sword_arr[2] = 124;

    player.man_sta = 1;
    player.sword_sta = 100;

    put();

    player.face_dir = 'd';
    player.hp = 5;

    atk_act = 0;
}
