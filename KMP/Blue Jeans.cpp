//POJ 3080
Description

The Genographic Project is a research partnership between IBM and The National Geographic Society that is analyzing DNA from hundreds of 
thousands of contributors to map how the Earth was populated.

As an IBM researcher, you have been tasked with writing a program that will find commonalities amongst given snippets of DNA that can be 
correlated with individual survey information to identify new genetic markers.

A DNA base sequence is noted by listing the nitrogen bases in the order in which they are found in the molecule. There are four bases: 
adenine (A), thymine (T), guanine (G), and cytosine (C). A 6-base DNA sequence could be represented as TAGACC.

Given a set of DNA base sequences, determine the longest series of bases that occurs in all of the sequences.
Input

Input to this problem will begin with a line containing a single integer n indicating the number of datasets. Each dataset consists of 
the following components:
A single positive integer m (2 <= m <= 10) indicating the number of base sequences in this dataset.
m lines each containing a single base sequence consisting of 60 bases.

Output

For each dataset in the input, output the longest base subsequence common to all of the given base sequences. If the longest common 
subsequence is less than three bases in length, display the string "no significant commonalities" instead. If multiple subsequences of 
the same longest length exist, output only the subsequence that comes first in alphabetical order.

Sample Input

3
2
GATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
3
GATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATACCAGATA
GATACTAGATACTAGATACTAGATACTAAAGGAAAGGGAAAAGGGGAAAAAGGGGGAAAA
GATACCAGATACCAGATACCAGATACCAAAGGAAAGGGAAAAGGGGAAAAAGGGGGAAAA
3
CATCATCATCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
ACATCATCATAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AACATCATCATTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT

Sample Output

no significant commonalities
AGATAC
CATCATCAT





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 65
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], prefix[maxn];
bool is, vis[maxn];
char s[maxn], str[15][maxn];
char st[maxn];

void setPrefix(int lenth){
    int i = 0;
    int len = -1;
    prefix[0] = -1;
    while(i < lenth){
        if(len == -1 || st[i] == st[len]){
            len++;
            i++;
            prefix[i] = len;
        }else{
            len = prefix[len];
        }
    }
}

bool KMP(int len, int x){
    int i = 0;
    int j = 0;
    while(i < 60 && j < len){
        if(j == -1 || st[j] == str[x][i]){
            i++; j++;
        }else{
            j = prefix[j];
        }
        if(j == len){
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        scanf("%d", &a);
        scanf("%s", &s);
        a--;
        for(int i = 0; i < a; i++){
            scanf("%s", str[i]);
        }
        ans = 0;
        char re[maxn];
        for(int k = 0; k <= 60 - 3 ; k++){
            for(int i = k + 3; i <= 60; i++){
                is = true;
                for(int p = 0; p < i - k ; p++){
                    st[p] = s[p + k];
                }
                setPrefix(i - k);
                for(int j = 0 ; j < a ; j++){
                    if( !KMP(i - k, j) ){
                        is = false;
                        break;
                    }
                }
                if(is && (i - k) >= ans){
                    if(ans == i - k){
                        bool iss = true;
                        for(int p = 0 ; p < i - k ; p++){
                                if(re[p] > st[p]){
                                    iss = false;
                                    break;
                                }
                        }
                        if( !iss ){
                            for(int p = 0 ; p < i - k ; p++){
                                re[p] = st[p];
                            }
                        }
                    }else{
                        for(int p = 0 ; p < i - k ; p++){
                            re[p] = st[p];
                        }
                    }
                    ans = i - k;
                }
            }
        }
        if(ans < 3){
            printf("no significant commonalities\n");
        }else{
            for(int i = 0; i < ans ; i++){
                printf("%c", re[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
