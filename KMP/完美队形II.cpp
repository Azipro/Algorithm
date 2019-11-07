//HDU 4513
Problem Description
　　吉哥又想出了一个新的完美队形游戏！
　　假设有n个人按顺序站在他的面前，他们的身高分别是h[1], h[2] ... h[n]，吉哥希望从中挑出一些人，让这些人形成一个新的队形，新的队形若满足以下
    三点要求，则就是新的完美队形：
    1、挑出的人保持原队形的相对顺序不变，且必须都是在原队形中连续的；
    2、左右对称，假设有m个人形成新的队形，则第1个人和第m个人身高相同，第2个人和第m-1个人身高相同，依此类推，当然如果m是奇数，中间那个人可以任意；
    3、从左到中间那个人，身高需保证不下降，如果用H表示新队形的高度，则H[1] <= H[2] <= H[3] .... <= H[mid]。

　　现在吉哥想知道：最多能选出多少人组成新的完美队形呢？
 

Input
　　输入数据第一行包含一个整数T，表示总共有T组测试数据(T <= 20)；
　　每组数据首先是一个整数n(1 <= n <= 100000)，表示原先队形的人数，接下来一行输入n个整数，表示原队形从左到右站的人的身高（50 <= h <= 250，
    不排除特别矮小和高大的）。
 

Output
　　请输出能组成完美队形的最多人数，每组输出占一行。
 

Sample Input
2
3
51 52 51
4
51 52 52 51
 

Sample Output
3
4




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 300005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], prefix[maxn];
bool vis[maxn];
int s[maxn], str[maxn];

void init(){
    str[0] = 0;
    str[1] = 255;
    for(int i = 0; i < m ; i++){
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = 255;
    }
    n = m * 2 + 2;
    str[n] = -1;
}

void manacher(){
    int id = 0, mx = 0;
    int judge = 0;
    for(int i = 1; i < n ; i++){
        if(mx > i) arr[i] = min(arr[2 * id - i], mx - i);
        else{
            arr[i] = 1;
        }
        judge = str[i];
        while( (str[i + arr[i]] == str[i - arr[i]]) && (str[i - arr[i]] == 255 || str[i - arr[i]] <= judge) ){
            if(str[i - arr[i]] != 255){
                judge = str[i - arr[i]];
            }
            arr[i]++;   
        } 
         if(arr[i] + i > mx){
            mx = arr[i] + i;
            id = i;
        }
        ans = max(ans , arr[i]);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        scanf("%d", &m);
        for(int i = 0 ; i < m ;i++) scanf("%d", &s[i]);
        ans = 0;
        init();
        manacher();
        printf("%d\n", ans - 1);
    }
    return 0;
}
