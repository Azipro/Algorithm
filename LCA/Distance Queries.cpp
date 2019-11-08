//POJ 1986
Description
Farmer John's cows refused to run in his marathon since he chose a path much too long for their leisurely lifestyle.
He therefore wants to find a path of a more reasonable length. The input to this problem consists of the same input as in "Navigation 
Nightmare",followed by a line containing a single integer K, followed by K "distance queries". 
Each distance query is a line of input containing two integers, giving the numbers of two farms between which FJ is interested in 
computing distance (measured in the length of the roads along the path between the two farms). Please answer FJ's distance queries as 
quickly as possible!

Input
* Lines 1..1+M: Same format as "Navigation Nightmare"
* Line 2+M: A single integer, K. 1 <= K <= 10,000
* Lines 3+M..2+M+K: Each line corresponds to a distance query and contains the indices of two farms.

Output
* Lines 1..K: For each distance query, output on a single line an integer giving the appropriate distance.

Sample Input
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
3
1 6
1 4
2 6

Sample Output
13
3
36

Hint
Farms 2 and 6 are 20+3+13=36 apart.


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
        char ch;
        for(int i = 0 ; i < times ; i++){
            scanf("%d %d %d %c", &x, &y, &cost, &ch);
            init(x, y, cost);
            init(y, x, cost);
        }
        deep[1] = 1;
        dis[1] = 0;
        vis[1] = true;
        dfs(1);
        scanf("%d", &times);
        while( times-- ){
            scanf("%d %d", &x, &y);
            printf("%d\n", dis[x] + dis[y] - 2 * dis[lca(x, y)]);
        }
    return 0;
}
