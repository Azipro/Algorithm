//HDU 1757
Problem Description
Lele now is thinking about a simple function f(x).

If x < 10 f(x) = x.
If x >= 10 f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + …… + a9 * f(x-10);
And ai(0<=i<=9) can only be 0 or 1 .

Now, I will give a0 ~ a9 and two positive integers k and m ,and could you help Lele to caculate f(k)%m.
 

Input
The problem contains mutiple test cases.Please process to the end of file.
In each case, there will be two lines.
In the first line , there are two positive integers k and m. ( k<2*10^9 , m < 10^5 )
In the second line , there are ten integers represent a0 ~ a9.
 

Output
For each case, output f(k) % m in one line.
 

Sample Input
10 9999
1 1 1 1 1 1 1 1 1 1
20 500
1 0 1 0 1 0 1 0 1 0
 

Sample Output
45
104



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 10
#define mod 1000000009
using namespace std;
typedef long long ll;;

int t, sum[maxn], arr[maxn], add[maxn];
int times, which;
bool is;
ll m, k;

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
                c.g[i][j] = (a.g[i][k] * b.g[k][j] + c.g[i][j]) % m;
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
    while( scanf("%lld %lld", &k, &m) != EOF ){
        if(k < 10){
            printf("%lld\n", k % m);
            continue;
        }
        mat a, re;
        ll ans = 0;
        for(int i = 0 ; i < maxn ; i++){
            scanf("%lld", &a.g[0][i]);
        }
        for(int i = 1 ; i < maxn ; i++){
            a.g[i][i - 1] = 1;
        }
        for(int i = 0 ; i < maxn ; i++){
            re.g[i][0] = maxn - i - 1;
        }
        a = mat_quick_pow(a, k - 9);
        re = multi(a, re);
        printf("%lld\n", re.g[0][0] % m);
    }
    return 0;
}
