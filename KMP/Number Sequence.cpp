//HDU 1711
Problem Description
Given two sequences of numbers : a[1], a[2], ...... , a[N], and b[1], b[2], ...... , b[M] (1 <= M <= 10000, 1 <= N <= 1000000). 
Your task is to find a number K which make a[K] = b[1], a[K + 1] = b[2], ...... , a[K + M - 1] = b[M]. 
If there are more than one K exist, output the smallest one.
 

Input
The first line of input is a number T which indicate the number of cases. Each case contains three lines.
The first line is two numbers N and M (1 <= M <= 10000, 1 <= N <= 1000000). 
The second line contains N integers which indicate a[1], a[2], ...... , a[N]. 
The third line contains M integers which indicate b[1], b[2], ...... , b[M].
All integers are in the range of [-1000000, 1000000].
 

Output
For each test case, you should output one line which only contain K described above. If no such K exists, output -1 instead.
 

Sample Input
2
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 1 3
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 2 1
 

Sample Output
6
-1



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<map>
#define maxn 10005
using namespace std;

int t, n, m, prefix[maxn];
int s[maxn * 100], in[maxn];

void setPrefix() {
    int i = 1;
    int len = 0;
    prefix[0] = 0;
    while(i < m) {
        if(in[i] == in[len]) {
            len++;
            prefix[i] = len;
            i++;
        } else {
            if(len > 0) {
                len = prefix[len - 1];
            } else {
                prefix[i] = len;
                i++;
            }
        }
    }
}

void re_prefix() {
    for(int i = m; i >= 0; i--) {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

int KMP() {
    int i = 0;
    int j = 0;
    while(i < n) {
        if(j == m - 1 && s[i] == in[j]) {
            return i - j;
        }
        if(s[i] == in[j]) {
            i++;
            j++;
        } else {
            j = prefix[j];
            if(j == -1) {
                i++;
                j++;
            }
        }
    }
    return -1;
}

int main() {
    //freopen("text.txt", "r", stdin);
    cin >> t;
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d", &in[i]);
        }
        setPrefix();
        re_prefix();
        int ans = KMP();
        if(ans == -1) {
            cout << ans << endl;
        } else {
            cout << ans + 1 << endl;
        }
    }
    return 0;
}
