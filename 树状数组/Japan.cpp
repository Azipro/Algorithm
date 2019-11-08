//POJ 3067
Description
Japan plans to welcome the ACM ICPC World Finals and a lot of roads must be built for the venue. Japan is tall island with N cities on the
East coast and M cities on the West coast (M <= 1000, N <= 1000). 
K superhighways will be build. Cities on each coast are numbered 1, 2, ... from North to South. 
Each superhighway is straight line and connects city on the East coast with city of the West coast. 
The funding for the construction is guaranteed by ACM. A major portion of the sum is determined by the number of crossings between 
superhighways. At most two superhighways cross at one location.
Write a program that calculates the number of the crossings between superhighways.

Input
The input file starts with T - the number of test cases. Each test case starts with three numbers – N, M, K. 
Each of the next K lines contains two numbers – the numbers of cities connected by the superhighway. 
The first one is the number of the city on the East coast and second one is the number of the city of the West coast.

Output
For each test case write one line on the standard output:
Test case (case number): (number of crossings)

Sample Input
1
3 4 4
1 4
2 3
3 2
3 1

Sample Output
Test case 1: 5



#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 500005
#define mod 10007
using namespace std;
typedef long long ll;

int t, n, m, a, b, which, num[maxn];
ll ans, arr[maxn];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

struct Rode{
    int east, west;
}rode[maxn];

bool cmp(Rode a, Rode b){
    return a.east != b.east ? (a.east < b.east) : (a.west < b.west);
}

int lowbit(int x){
    return x & (-x);
}

ll query(int x){
    ll re = 0;
    while(x > 0){
        re += arr[x];
        x -= lowbit(x);
    }
    return re;
}

void add(int x, int val){
    while(x <= m){
        arr[x] += val;
        x += lowbit(x);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    which = 1;
    while( t-- ){
        int k;
        scanf("%d %d %d", &n, &m, &k);
        ans = 0;
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < k ; i++){
            scanf("%d %d", &rode[i].east, &rode[i].west);
        }
        sort(rode, rode + k, cmp);
        for(int i = 0; i < k ; i++){
            ans += i - query(rode[i].west);
            add(rode[i].west, 1);
        }
        printf("Test case %d: %lld\n", which++, ans);
    }
    return 0;
}
