//HDU 2276
Problem Description
There are n lights in a circle numbered from 1 to n. The left of light 1 is light n, and the left of light k (1< k<= n) is the light k-1.
At time of 0, some of them turn on, and others turn off.
Change the state of light i (if it's on, turn off it; if it is not on, turn on it) at t+1 second (t >= 0), if the left of light i is on !!!
Given the initiation state, please find all lights’ state after M second. (2<= n <= 100, 1<= M<= 10^8)

 

Input
The input contains one or more data sets. The first line of each data set is an integer m indicate the time, the second line will be a 
string T, only contains '0' and '1' , and its length n will not exceed 100. It means all lights in the circle from 1 to n.
If the ith character of T is '1', it means the light i is on, otherwise the light is off.

 

Output
For each data set, output all lights' state at m seconds in one line. It only contains character '0' and '1.
 

Sample Input
1
0101111
10
100000001
 

Sample Output
1111000
001000010





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 105
#define mod 2
using namespace std;
typedef long long ll;;

int t, sum[maxn], arr[maxn], add[maxn];
int times, which;
char s[maxn];
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
    while( scanf("%lld", &m) != EOF ){
        scanf("%s", s);
        n = strlen(s);
        mat a;
        a.g[0][0] = 1;
        a.g[0][n - 1] = 1;
        for(int i = 1 ; i < n ; i++){
            a.g[i][i - 1] = a.g[i][i] = 1;
        }
        mat re;
        for(int i = 0 ; i < n ; i++ ){
            re.g[i][0] = s[i] - '0';
        }
        a = mat_quick_pow(a, m);
        re = multi(a, re);
        for(int i = 0 ; i < n ; i++){
            printf("%d", re.g[i][0]);
        }
        printf("\n");
    }
    return 0;
}
