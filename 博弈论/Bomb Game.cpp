//HDU 2873
Problem Description
John and Jack, two mathematicians, created a game called “Bomb Game” at spared time. This game is played on an n*m chessboard. 
A pair of integers (p, q) represents the grid at row p, column q. Some bombs were placed on the chessboard at the beginning. 
Every round, a player can choose to explode a bomb located at (p, q), and the exploded bomb will disappear. Furthermore:

1.If p>1 and q>1, the bomb will split up into two bombs located at (u, q) and (p, v), u<p, v<q, u and v are chosen by the player.
2.If p=1 and q>1, one new bomb will be produced, located at (p, v), v<q, v can be chosen freely by the player.
3.If q=1 and p>1, one new bomb will be produced, located at (u, q), u<p, u can be chosen freely by the player.


If two bombs located at the same position or a bomb located at (1, 1), they will be exploded automatically without producing new bombs.
Two players play in turn, until one player cannot explode the bombs and loses the game.
John always plays first.
Now, we’ll give you an initial situation, and you should tell us who will win at last. Assume John and Jack are smart enough, 
and they always do the best choice.
 

Input
There are several test cases, each one begins with two integers n and m, 0<n, m<=50, represents the number of rows and columns. 
Following by an n*m grid, describing the initial situation, ‘#’ indicates bomb.
The input is terminated by n=m=0.
 

Output
For each test case, output one line, the name of the winner.
 

Sample Input
2 2
.#
..
2 2
.#
.#
0 0
 

Sample Output
John
Jack




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 55
#define mod 1.61803398874979
using namespace std;
typedef long long ll;

int t, n, m, k, a, b, ans, which, num[maxn], arr[maxn];
bool is, vis[maxn * 60];
int sg[maxn][maxn];
char ch, s[maxn][maxn], str[maxn];

int getsg(int x, int y){
    memset(vis, false, sizeof(vis));
    for(int i = 0 ; i < x ; i++){
        for(int j = 0 ; j < y; j++){
                vis[sg[x][j] ^ sg[i][y]] = true;
        }
    }
    for(int j = 0; ; j++){
        if(!vis[j]){
            return j;
        }
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    memset(sg, -1, sizeof(sg));
    for(int i = 0 ; i < maxn ; i++){
        sg[i][0] = sg[0][i] = i;
    }
    for(int i = 1 ; i < maxn ; i++){
        for(int j = 1 ; j < maxn ; j++){
            sg[i][j] = getsg(i, j);
        }
    }
    while( scanf("%d %d", &n, &m), n || m ){
        ans = 0;
        for(int i = 0 ; i < n ; i++){
            scanf("%s", s[i]);
            for(int j = 0 ; j < m ; j++){
                if(s[i][j] == '#'){
                    ans ^= sg[i][j];
                }
            }
        }
        if(ans){
            printf("John\n");
        }else{
            printf("Jack\n");
        }
    }
    return 0;
}
