//HDU2087
Problem Description
一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
 

Input
输入中含有一些数据，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。如果遇见#字符，则不再进行工作。
 

Output
输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就老老实实输出0，每个结果之间应换行。
 

Sample Input
abcde a3
aaaaaa  aa
#
 

Sample Output
0
3
3




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<map>
#define maxn 1005
using namespace std;

int ans;
int n, m, prefix[maxn];
char s[maxn], in[maxn];

void setPrefix() {
    int i = 0;
    int len = -1;
    prefix[0] = -1;
    while(i < m) {
        if(len == -1 || in[i] == in[len]) {
            len++;
            i++;
            prefix[i] = len;
        } else {
            len = prefix[len];
        }
    }
}

void KMP() {
    int i = 0;
    int j = 0;
    while(i < n && j < m) {
        if(j == -1 || s[i] == in[j]) {
            i++;
            j++;
        } else {
            j = prefix[j];
        }
        if(j == m) {
            ans++;
            j = 0;
        }
    }
}

int main() {
    //freopen("text.txt", "r", stdin);
    while(scanf("%s", s)) {
        if(s[0] == '#') {
            break;
        }
        ans = 0;
        scanf("%s", in);
        n = strlen(s);
        m = strlen(in);
        setPrefix();
        KMP();
        printf("%d\n", ans);
    }
    return 0;
}
