#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 100005
#define mod 10007
using namespace std;

typedef long long ll;

int t, n, m, a, b, which, num[maxn];
ll arr[maxn * 4];
ll ans;
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

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
    while(x <= maxn * 3){
        arr[x] += val;
        x += lowbit(x);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while( scanf("%d", &n) != EOF ){
        int ans = 0;
        memset(arr, 0, sizeof(arr));
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &num[i]);
            ans += (i - query(num[i] + 1));
            add(num[i] + 1, 1);
        }
        int re = ans;
        for(int i = 0 ; i < n ; i++){
            ans -= num[i];
            ans += n - 1 - num[i];
            re = min(re, ans);
        }
        printf("%d\n", re);
    }
    return 0;
}
