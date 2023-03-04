#include <stdio.h>
#include <time.h>
#define height 20
#define len 80
// �� 20 �� 80

extern clock_t hp_start, hp_end;
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

void cal_hp() // �p���q
{
    if(table[1][player.loc[2][0] + 1][player.loc[2][1]] == 200) // �Y��쳴��
    {
        hp_end = clock(); // ��������U���ɶ�

        if(((float)(hp_end - hp_start) / CLK_TCK) > 3) // �Y���|���� ���̦h3���@��
        {
            for(int i = 5; i < 15; i++)
                table[0][1][i] = 0; // �N���W�����ܪ������M��
                                    // �å�set_hp() �i���s
            player.hp--; // ���a��q���
            hp_start = clock(); // �O������᪺�ɶ��I �Ψӷ����P�w���_�l�ɶ��I
        }
    }
}
