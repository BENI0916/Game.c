#include <stdio.h>
#include <time.h>
#define height 20
#define len 80
// 高 20 長 80

extern clock_t hp_start, hp_end;
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

void cal_hp() // 計算血量
{
    if(table[1][player.loc[2][0] + 1][player.loc[2][1]] == 200) // 若踩到陷阱
    {
        hp_end = clock(); // 紀錄踩到當下的時間

        if(((float)(hp_end - hp_start) / CLK_TCK) > 3) // 若踩到會扣血 但最多3秒扣一次
        {
            for(int i = 5; i < 15; i++)
                table[0][1][i] = 0; // 將左上血條顯示的部分清除
                                    // 並由set_hp() 進行刷新
            player.hp--; // 玩家血量減少
            hp_start = clock(); // 記錄扣血後的時間點 用來當後續判定的起始時間點
        }
    }
}
