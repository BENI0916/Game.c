//Game.c
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define height 20
#define len 100
// �� 20 �� 100

int atk_act;
char input;
// �N���a����J���s��

clock_t start, end;

int table[2][height + 2][len + 2];
// table[0][][] : ���L��
// �̥~��O��� �n+2
// ����ΨӦL�X
// 0 �N���L�F��
// ��L�Ʀr�h�N��n�L�X��ASCII�r��

// table[1][][] : ���A��
// ����ΨӧP�_
// 0�N��L���A
// ��L�Ʀr�U�����P���A
// Dictionary.txt�����㻡��

struct man  // �N���a����m
{           // loc[0][]:�Y, loc[1][]:��, loc[2][]:�}, loc[][0]:y�b��m, loc[][1]:x�b��m
    int loc[3][2];
    int loc_sword[3][2];
    int asc_arr[3]; // 0:�Y, 1:��, 2:�}
    int asc_sword_arr[3];   // 0:�Y, 1:��, 2:�}
    int man_sta; // ���w
    int sword_sta;  // ���w
    int hp; // ��q
    char face_dir; // �H�������V(�C�Ҧb����V)
} player;

void put();
// ���L��P���A�� : �H�� �C ��m

void initialization();
// ��l��

void print();
// �N���L���F��L�X
// �����b��L�ʧ@������~����

void ResetScreenPosition();
// �N���L����Ц�m��^(0,0)

void hidden();
// ���ô�а{�{ ���[�γ~

int getch_noblock();
// �������a��J
// �Y�S��J�]�|����U�@�Ӱʧ@

void player_loc_clr();
// ���L��P���A�� : �H�� �C ��m�M��

void player_loc_move(int coor, int num);
// ���L��P���A�� : �H�� ��m����

void sword_loc_move(int coor, int head_num, int body_num, int feet_num);
// ���L��P���A�� : �C ��m����

void move();
// �P�_���ʥi��ʤβ���

int check_empty(int x, int y);

void set_obstable();

int main(void)
{
    SetConsoleOutputCP(437);
    // �ϵ{���i��X ASCII 256

    initialization();
    // ������l�� �]�w�n�U�譱���ƭ�

    while(((float)(end - start) / CLK_TCK) < 30) // �j�鵲���N��C������
    {
        ResetScreenPosition();
        hidden();
        move();
        set_obstable();
        print();
    }

    return 0;
}
