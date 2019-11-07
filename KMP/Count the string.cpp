//HDU 3336
Problem Description
It is well known that AekdyCoin is good at string problems as well as number theory problems. When given a string s, we can write down 
all the non-empty prefixes of this string. For example:
s: "abab"
The prefixes are: "a", "ab", "aba", "abab"
For each prefix, we can count the times it matches in s. So we can see that prefix "a" matches twice, "ab" matches twice too, 
"aba" matchesonce, and "abab" matches once. Now you are asked to calculate the sum of the match times for all the prefixes. 
For "abab", it is 2 + 2 + 1 + 1 = 6.
The answer may be very large, so output the answer mod 10007.
 

Input
The first line is a single integer T, indicating the number of test cases.
For each case, the first line is an integer n (1 <= n <= 200000), which is the length of string s. A line follows giving the string s.
The characters in the strings are all lower-case letters.
 

Output
For each case, output only one number: the sum of the match times for all the prefixes of s mod 10007.
 

Sample Input
1
4
abab
 

Sample Output
6



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 200005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], prefix[maxn];
bool is, vis[maxn];
char s[maxn], str[maxn];

void setPrefix(){
    int i = 0;
    int len = -1;
    prefix[0] = -1;
    while(i < n){
        if(len == -1 || s[i] == s[len]){
            len++;
            i++;
            prefix[i] = len;
        }else{
            len = prefix[len];
        }
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        ans = 0;
        scanf("%d", &n);
        scanf("%s", s);
        setPrefix();
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= n ; i++){
            arr[i] = (arr[prefix[i]] + 1) % mod;
            ans = (ans + arr[i]) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
