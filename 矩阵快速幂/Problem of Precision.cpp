//HDU 2256
Problem Description
求sqrt(sqrt(2) + sqrt(3)) ^ 2n MOD 1024


Input
The first line of input gives the number of cases, T. T test cases follow, each on a separate line. Each test case contains one positive integer n. (1 <= n <= 10^9)
 

Output
For each input case, you should output the answer in one line.
 

Sample Input
3
1
2
5
 

Sample Output
9
97
841




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 2
#define mod 1024
using namespace std;
typedef long long ll;;

int t, sum[maxn], arr[maxn], add[maxn];
int times, which;
bool is;
ll n, m;

struct mat{
    ll g[maxn][maxn];
    mat(){
        memset(g, 0, sizeof(g));
    }
};

mat multi(mat &a, mat &b){
    mat c;
    for(int i = 0 ; i < maxn ; i++){
        for(int j = 0 ; j < maxn ; j++){
            for(int k = 0 ; k < maxn ; k++){
                c.g[i][j] = (a.g[i][k] * b.g[k][j] + c.g[i][j]) % mod;
            }
        }
    }
    return c;
}

mat mat_quick_pow(mat a, ll x){
    mat b;
    for(int i = 0 ; i < maxn ; i++){
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
        scanf("%lld", &n);
        if( n == 1 ){
            printf("9\n");
            continue;
        }
        mat a;
        a.g[0][0] = 5;
        a.g[0][1] = 12;
        a.g[1][0] = 2;
        a.g[1][1] = 5;
        mat re;
        re.g[0][0] = 5;
        re.g[1][0] = 2;
        a = mat_quick_pow(a, n - 1);
        re = multi(a, re);
        printf("%lld\n", (2 * re.g[0][0] - 1) % mod);
        
    }
    return 0;
}
