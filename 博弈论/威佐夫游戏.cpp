//51Nod - 1185
有2堆石子。A B两个人轮流拿，A先拿。每次可以从一堆中取任意个或从2堆中取相同数量的石子，但不可不取。拿到最后1颗石子的人获胜。
假设A B都非常聪明，拿石子的过程中不会出现失误。给出2堆石子的数量，问最后谁能赢得比赛。
例如：2堆石子分别为3颗和5颗。那么不论A怎样拿，B都有对应的方法拿到最后1颗。

输入
第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10000)
第2 - T + 1行：每行2个数分别是2堆石子的数量，中间用空格分隔。(1 <= N <= 10^18)

输出
共T行，如果A获胜输出A，如果B获胜输出B。

输入样例
3
3 5
3 4
1 9

输出样例
B
A
A


#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 55
#define mod 1000000000
using namespace std;
typedef long long ll;

int t, n, m, k, a, b, ans, which, num[maxn], arr[maxn];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

ll temp[3] = {618033988,749894848,204586834};


int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        if(x > y){
            swap(x, y);
        }
        ll p = y - x;
        ll p_1 = p / mod;
        ll p_2 = p % mod;
        ll p_3 = p_2 * temp[2];
        p_3 = p_1 * temp[2] + p_2 * temp[1] + p_3 / mod;
        p_3 = p_1 * temp[1] + p_2 * temp[0] + p_3 / mod;
        p_3 = p_1 * temp[0] + p_3 / mod + p;
        if(p_3 == x){
            printf("B\n");
        }else{
            printf("A\n");
        }
    }
    return 0;
}
