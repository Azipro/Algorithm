//HDU 1575
Problem Description
A为一个方阵，则Tr A表示A的迹（就是主对角线上各项的和），现要求Tr(A^k)%9973。
 

Input
数据的第一行是一个T，表示有T组数据。
每组数据的第一行有n(2 <= n <= 10)和k(2 <= k < 10^9)两个数据。接下来有n行，每行有n个数据，每个数据的范围是[0,9]，表示方阵A的内容。
 

Output
对应每组数据，输出Tr(A^k)%9973。
 

Sample Input
2
2 2
1 0
0 1
3 99999999
1 2 3
4 5 6
7 8 9
 

Sample Output
2
2686




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 15
#define mod 9973
using namespace std;
typedef long long ll;;

int t, n, sum[maxn], arr[maxn], add[maxn];
int times, which;
bool is;
ll l, m;

struct mat{
    ll g[maxn][maxn];
    mat(){
        memset(g, 0, sizeof(g));
    }
};

mat multi(mat &a, mat &b){
    mat c;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                c.g[i][j] = (a.g[i][k] * b.g[k][j] + c.g[i][j]) % mod;
            }
        }
    }
    return c;
}

mat mat_quick_pow(mat a, ll x){
    mat b;
    for(int i = 0 ; i < n ; i++){
        b.g[i][i] = 1;
    }
    while(x){
        if(x & 1){
            b = multi(b, a);
        }
        a = multi(a, a);
        x >>= 1;
    }
    return b;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        ll k;
        mat a;
        scanf("%d %lld", &n, &k);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                scanf("%lld", &a.g[i][j]);
            }
        }
        a = mat_quick_pow(a, k);
        ll ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = (ans + a.g[i][i]) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
