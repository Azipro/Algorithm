/*博弈论极大极小算法
  对抗搜索
*/

#include<iostream>
#include<cstdio>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#define INF 0x3f3f3f3f
#define mod 100000007
#define maxn 105
using namespace std;
typedef long long ll;

int arr[3][3];

int judge(int w){
    if(arr[0][0] == w && arr[0][1] == w && arr[0][2] == w){
        return 1;
    }
    if(arr[0][0] == w && arr[1][0] == w && arr[2][0] == w){
        return 1;
    }
    if(arr[0][0] == w && arr[1][1] == w && arr[2][2] == w){
        return 1;
    }
    if(arr[1][0] == w && arr[1][1] == w && arr[1][2] == w){
        return 1;
    }
    if(arr[2][0] == w && arr[1][1] == w && arr[0][2] == w){
        return 1;
    }
    if(arr[2][0] == w && arr[2][1] == w && arr[2][2] == w){
        return 1;
    }
    if(arr[0][1] == w && arr[1][1] == w && arr[2][1] == w){
        return 1;
    }
    if(arr[0][2] == w && arr[1][2] == w && arr[2][2] == w){
        return 1;
    }
    return 0;
}

int sum(int w){
    int ans = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(arr[i][j] == 0) ans++;
        }
    }
    if(w == 1){
        return ans + 1;
    }else{
        return -ans - 1;
    }
}

int dfs(int w){
    if(sum(w) == 1 || sum(w) == -1) return 0;
    int ma = -9, mb = 9;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(!arr[i][j]){
                arr[i][j] = w;
                if(judge(w)){
                    int score = sum(w);
                    arr[i][j] = 0;
                    if(w == 1){
                        return max(ma, score);
                    }else{  
                        return min(mb, score);
                    }
                }else{
                    if(w == 1){
                        ma = max(ma, dfs(2));
                    }else{
                        mb = min(mb, dfs(1));
                    }
                    arr[i][j] = 0;
                }
            }
        }
    }
    return w == 1 ? ma : mb;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        if(judge(1)){
            printf("%d\n", sum(1));
            continue;
        }
        if(judge(2)){
            printf("%d\n", sum(2));
            continue;
        }
        printf("%d\n", dfs(1));
    }
    return 0;
}
