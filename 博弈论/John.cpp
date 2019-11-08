//HDU 1907
Problem Description
Little John is playing very funny game with his younger brother. There is one big box filled with M&Ms of different colors. 
At first John has to eat several M&Ms of the same color. Then his opponent has to make a turn. And so on. 
Please note that each player has to eat at least one M&M during his turn. 
If John (or his brother) will eat the last M&M from the box he will be considered as a looser and he will have to buy a new candy box.

Both of players are using optimal game strategy. John starts first always. You will be given information about M&Ms and your task is to 
determine a winner of such a beautiful game.

 

Input
The first line of input will contain a single integer T – the number of test cases. Next T pairs of lines will describe tests in a 
following format. The first line of each test will contain an integer N – the amount of different M&M colors in a box. 
Next line will contain N integers Ai, separated by spaces – amount of M&Ms of i-th color.

Constraints:
1 <= T <= 474,
1 <= N <= 47,
1 <= Ai <= 4747

 

Output
Output T lines each of them containing information about game winner. Print “John” if John will win the game or “Brother” in other case.

 

Sample Input
2
3
3 5 1
1
1
 

Sample Output
John
Brother




#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 1010
#define mod 1.61803398874979
using namespace std;
typedef long long ll;

int t, n, m, k, a, b, ans, which, num[maxn], arr[maxn];
bool is, vis[maxn];
int sg[maxn];
char ch, s[maxn], str[maxn];

void getsg(){
    memset(sg, 0, sizeof(sg));
    for(int i = 1 ; i <= maxn ; i++){
        memset(vis, false, sizeof(vis));
        for(int j = 0 ; arr[j] <= i && j <= 16; j++){
                vis[sg[ i - arr[j] ]] = true;
        }
        for(int j = 0; ; j++){
            if(!vis[j]){
                sg[i] = j;
                break;
            }
        }
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        ans = 0;
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &arr[i]);
            if(arr[i] >= 2) ans++;
        }
        if(ans == 1){
            printf("John\n");
        }else{
            k = 0;
            for(int i = 1; i <= n ; i++){
                k ^= arr[i];
            }
            if(k == 0){
                if(ans > 1){
                    printf("Brother\n");
                }else{
                    printf("John\n");
                }
            }else{
                if(ans > 1){
                    printf("John\n");
                }else{
                    printf("Brother\n");
                }
            }
        }
        
    }
    return 0;
}
