//HDU 3294
Problem Description
One day, sailormoon girls are so delighted that they intend to research about palindromic strings. Operation contains two steps:
First step: girls will write a long string (only contains lower case) on the paper. For example, "abcde", but 'a' inside is not the 
real 'a', that means if we define the 'b' is the real 'a', then we can infer that 'c' is the real 'b', 'd' is the real 'c' ……, 'a' is 
the real 'z'. According to this, string "abcde" changes to "bcdef".
Second step: girls will find out the longest palindromic string in the given string, the length of palindromic string must be equal or 
more than 2.
 

Input
Input contains multiple cases.
Each case contains two parts, a character and a string, they are separated by one space, the character representing the real 'a' is and 
the length of the string will not exceed 200000.All input must be lowercase.
If the length of string is len, it is marked from 0 to len-1.
 

Output
Please execute the operation following the two steps.
If you find one, output the start position and end position of palindromic string in a line, next line output the real palindromic string,
or output "No solution!".
If there are several answers available, please choose the string which first appears.
 

Sample Input
b babd
a abcd
 

Sample Output
0 2
aza
No solution!





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 600005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], prefix[maxn];
bool vis[maxn];
char ch, str[maxn], s[maxn];

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

int manacher(){
    int id = 0, mx = 0;
    int at = 0;
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
        if(ans < arr[i]){
            ans = arr[i];
            at = i;
        }
    }
    return at;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while( cin >> ch ){
        scanf("%s", s);
        m = strlen(s);
        int p = int(ch - 'a');
        for(int i = 0 ; i < m ; i++){
            if( int(s[i]) - p < 97 ){
                s[i] = char(s[i] - p + 26);
            }else{
                s[i] = char(s[i] - p);
            }
        }
        ans = 0;
        init();
        int where = manacher();
        ans--;
        if(ans < 2){
            printf("No solution!");
        }else{
            int x = where - ans + 1;
            int y = where + ans - 1;
            printf("%d %d\n", (x - 2) / 2, (y - 2) / 2);
            for(int i = (x - 2) / 2; i <= (y - 2) / 2; i++)
                printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}
