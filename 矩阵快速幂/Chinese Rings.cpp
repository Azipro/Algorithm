//HDU 2842
Problem Description
Dumbear likes to play the Chinese Rings (Baguenaudier). It’s a game played with nine rings on a bar. The rules of this game are very
simple: At first, the nine rings are all on the bar.
The first ring can be taken off or taken on with one step.
If the first k rings are all off and the (k + 1)th ring is on, then the (k + 2)th ring can be taken off or taken on with one step. 
(0 ≤ k ≤ 7)

Now consider a game with N (N ≤ 1,000,000,000) rings on a bar, Dumbear wants to make all the rings off the bar with least steps. 
But Dumbear is very dumb, so he wants you to help him.
 

Input
Each line of the input file contains a number N indicates the number of the rings on the bar.
The last line of the input file contains a number "0".
 

Output
For each line, output an integer S indicates the least steps. For the integers may be very large, output S mod 200907.
 

Sample Input
1
4
0
 

Sample Output
1
10





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 3
#define mod 200907
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
    while( scanf("%lld", &n), n ){
        if(n == 1){
            printf("1\n");
            continue;
        }
        if(n == 2){
            printf("2\n");
            continue;
        }
        mat a;
        a.g[0][0] = a.g[0][2] = 1;
        a.g[0][1] = 2;
        a.g[1][0] = a.g[2][2] = 1;
        mat re;
        re.g[0][0] = 2;
        re.g[1][0] = 1;
        re.g[2][0] = 1;
        a = mat_quick_pow(a, n - 2);
        re = multi(a, re);
        printf("%lld\n", re.g[0][0] % mod);
    }
    return 0;
}
