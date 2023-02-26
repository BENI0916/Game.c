#include <stdio.h>
#define height 20
#define len 100

extern int table[2][height + 2][len + 2];

void set_obstable()
{
    for(int i = 0; i < 5; i++)
    {
        table[0][height - i][5] = 186;
        table[1][height - i][5] = 100;
    }
}
