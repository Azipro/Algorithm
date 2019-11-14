//POJ 2155
Description
Given an N*N matrix A, whose elements are either 0 or 1. A[i, j] means the number in the i-th row and j-th column. 
Initially we have A[i, j] = 0 (1 <= i, j <= N).
We can change the matrix in the following way. Given a rectangle whose upper-left corner is (x1, y1) and lower-right corner is (x2, y2),
we change all the elements in the rectangle by using "not" operation (if it is a '0' then change it into '1' otherwise change it 
into '0'). To maintain the information of the matrix, you are asked to write a program to receive and execute two kinds of instructions.

1. C x1 y1 x2 y2 (1 <= x1 <= x2 <= n, 1 <= y1 <= y2 <= n) changes the matrix by using the rectangle whose upper-left corner is 
(x1, y1) and lower-right corner is (x2, y2).
2. Q x y (1 <= x, y <= n) querys A[x, y].


Input
The first line of the input is an integer X (X <= 10) representing the number of test cases. The following X blocks each represents 
a test case.
The first line of each block contains two numbers N and T (2 <= N <= 1000, 1 <= T <= 50000) representing the size of the matrix and 
the number of the instructions. The following T lines each represents an instruction having the format "Q x y" or "C x1 y1 x2 y2", which 
has been described above.

Output
For each querying output one line, which has an integer representing A[x, y].
There is a blank line between every two continuous test cases.

Sample Input
1
2 10
C 2 1 2 2
Q 2 2
C 2 1 2 1
Q 1 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
Q 1 1
C 1 1 2 1
Q 2 1

Sample Output
1
0
0
1


//二维树状数组，也可以用二维线段树写
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 1005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn][maxn], num[maxn];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

int lowbit(int x){
    return x & (-x);
}

int query(int x, int y){
    int re = 0;
    while(x > 0){
        for(int i = y; i > 0 ;){
            re += arr[x][i];
            i -= lowbit(i);
        }
        x -= lowbit(x);
    }
    return re;
}

void add(int x, int y, int val){
    while(x <= n){
        for(int i = y; i <= n ;){
            arr[x][i] += val;
            i += lowbit(i);
        }
        x += lowbit(x);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        scanf("%d %d", &n, &m);
        memset(arr, 0, sizeof(arr));
        while( m-- ){
            cin >> ch;
            if( ch == 'C' ){
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                add(x1, y1, 1);
                add(x2 + 1, y1, 1);
                add(x1, y2 + 1, 1);
                add(x2 + 1, y2 + 1, 1);
            }else{
                int x, y;
                scanf("%d %d", &x, &y);
                int re = query(x, y);
                if(re % 2 == 0){
                    printf("0\n");
                }else{
                    printf("1\n");
                }
            }
        }
        if(m) printf("\n");
    }
    return 0;
}
