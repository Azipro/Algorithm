//POJ 2406
Description

Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". 
If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" 
(the empty string) and a^(n+1) = a*(a^n).

Input

Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not 
exceed 1 million characters. A line containing a period follows the last test case.

Output

For each s you should print the largest n such that s = a^n for some string a.

Sample Input

abcd
aaaa
ababab
.

Sample Output

1
4
3

Hint

This problem has huge input, use scanf instead of cin to avoid time limit exceed.



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<map>
#define maxn 1000005
#define mod 998244353
using namespace std;

int n, prefix[maxn];
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

void re_Prefix(){
    for(int i = n; i > 0 ; i--){
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while(scanf("%s", s) != EOF){
        if(s[0] == '.'){
            break;
        }
        n = strlen(s);
        setPrefix();
        re_Prefix();
        if(n % (n - prefix[n]) == 0){
            cout << n / (n - prefix[n]) << endl;
        }else{
            cout << "1" << endl;
        }
    }
    return 0;
}
