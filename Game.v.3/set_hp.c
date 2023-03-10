#include <stdio.h>

#define height 20
#define len 80
// 高 20 長 80
extern int table[2][height + 2][len + 2];

extern struct man  // 代表玩家的位置
{           // loc[0][]:頭, loc[1][]:身, loc[2][]:腳, loc[][0]:y軸位置, loc[][1]:x軸位置
    int loc[3][2];
    int loc_sword[3][2];
    int asc_arr[3];
    int asc_sword_arr[3];
    int man_sta;
    int sword_sta;
    int hp;
    char face_dir; // 人物面對方向(劍所在的方向)
} player;

void set_hp() // 在螢幕左上方顯示血條
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
