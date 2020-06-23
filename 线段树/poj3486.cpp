#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<algorithm>
#define maxn 1005
using namespace std;

int n, M, sum[maxn * 4], arr[maxn + 5];

void pushup(int t) {
    sum[t] = max(sum[t << 1] ,sum[t << 1 | 1]);
}

void build(int l, int r, int t) {
    if(l == r) {
        sum[t] = arr[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, t << 1);
    build(m + 1, r, t << 1 | 1);
    pushup(t);
}

void update(int L, int l, int r, int t) {
    if(l == r) {
        sum[t] = arr[L];
        return;
    }
    int m = (r + l) >> 1;
    if(L <= m) {
        update(L, l, m, t << 1);
    } else {
        update(L, m + 1, r, t << 1 | 1);
    }
    pushup(t);
}


int query(int L, int R, int l, int r, int t) {
    if(L <= l && r <= R) {
        return sum[t];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if(L <= m) {
        ans = max(ans,query(L, R, l, m, t << 1));
    }
    if(R > m) {
        ans = max(ans,query(L, R, m + 1, r, t << 1 | 1));
    }
    return ans;
}

int dp[maxn][maxn];

int main() {
    //freopen("Test.txt", "r", stdin);
    int c;
    while( scanf("%d", &c) != EOF ) {
        scanf("%d", &n);
        for(int i = 1; i <= n ; i++){
            for(int j = i; j <= n ; j++){
                scanf("%d", &dp[i][j]);
            }
        }
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = i ; j <= n ; j++){
                if(i == 1){
                    dp[i][j] = dp[i][j] + c;
                }else{
                    if(dp[i - 1][i - 1] + c + dp[i][j] < dp[i - 1][j]){
                        dp[i][j] = dp[i - 1][i - 1] + c + dp[i][j];
                    }else{
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}
