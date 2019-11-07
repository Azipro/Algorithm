//POJ 2752
Description

The little cat is so famous, that many couples tramp over hill and dale to Byteland, and asked the little cat to give names to their 
newly-born babies. They seek the name, and at the same time seek the fame. In order to escape from such boring job, the innovative little 
cat works out an easy but fantastic algorithm:

Step1. Connect the father's name and the mother's name, to a new string S.
Step2. Find a proper prefix-suffix string of S (which is not only the prefix, but also the suffix of S).

Example: Father='ala', Mother='la', we have S = 'ala'+'la' = 'alala'. Potential prefix-suffix strings of S are {'a', 'ala', 'alala'}. 
Given the string S, could you help the little cat to write a program to calculate the length of possible prefix-suffix strings of S? 
(He might thank you by giving your baby a name:)

Input

The input contains a number of test cases. Each test case occupies a single line that contains the string S described above.

Restrictions: Only lowercase letters may appear in the input. 1 <= Length of S <= 400000.
Output

For each test case, output a single line with integer numbers in increasing order, denoting the possible length of the new baby's name.

Sample Input

ababcababababcabab
aaaaa

Sample Output

2 4 9 18
1 2 3 4 5




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
bool is;

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
    for(int i = n; i > 0; i--){
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

void show(int len){
    if(prefix[len] == 0){
        return ;
    }
    show(prefix[len]);
        printf("%d ", prefix[len]);
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        setPrefix();
        re_Prefix();
        show(n);
        printf("%d\n", n);
    }
    return 0;
}
