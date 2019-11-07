//HDU 4763
Problem Description
It's time for music! A lot of popular musicians are invited to join us in the music festival. Each of them will play one of their 
representative songs. To make the programs more interesting and challenging, the hosts are going to add some constraints to the rhythm 
of the songs, i.e., each song is required to have a 'theme section'. The theme section shall be played at the beginning, the middle, 
and the end of each song. More specifically, given a theme section E, the song will be in the format of 'EAEBE', where section A and 
section B could have arbitrary number of notes. Note that there are 26 types of notes, denoted by lower case letters 'a' - 'z'.

To get well prepared for the festival, the hosts want to know the maximum possible length of the theme section of each song. Can you help 
us?
 

Input
The integer N in the first line denotes the total number of songs in the festival. Each of the following N lines consists of one string, 
indicating the notes of the i-th (1 <= i <= N) song. The length of the string will not exceed 10^6.
 

Output
There will be N lines in the output, where the i-th line denotes the maximum possible length of the theme section of the i-th song.
 

Sample Input
5
xy
abc
aaa
aaaaba
aaxoaaaaa
 

Sample Output
0
0
1
1
2




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 1000005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], pre[maxn], prefix[maxn];
bool is, vis[maxn];
char s[maxn], str[maxn];

void setPrefix(){
    int i = 0;
    int len = -1;
    prefix[0] = -1;
    while(i < m){
        if(len == -1 || s[i] == s[len]){
            len++;
            i++;
            prefix[i] = len;
        }else{
            len = prefix[len];
        }
    }
}

void setPrefix_v1(int lenth){
    int i = 0;
    int len = -1;
    pre[0] = -1;
    while(i < lenth){
        if(len == -1 || str[i] == str[len]){
            len++;
            i++;
            pre[i] = len;
        }else{
            len = pre[len];
        }
    }
}

bool KMP(int strat){
    int i = strat;
    int j = 0;
    while(i < m - strat && j < strat){
        if(j == -1 || s[i] == str[j]){
            i++;
            j++;
        }else{
            j = pre[j];
        }
        if(j == strat){
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        scanf("%s", s);
        m = strlen(s);
        is = false;
        setPrefix();
        int p = prefix[m];
        if(p == 0){
            printf("0\n");
            continue;
        }
        while(!is){
            if( p == -1 || p == 0){
                printf("0\n");
                break;
            }
            for(int i = 0; i < p ; i++){
                str[i] = s[i];
            }
            setPrefix_v1(p);
            if( KMP(p) ){
                printf("%d\n", p);
                is = true;
            } else{
                p = prefix[p];
            }
        }
    }
    return 0;
}
