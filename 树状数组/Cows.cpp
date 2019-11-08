//POJ 2481
Description
Farmer John's cows have discovered that the clover growing along the ridge of the hill (which we can think of as a one-dimensional number 
line) in his field is particularly good.
Farmer John has N cows (we number the cows from 1 to N). Each of Farmer John's N cows has a range of clover that she particularly likes 
(these ranges might overlap). The ranges are defined by a closed interval [S,E].
But some cows are strong and some are weak. Given two cows: cowi and cowj, their favourite clover range is [Si, Ei] and [Sj, Ej]. 
If Si <= Sj and Ej <= Ei and Ei - Si > Ej - Sj, we say that cowi is stronger than cowj.
For each cow, how many cows are stronger than her? Farmer John needs your help!

Input
The input contains multiple test cases.
For each test case, the first line is an integer N (1 <= N <= 105), which is the number of cows. 
Then come N lines, the i-th of which contains two integers: S and E(0 <= S < E <= 105) specifying the start end location respectively 
of a range preferred by some cow. Locations are given as distance from the start of the ridge.
The end of the input contains a single 0.

Output
For each test case, output one line containing n space-separated integers, the i-th of which specifying the number of cows that 
are stronger than cowi.

Sample Input
3
1 2
0 3
3 4
0

Sample Output
1 0 0

Hint
Huge input and output,scanf and printf is recommended.


#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 100010
#define mod 10007
using namespace std;
typedef long long ll;

int t, n, m, a, b, which, num[maxn], ans, arr[maxn];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

struct COW{
    int S, E;
    int id;
}cow[maxn];

bool cmp(COW a, COW b){
    return a.S == b.S ? (a.E > b.E) : (a.S < b.S);
}

int lowbit(int x){
    return x & (-x);
}

int query(int x){
    int re = 0;
    while(x > 0){
        re += arr[x];
        x -= lowbit(x);
    }
    return re;
}

void add(int x, int val){
    while(x <= 100001){
        arr[x] += val;
        x += lowbit(x);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while( scanf("%d", &n) && n != 0 ){
        for(int i = 0 ; i < n ; i++){
            scanf("%d %d", &cow[i].S, &cow[i].E);
            cow[i].id = i;
        }
        memset(arr, 0, sizeof(arr));
        memset(num, 0, sizeof(num));
        sort(cow, cow + n, cmp);
        for(int i = 0; i < n ; i++){
            if( i != 0 && cow[i].S == cow[i - 1].S && cow[i].E == cow[i - 1].E){
                num[ cow[i].id ] = num[ cow[i - 1].id ];
            }else{
                num[ cow[i].id ] = query(100001) - query( cow[i].E - 1);
            }
            add(cow[i].E, 1);
        }
        for(int i = 0; i < n ; i++){
            int p = num[i];
            printf("%d%c", p, i == (n - 1) ? '\n' : ' ');
        }
    }
    return 0;
}
