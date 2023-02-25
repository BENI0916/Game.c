#include <stdio.h>
#include <time.h>
#define height 20
#define len 100
extern int atk_act;
extern char input;
// 將玩家的輸入站存於此

extern clock_t start, end;

extern int table[2][height + 2][len + 2];
// table[0][][] : 打印表
// 最外圈是邊界 要+2
// 此表用來印出
// 0 代表不印東西
// 其他數字則代表要印出的ASCII字元

// table[1][][] : 狀態表
// 此表用來判斷
// 0代表無狀態
// 其他數字各有不同狀態
// Dictionary.txt有完整說明

extern struct man  // 代表玩家的位置 拆成頭身腳三部分
{           // Index 0 代表 y 軸, 1代表 x 軸
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
    char face_dir; // 人物面對方向(劍所在的方向)
} player;

// 玩家移動
void move()
{
    input = getch_noblock();
    input = tolower(input);

    if(input == 'a')
    {
        if(input != player.face_dir && !atk_act)  // 若面對方向與前進方向不同
        {                           // 先轉面對方向
            player.face_dir = input;
            clear_loc();
            player_loc_move(0, 0);
            sword_loc_move(1, -2, -2, -2);
            put();
        }
        else if(table[1][player.loc_sword_head[0]][player.loc_sword_head[1] - 2] == 0) // 判定是否可移動
        {
            clear_loc();
            player_loc_move(1, -1);
            sword_loc_move(1, -1, -1, -1);
            put();
        }
    }
    else if(input == 'd')
    {
        if(input != player.face_dir && !atk_act)  // 若面對方向與前進方向不同
        {                           // 先轉面對方向
            player.face_dir = input;
            clear_loc();
            player_loc_move(0, 0);
            sword_loc_move(1, 2, 2, 2);
            put();
        }
        else if(table[1][player.loc_sword_head[0]][player.loc_sword_head[1] + 1] == 0) // 判定是否可移動
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
            // 計時開始
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
    // 計時結束

    // 如果玩家沒落地 而且滯空超過 0.5秒後 往下 1 格
    if(table[1][player.loc_feet[0] + 1][player.loc_feet[1]] == 0 && ((float)(end - start) / CLK_TCK) > 0.5)
    {
        clear_loc();
        player_loc_move(0, 1);
        sword_loc_move(0, 1, 1, 1);
        put();

        start = clock();
        // 更新計時開始的時間
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
