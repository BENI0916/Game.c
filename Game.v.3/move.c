#include <stdio.h>
#include <time.h>
#define height 20
#define len 80
// 高 20 長 80
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

// 玩家移動
void move()
{
    input = getch_noblock();
    input = tolower(input);

    if(input == 'a')
    {
        if(input != player.face_dir && !atk_act && check_empty(-2, 0))  // 若面對方向與前進方向不同
        {                           // 先轉面對方向
            player.face_dir = input;
            clear_loc();
            player_loc_move(0, 0);
            sword_loc_move(1, -2, -2, -2);
            put();
        }
        else if(check_empty(-1, 0)) // 判定是否可移動
        {
            clear_loc();
            player_loc_move(1, -1);
            sword_loc_move(1, -1, -1, -1);
            put();
        }
    }
    else if(input == 'd')
    {
        if(input != player.face_dir && !atk_act && check_empty(2, 0))  // 若面對方向與前進方向不同
        {                           // 先轉面對方向
            player.face_dir = input;
            clear_loc();
            player_loc_move(0, 0);
            sword_loc_move(1, 2, 2, 2);
            put();
        }
        else if(check_empty(1, 0)) // 判定是否可移動
        {
            clear_loc();
            player_loc_move(1, 1);
            sword_loc_move(1, 1, 1, 1);
            put();
        }
    }
    else if(input == ' ')
    {
        if(check_empty(0, -1))
        {
            clear_loc();
            player_loc_move(0, -1);
            sword_loc_move(0, -1, -1, -1);
            put();

            start = clock();
            // 計時開始
        }
    }
    else if(input == 'j' && !atk_act)   // 如果玩家進行攻擊且未在攻擊狀態
    {
        int emp = 1; // 判定是否可以攻擊 0:不可攻擊, 1:可攻擊
        if(player.face_dir == 'd')  // 根據玩家面對的方向進行"前方空間是否有可攻擊的空間"的判定
        {
            for(int i = player.loc_sword[0][0]; i < player.loc_sword[0][0] + 3; i++)
            {
                for(int j = player.loc_sword[0][1] + 1; j < player.loc_sword[0][1] + 3; j++)
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
            for(int i = player.loc_sword[0][0]; i < player.loc_sword[0][0] + 3; i++)
            {
                for(int j = player.loc_sword[0][1] - 2; j < player.loc_sword[0][1]; j++)
                {
                    if(table[1][i][j] != 0)
                    {
                        emp = 0;
                        break;
                    }
                }
            }
        }

        if(emp) // 若前方可攻擊, 賦予攻擊計數器: 4
            atk_act = 4;
    }

    end = clock();
    // 計時結束

    // 如果玩家沒落地 而且滯空超過 0.5秒後 往下 1 格
    if(check_empty(0, 1) && ((float)(end - start) / CLK_TCK) > 0.3)
    {
        clear_loc();
        player_loc_move(0, 1);
        sword_loc_move(0, 1, 1, 1);
        put();

        start = clock();
        // 更新計時開始的時間
    }

    if(atk_act) // 若攻擊計數器啟動
    {
        clear_loc();
        switch(atk_act)
        {
            case 4:
                if(player.face_dir == 'd') // 先判定方向
                {   // 根據揮劍角度給予相對應字元
                    player.asc_sword_arr[0] = 47;
                    player.asc_sword_arr[1] = 47;
                    player.asc_sword_arr[2] = 47;

                    // 並移動打印表與狀態表上的劍
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
        put(); // 打印表與狀態表 : 人物 劍 放置
        atk_act--; // 每執行一次須減少一次計數器
    }
}
