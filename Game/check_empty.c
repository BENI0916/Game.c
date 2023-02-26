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

int check_empty(int x, int y)
{
    if(x)
    {
        for(int i = 0; i < 4; i++)
            if(table[1][player.loc_sword[0][0] + i][player.loc_sword[0][1] + x] != 0)
                return 0;
    }

    if(y > 0)
    {
        if(table[1][player.loc_sword[2][0] + 1 + y][player.loc_sword[0][1]] != 0
        || table[1][player.loc[2][0] + y][player.loc[0][1]] != 0)
            return 0;
    }
    else if(y < 0)
    {
        if(table[1][player.loc_sword[0][0] + y][player.loc_sword[0][1]] != 0
        || table[1][player.loc[0][0] + y][player.loc[0][1]] != 0)
            return 0;
    }
    return 1;
}
