//HDU 3068
Problem Description
给出一个只由小写英文字符a,b,c...y,z组成的字符串S,求S中最长回文串的长度.
回文就是正反读都是一样的字符串,如aba, abba等
 

Input
输入有多组case,不超过120组,每组输入为一行小写英文字符a,b,c...y,z组成的字符串S
两组case之间由空行隔开(该空行不用处理)
字符串长度len <= 110000
 

Output
每一行一个整数x,对应一组case,表示该组case的字符串中所包含的最长回文长度.
 

Sample Input
aaaa

abab
 

Sample Output
4
3



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 330005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], prefix[maxn];
bool vis[maxn];
char str[maxn], s[maxn];

void init(){
    str[0] = '$';
    str[1] = '#';
    for(int i = 0; i < m ; i++){
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    n = m * 2 + 2;
    str[n] = '*';
}

void manacher(){
    int id = 0, mx = 0;
    for(int i = 1; i < n ; i++){
        if(mx > i) arr[i] = min(arr[2 * id - i], mx - i);
        else{
            arr[i] = 1;
        }
        while( str[i + arr[i]] == str[i - arr[i]] ) arr[i]++;
         if(arr[i] + i > mx){
            mx = arr[i] + i;
            id = i;
        }
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while( scanf("%s", s) != EOF ){
        m = strlen(s);
        init();
        manacher();
        ans = 0;
        for(int i = 0; i < n ; i++){
            ans = max(ans, arr[i]);
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
