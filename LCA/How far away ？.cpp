//HDU 2586
Problem Description
There are n houses in the village and some bidirectional roads connecting them. 
Every day peole always like to ask like this "How far is it if I want to go from house A to house B"? Usually it hard to answer. 
But luckily int this village the answer is always unique, since the roads are built in the way that there is a unique simple
path("simple" means you can't visit a place twice) between every two houses. Yout task is to answer all these curious people.
 

Input
First line is a single integer T(T<=10), indicating the number of test cases.
For each test case,in the first line there are two numbers n(2<=n<=40000) and m (1<=m<=200),the number of houses and the number of 
queries.The following n-1 lines each consisting three numbers i,j,k, separated bu a single space, meaning that there is a 
road connecting house i and house j,with length k(0<k<=40000).The houses are labeled from 1 to n.
Next m lines each has distinct integers i and j, you areato answer the distance between house i and house j.
 

Output
For each test case,output m lines. Each line represents the answer of the query. Output a bland line after each test case.
 

Sample Input
2
3 2
1 2 10
3 1 15
1 2
2 3

2 2
1 2 100
1 2
2 1
 

Sample Output
10
25
100
100



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 40005
#define mod 10007
using namespace std;
typedef long long ll;;

int t, n, m, pos[maxn], sign[maxn * 2], to[maxn * 2], val[maxn * 2], deep[maxn], dis[maxn];
int gather[maxn][20];
int ans, times;
bool vis[maxn];

void init(int x, int y, int cost){
    sign[++ans] = pos[x];
    pos[x] = ans;
    to[ans] = y;
    val[ans] = cost;
}

void dfs(int x){
    int p, son;
    p = pos[x];
    while(p){
        son = to[p];
        if(!vis[son]){
            vis[son] = true;
            gather[son][0] = x;
            deep[son] = deep[x] + 1;
            dis[son] = dis[x] + val[p];
            int k = 0, at = x;
            while(gather[at][k] != 0){
                gather[son][k + 1] = gather[at][k];
                at = gather[at][k];
                k++;
            }
            dfs(son);
        }
        p = sign[p];
    }
}

int lca(int x, int y){
    if(deep[x] < deep[y]) swap(x, y);
    m = 0;
    while( (1 << m) <= deep[x] ) m++;
    m--;
    for(int i = m ; i >= 0; i--){
        if(deep[x] - (1 << i) >= deep[y]) x = gather[x][i];
    }
    if(x == y) return y;
    for(int i = m ; i >= 0 ; i--){
        if(gather[x][i] != gather[y][i]){
            x = gather[x][i];
            y = gather[y][i];
        }
    }
    return gather[x][0];
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        ans = 0;
        scanf("%d %d", &n, &times);
        for(int i = 0 ; i < maxn ; i++){
            pos[i] = dis[i] = deep[i] = 0;
            vis[i] = false;
        }
        for(int i = 0 ; i < 2 * maxn ; i++){
            sign[i] = to[i] = val[i] = 0;
        }
        memset(gather, 0, sizeof(gather));
        int x, y, cost;
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d %d %d", &x, &y, &cost);
            init(x, y, cost);
            init(y, x, cost);
        }
        deep[1] = 1;
        dis[1] = 0;
        vis[1] = true;
        dfs(1);
        while( times-- ){
            scanf("%d %d", &x, &y);
            printf("%d\n", dis[x] + dis[y] - 2 * dis[lca(x, y)]);
        }
    }
    return 0;
}

