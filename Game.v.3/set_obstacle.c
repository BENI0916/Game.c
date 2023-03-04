#include <stdio.h>
#define height 20
#define len 80
// 高 20 長 80
extern int table[2][height + 2][len + 2];

void set_obstable() // 設定關卡地形 陷阱
{
    int i;

    for(i = 0; i < 4; i++)
    {
        table[0][height - i][10] = 186;
        table[1][height - i][10] = 100;
    }

    table[0][height - 4][10] = 201;
    table[1][height - 4][10] = 100;

    for(i = 0; i < 6; i++)
    {
        table[0][height - 4][11 + i] = 205;
        table[1][height - 4][11 + i] = 100;
    }

    table[0][height - 4][16] = 187;
    table[1][height - 4][16] = 100;
    table[1][height - 4][17] = 100;

    for(i = 0; i < 4; i++)
    {
        table[0][height - i][16] = 186;
        table[1][height - i][16] = 100;
    }

    for(i = 0; i < 5; i++)
    {
        table[0][height][17 + i] = 65;
        table[1][height][17 + i] = 200;
    }

    for(i = 0; i < 9; i++)
    {
        table[0][height - 8][30 + i] = 205;
        table[1][height - 8][30 + i] = 100;
    }
    table[1][height - 8][39] = 100;

}
