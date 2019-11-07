//HUD 2594
Problem Description
Homer: Marge, I just figured out a way to discover some of the talents we weren’t aware we had.
Marge: Yeah, what is it?
Homer: Take me for example. I want to find out if I have a talent in politics, OK?
Marge: OK.
Homer: So I take some politician’s name, say Clinton, and try to find the length of the longest prefix
in Clinton’s name that is a suffix in my name. That’s how close I am to being a politician like Clinton
Marge: Why on earth choose the longest prefix that is a suffix???
Homer: Well, our talents are deeply hidden within ourselves, Marge.
Marge: So how close are you?
Homer: 0!
Marge: I’m not surprised.
Homer: But you know, you must have some real math talent hidden deep in you.
Marge: How come?
Homer: Riemann and Marjorie gives 3!!!
Marge: Who the heck is Riemann?
Homer: Never mind.
Write a program that, when given strings s1 and s2, finds the longest prefix of s1 that is a suffix of s2.
 

Input
Input consists of two lines. The first line contains s1 and the second line contains s2. You may assume all letters are in lowercase.
 

Output
Output consists of a single line that contains the longest string that is a prefix of s1 and a suffix of s2, followed by the length of 
that prefix. If the longest such string is the empty string, then the output should be 0.
The lengths of s1 and s2 will be at most 50000.
 

Sample Input
clinton
homer
riemann
marjorie
 

Sample Output
0
rie 3





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<map>
#define maxn 50005
#define mod 998244353
using namespace std;

int n, len_1, len_2, prefix[maxn * 2];
char s[maxn * 2], in[maxn];

void setPrefix(){
    int i = 1;
    int len = 0;
    prefix[0] = -1;
    while(i < n){
        if(s[i] == s[len] || len == -1){
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
    while(scanf("%s %s", s, in) != EOF){
        len_1 = strlen(s);
        len_2 = strlen(in);
        strcat(s, in);
        n = strlen(s);
        setPrefix();
        int p = prefix[n];
        while(p > len_1 || p >len_2){
            p = prefix[p];
        }
        if(p == 0 || p == -1){
            printf("0\n");
        }else{
            for(int i = 0; i < p; i++){
                printf("%c", s[i]);
            }
            printf(" %d\n", p);
        }
    }
    return 0;
}
