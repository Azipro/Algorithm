//HDU 3584
Problem Description
Given an N*N*N cube A, whose elements are either 0 or 1. A[i, j, k] means the number in the i-th row , j-th column and k-th layer. 
Initially we have A[i, j, k] = 0 (1 <= i, j, k <= N).
We define two operations, 1: “Not” operation that we change the A[i, j, k]=!A[i, j, k]. that means we change A[i, j, k] from 0->1,or 1->0.
(x1<=i<=x2,y1<=j<=y2,z1<=k<=z2).
0: “Query” operation we want to get the value of A[i, j, k].
 

Input
Multi-cases.
First line contains N and M, M lines follow indicating the operation below.
Each operation contains an X, the type of operation. 1: “Not” operation and 0: “Query” operation.
If X is 1, following x1, y1, z1, x2, y2, z2.
If X is 0, following x, y, z.
 

Output
For each query output A[x, y, z] in one line. (1<=n<=100 sum of m <=10000)
 

Sample Input
2 5
1 1 1 1  1 1 1
0 1 1 1
1 1 1 1  2 2 2
0 1 1 1
0 2 2 2
 

Sample Output
1
0
1




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 105
#define mod 10007
using namespace std;
typedef long long ll;

int t, n, m, a, b, which, num[maxn], ans, arr[maxn][maxn][maxn];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

int lowbit(int x){
    return x & (-x);
}

int query(int x, int y, int z){
    int re = 0;
    while(x > 0){
        for(int i = y; i > 0 ;){
            for(int j = z; j > 0;){
                re += arr[x][i][j];
                j -= lowbit(j);
            }
            i -= lowbit(i);
        }
        x -= lowbit(x);
    }
    return re;
}

void add(int x, int y, int z, int val){
    while(x <= n){
        for(int i = y; i <= n ;){
            for(int j = z; j <= n ;){
                arr[x][i][j] += val;
                j += lowbit(j);
            }
            i += lowbit(i);
        }
        x += lowbit(x);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while( scanf("%d %d", &n, &m) != EOF ){
    memset(arr, 0, sizeof(arr));
    while( m-- ){
        scanf("%d", &t);
        if(t == 1){     
            int x1, y1, z1, x2, y2, z2;
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            add(x1, y1, z1, 1);
            add(x2 + 1, y2 + 1, z1, 1);
            add(x2 + 1, y1, z1, 1);
            add(x1, y2 + 1, z2 + 1, 1);
            add(x1, y2 + 1, z1, 1);
            add(x2 + 1, y1, z2 + 1, 1);
            add(x1, y1, z2 + 1, 1);
            add(x2 + 1, y2 + 1, z2 + 1, 1);
        }else{
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            printf("%d\n", query(x, y, z) % 2);
        }
    }
}
    return 0;
}
