//HDU 1848
Problem Description
任何一个大学生对菲波那契数列(Fibonacci numbers)应该都不会陌生，它是这样定义的：
F(1)=1;
F(2)=2;
F(n)=F(n-1)+F(n-2)(n>=3);
所以，1,2,3,5,8,13……就是菲波那契数列。
在HDOJ上有不少相关的题目，比如1005 Fibonacci again就是曾经的浙江省赛题。
今天，又一个关于Fibonacci的题目出现了，它是一个小游戏，定义如下：
1、  这是一个二人游戏;
2、  一共有3堆石子，数量分别是m, n, p个；
3、  两人轮流走;
4、  每走一步可以选择任意一堆石子，然后取走f个；
5、  f只能是菲波那契数列中的元素（即每次只能取1，2，3，5，8…等数量）；
6、  最先取光所有石子的人为胜者；

假设双方都使用最优策略，请判断先手的人会赢还是后手的人会赢。
 

Input
输入数据包含多个测试用例，每个测试用例占一行，包含3个整数m,n,p（1<=m,n,p<=1000）。
m=n=p=0则表示输入结束。
 

Output
如果先手的人能赢，请输出“Fibo”，否则请输出“Nacci”，每个实例的输出占一行。
 

Sample Input
1 1 1
1 4 1
0 0 0
 

Sample Output
Fibo
Nacci





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
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2 ; i < 17 ; i++){
        arr[i] = arr[ i - 1 ] + arr[ i - 2 ];
    }
    getsg();
    while(~scanf("%d %d %d", &m, &n, &k), m || n || k ){
        if( sg[m] ^ sg[n] ^ sg[k] ){
            printf("Fibo\n");
        }else{
            printf("Nacci\n");
        }
    }
    return 0;
}
