//《算法竞赛进阶指南》
#include <iostream>
#include <cstring>
using namespace std;

const int N = 7;
char map[N][N], backup[N][N];
int dir[5][2] = {0, -1, 1, 0, 0, 1, -1, 0, 0, 0};

void turn(int x, int y){
    for(int i = 0 ; i < 5 ; i ++){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];

        if(xx < 0 || xx > 4 || yy < 0 || yy > 4) continue;
        map[xx][yy] ^= 1;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        for(int i = 0 ; i < 5 ; i ++) cin >> map[i];

        int ans = 7;
        for(int op = 0 ; op < 32 ; op ++){
            int step = 0;
            memcpy(backup, map, sizeof map);
            for(int i = 0 ; i < 5 ; i ++){
                if(op >> i & 1){
                    step ++;
                    turn(0, i);
                }
            }

            for(int i = 0 ; i < 4 ; i ++)
                for(int j = 0 ; j < 5 ; j ++){
                    if(map[i][j] == '0'){
                        step ++;
                        turn(i + 1, j);
                    }
                }

            bool is = true;
            for(int i = 0 ; i < 5 ; i ++){
                if(map[4][i] == '0'){
                    is = false;
                    break;
                }
            }
            if(is) ans = min(step, ans);   

            memcpy(map, backup, sizeof backup);
        }
        if(ans == 7) puts("-1");
        else cout << ans << endl;
    }
    return 0;
}