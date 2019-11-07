//51Nod-1242

斐波那契数列的定义如下：

F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) (n >= 2)

(1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, ...)
给出n，求F(n)，由于结果很大，输出F(n) % 1000000009的结果即可。

Input
输入1个数n(1 <= n <= 10^18)。

Output
输出F(n) % 1000000009的结果。

Sample Input
11

Sample Output
89





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 2
#define mod 1000000009
using namespace std;
typedef long long ll;;

int t, n, k, sum[maxn], arr[maxn], add[maxn];
int times, which;
bool is;

struct mat{
    ll fibo[maxn][maxn];
    mat(){
        memset(fibo, 0, sizeof(fibo));
    }
};

mat multi(mat &a, mat &b){
    mat c;
    for(int i = 0 ; i < maxn ; i++){
        for(int j = 0 ; j < maxn ; j++){
            for(int k = 0 ; k < maxn ; k++){
                c.fibo[i][j] = (a.fibo[i][k] * b.fibo[k][j] + c.fibo[i][j]) % mod;
            }
        }
    }
    return c;
}

void mat_quick_pow(mat a, ll x){
    mat b;
    b.fibo[0][0] = b.fibo[1][1] = 1;
    while(x){
        if(x & 1){
            b = multi(b, a);
        }
        a = multi(a, a);
        x >>= 1;
    }
    printf("%lld\n", b.fibo[1][0]);
}

int main() {
    //freopen("Test.txt", "r", stdin);
    ll m;
    scanf("%lld", &m);
    mat x;
    x.fibo[0][0] = x.fibo[0][1] = x.fibo[1][0] = 1;
    mat_quick_pow(x, m);
    return 0;
}
