//HDU 1358
Problem Description
For each prefix of a given string S with N characters (each character has an ASCII code between 97 and 126, inclusive), we want to know 
whether the prefix is a periodic string. That is, for each i (2 <= i <= N) we want to know the largest K > 1 (if there is one) such that 
the prefix of S with length i can be written as AK , that is A concatenated K times, for some string A. Of course, we also want to know 
the period K.
 

Input
The input file consists of several test cases. Each test case consists of two lines. The first one contains N (2 <= N <= 1 000 000) – the 
size of the string S. The second line contains the string S. The input file ends with a line, having the number zero on it.
 

Output
For each test case, output “Test case #” and the consecutive test case number on a single line; then, for each prefix with length i that 
has a period K > 1, output the prefix size i and the period K separated by a single space; the prefix sizes must be in increasing order. 
Print a blank line after each test case.
 

Sample Input
3
aaa
12
aabaabaabaab
0
 

Sample Output
Test case #1
2 2
3 3

Test case #2
2 2
6 2
9 3
12 4




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<map>
#define maxn 1000005
#define mod 998244353
using namespace std;

int n, which, prefix[maxn];
char s[maxn];

void setPrefix(){
    int i = 1;
    int len = 0;
    prefix[0] = 0;
    while(i < n){
        if(s[i] == s[len]){
            len++;
            prefix[i] = len;
            i++;
        }else{
            if(len > 0){
                len = prefix[len - 1];
            }else{
                prefix[i] = len;
                i++;
            }
        }
    }
}

void re_prefix(){
    for(int i = n; i > 0; i--){
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    which = 1;
    while(scanf("%d", &n) && n != 0){
        scanf("%s", s);
        setPrefix();
        re_prefix();
        printf("Test case #%d\n", which++ );
        for(int i = 0; i <= n; i++){
            if(prefix[i] != 0 && prefix[i] != -1){
                if(i % (i - prefix[i]) == 0){
                    printf("%d %d\n", i, i / (i - prefix[i]));
                }
            }
        }
        cout << endl;
    }
    return 0;
}
