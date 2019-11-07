//HDU 2604
Problem Description
Queues and Priority Queues are data structures which are known to most computer scientists. The Queue occurs often in our daily life. 
There are many people lined up at the lunch time.


Now we define that ‘f’ is short for female and ‘m’ is short for male. If the queue’s length is L, then there are 2L numbers of queues.
For example, if L = 2, then they are ff, mm, fm, mf . If there exists a subqueue as fmf or fff, we call it O-queue else it is a E-queue.
Your task is to calculate the number of E-queues mod M with length L by writing a program.
 

Input
Input a length L (0 <= L <= 10 6) and M.
 

Output
Output K mod M(1 <= M <= 30) where K is the number of E-queues with length L.
 

Sample Input
3 8
4 7
4 8
 

Sample Output
6
2
1




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 4
#define mod 1000000009
using namespace std;
typedef long long ll;;

int t, sum[maxn], arr[maxn], add[maxn];
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
    while( scanf("%lld %lld", &l, &m) != EOF ){
        if( l == 0 ){
            printf("0\n");
            continue;
        }
        mat a, re;
        a.g[0][0] = a.g[0][2] = a.g[0][3] = 1;
        a.g[1][0] = 1;
        a.g[2][1] = 1;
        a.g[3][2] = 1;
        re.g[0][0] = 9;
        re.g[1][0] = 6;
        re.g[2][0] = 4;
        re.g[3][0] = 2;
        if(l <= 4){
            printf("%lld\n", re.g[4 - l][0] % m);
        }else{
            a = mat_quick_pow(a, l - 4);
            re = multi(a, re);
            printf("%lld\n", re.g[0][0] % m);
        }
    }
    return 0;
}
