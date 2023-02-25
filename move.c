#include <stdio.h>
#include <time.h>
#define height 20
#define len 100
extern int atk_act;
extern char input;
// �N���a����J���s��

extern clock_t start, end;

extern int table[2][height + 2][len + 2];
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

// ���a����
void move()
{
    input = getch_noblock();
    input = tolower(input);

    if(input == 'a')
    {
        if(input != player.face_dir && !atk_act)  // �Y�����V�P�e�i��V���P
        {                           // ���ୱ���V
            player.face_dir = input;
            clear_loc();
            player_loc_move(0, 0);
            sword_loc_move(1, -2, -2, -2);
            put();
        }
        else if(table[1][player.loc_sword_head[0]][player.loc_sword_head[1] - 2] == 0) // �P�w�O�_�i����
        {
            clear_loc();
            player_loc_move(1, -1);
            sword_loc_move(1, -1, -1, -1);
            put();
        }
    }
    else if(input == 'd')
    {
        if(input != player.face_dir && !atk_act)  // �Y�����V�P�e�i��V���P
        {                           // ���ୱ���V
            player.face_dir = input;
            clear_loc();
            player_loc_move(0, 0);
            sword_loc_move(1, 2, 2, 2);
            put();
        }
        else if(table[1][player.loc_sword_head[0]][player.loc_sword_head[1] + 1] == 0) // �P�w�O�_�i����
        {
            clear_loc();
            player_loc_move(1, 1);
            sword_loc_move(1, 1, 1, 1);
            put();
        }
    }
    else if(input == ' ')
    {
        if(table[1][player.loc_sword_head[0] - 1][player.loc_sword_head[1]] == 0)
        {
            clear_loc();
            player_loc_move(0, -1);
            sword_loc_move(0, -1, -1, -1);
            put();

            start = clock();
            // �p�ɶ}�l
        }
    }
    else if(input == 'j' && !atk_act)
    {
        int emp = 1;
        if(player.face_dir == 'd')
        {
            for(int i = player.loc_sword_head[0]; i < player.loc_sword_head[0] + 3; i++)
            {
                for(int j = player.loc_sword_head[1] + 1; j < player.loc_sword_head[1] + 3; j++)
                {
                    if(table[1][i][j] != 0)
                    {
                        emp = 0;
                        break;
                    }
                }
            }
        }
        else
        {
            for(int i = player.loc_sword_head[0]; i < player.loc_sword_head[0] + 3; i++)
            {
                for(int j = player.loc_sword_head[1] - 2; j < player.loc_sword_head[1]; j++)
                {
                    if(table[1][i][j] != 0)
                    {
                        emp = 0;
                        break;
                    }
                }
            }
        }

        if(emp)
            atk_act = 4;
    }

    end = clock();
    // �p�ɵ���

    // �p�G���a�S���a �ӥB���ŶW�L 0.5��� ���U 1 ��
    if(table[1][player.loc_feet[0] + 1][player.loc_feet[1]] == 0 && ((float)(end - start) / CLK_TCK) > 0.5)
    {
        clear_loc();
        player_loc_move(0, 1);
        sword_loc_move(0, 1, 1, 1);
        put();

        start = clock();
        // ��s�p�ɶ}�l���ɶ�
    }

    if(atk_act)
    {
        clear_loc();
        switch(atk_act)
        {
            case 4:
                if(player.face_dir == 'd')
                {
                    player.asc_sword_arr[0] = 47;
                    player.asc_sword_arr[1] = 47;
                    player.asc_sword_arr[2] = 47;
                    sword_loc_move(1, 2, 1, 0);
                }
                else
                {
                    player.asc_sword_arr[0] = 92;
                    player.asc_sword_arr[1] = 92;
                    player.asc_sword_arr[2] = 92;
                    sword_loc_move(1, -2, -1, 0);
                }
                break;
            case 3:
                player.asc_sword_arr[0] = 196;
                player.asc_sword_arr[1] = 196;
                player.asc_sword_arr[2] = 196;

                sword_loc_move(0, 2, 1, 0);
                break;
            case 2:
                if(player.face_dir == 'd')
                {
                    player.asc_sword_arr[0] = 47;
                    player.asc_sword_arr[1] = 47;
                    player.asc_sword_arr[2] = 47;
                }
                else
                {
                    player.asc_sword_arr[0] = 92;
                    player.asc_sword_arr[1] = 92;
                    player.asc_sword_arr[2] = 92;
                }

                sword_loc_move(0, -2, -1, 0);
                break;
            case 1:
                player.asc_sword_arr[0] = 124;
                player.asc_sword_arr[1] = 124;
                player.asc_sword_arr[2] = 124;

                if(player.face_dir == 'd')
                    sword_loc_move(1, -2, -1, 0);
                else
                    sword_loc_move(1, 2, 1, 0);
                break;
        }
        put();
        atk_act--;
    }
}
