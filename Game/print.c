#include <stdio.h>

#define height 20
#define len 100

extern int table[2][height + 2][len + 2];

void print()
{
    for(int i = 0; i < height + 2; i++)
    {
        for(int j = 0; j < len + 2; j++)
        {
            if(table[0][i][j] != 0)
            {
                printf("%c", table[0][i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
