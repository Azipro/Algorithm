//POJ 2309
Description
Consider an infinite full binary search tree (see the figure below), the numbers in the nodes are 1, 2, 3, .... 
In a subtree whose root node is X, we can get the minimum number in this subtree by repeating going down the left node until the 
last level, and we can also find the maximum number by going down the right node. Now you are given some queries as 
"What are the minimum and maximum numbers in the subtree whose root node is X?" Please try to find answers for there queries.

Input
In the input, the first line contains an integer N, which represents the number of queries. In the next N lines, each contains a number 
representing a subtree with root number X (1 <= X <= 2^31 - 1).

Output
There are N lines in total, the i-th of which contains the answer for the i-th query.

Sample Input
2
8
10

Sample Output
1 15
9 11




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 100010
#define mod 10007
using namespace std;
typedef long long ll;

int t, n, m, a, b, which, num[maxn], ans, arr[maxn];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

int lowbit(int x){
    return x & (-x);
}

int query(int x){
    int re = 0;
    while(x > 0){
        re += arr[x];
        x -= lowbit(x);
    }
    return re;
}

void add(int x, int val){
    while(x <= n){
        arr[x] += val;
        x += lowbit(x);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        scanf("%d", &n);
        int p = lowbit(n);
        printf("%d %d\n", n - p + 1, n + p - 1);
    }
    return 0;
}
