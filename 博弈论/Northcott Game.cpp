//HDU 1730
Problem Description
　　Tom和Jerry正在玩一种Northcott游戏，可是Tom老是输，因此他怀疑这个游戏是不是有某种必胜策略，郁闷的Tom现在向你求救了，你能帮帮他么？
游戏规则是这样的：
　　如图所示，游戏在一个n行m列（1 ≤ n ≤ 1000且2 ≤ m ≤ 100）的棋盘上进行，每行有一个黑子（黑方）和一个白子（白方）。
  执黑的一方先行，每次玩家可以移动己方的任何一枚棋子到同一行的任何一个空格上，当然这过程中不许越过该行的敌方棋子。
双方轮流移动，直到某一方无法行动为止，移动最后一步的玩家获胜。Tom总是先下（黑方）。
图1是某个初始局面，图二是Tom移动一个棋子后的局面（第一行的黑子左移两步）。


Input
输入数据有多组。每组数据第一行为两个整数n和m，由空格分开。接下来有n行，每行两个数Ti，Ji (1 ≤ Ti, Ji ≤ m)分别表示Tom和Jerry在该行棋子
所处的列数。
注意：各组测试数据之间有不定数量的空行。你必须处理到文件末。
 

Output
对于每组测试数据输出一行你的结果。如果当前局面下Tom有必胜策略则输出“I WIN!”，否则输出“BAD LUCK!”。
 

Sample Input
3 6
4 5
1 2
1 2

3 6
4 5
1 3
1 2
 

Sample Output
BAD LUCK!
I WIN!



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 1010
#define mod 1.61803398874979
using namespace std;
typedef long long ll;

int t, n, m, k, a, b, ans, which, num[maxn], arr[maxn];
bool is, vis[maxn];
int sg[maxn];
char ch, s[maxn], str[maxn];

void getsg(){
    memset(sg, 0, sizeof(sg));
    for(int i = 1 ; i <= maxn ; i++){
        memset(vis, false, sizeof(vis));
        for(int j = 0 ; arr[j] <= i && j <= 16; j++){
                vis[sg[ i - arr[j] ]] = true;
        }
        for(int j = 0; ; j++){
            if(!vis[j]){
                sg[i] = j;
                break;
            }
        }
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while( scanf("%d %d", &n, &m) != EOF ){
        ans = 0;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d %d", &a, &b);
            if(a < b){
                ans ^= (b - a - 1);
            }else{
                ans ^= (a - b - 1);
            }
        }
        if(ans == 0){
            printf("BAD LUCK!\n");
        }else{
            printf("I WIN!\n");
        }
    }
    return 0;
}
