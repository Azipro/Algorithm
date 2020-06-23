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
typedef long long ll;;

int t, n, sum[maxn * 4], arr[maxn + 5], add[maxn * 4];
int times, which;

void pushup(int t) {
    sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

void pushdown(int l, int r, int t){
    if(add[t]){
        add[t << 1] = add[t];
        add[t << 1 | 1] = add[t];
        sum[t << 1] = add[t] * l;
        sum[t << 1 | 1] = add[t] * r;
        add[t] = 0;
    }
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

void update_p(int L, int l, int r, int t) {
    if(l == r) {
        sum[t] = arr[L];
        return;
    }
    int m = (r + l) >> 1;
    if(L <= m) {
        update_p(L, l, m, t << 1);
    } else {
        update_p(L, m + 1, r, t << 1 | 1);
    }
    pushup(t);
}

void update_q(int L, int R, int C, int l, int r, int t){
    if(L <= l && r <= R){
        sum[t] = C * (r - l + 1);
        add[t] = C;
        return ;
    }
    int m = (r + l) >> 1;
    pushdown(m - l + 1, r - m, t);
    if(L <= m){
        update_q(L, R, C, l, m, t << 1);
    }
    if(R > m){
        update_q(L, R, C, m + 1, r, t << 1 | 1);
    }
    pushup(t);
}


int query_p(int L, int R, int l, int r, int t) {
    if(L <= l && r <= R) {
        return sum[t];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if(L <= m) {
        ans += query_p(L, R, l, m, t << 1);
    }
    if(R > m) {
        ans += query_p(L, R, m + 1, r, t << 1 | 1);
    }
    return ans;
}

int query_q(int L, int R, int l, int r, int t) {
    if(L <= l && r <= R) {
        return sum[t];
    }
    int m = (l + r) >> 1;
    pushdown(m - l + 1, r - m, t);
    int ans = 0;
    if(L <= m) {
        ans += query_q(L, R, l, m, t << 1);
    }
    if(R > m) {
        ans += query_q(L, R, m + 1, r, t << 1 | 1);
    }
    return ans;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &arr[i]);
    }
    memset(add, 0, sizeof(add));
    build(1, n, 1);
    scanf("%d", &t);
    while( t-- ){
        int q;
        scanf("%d", &q);
        if(q == 1){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            update_q(x, y, z, 1, n, 1);
        }else{
            int x, y;
            scanf("%d %d", &x, &y);
            int res = query_q(x, y, 1, n, 1);
            printf("%d\n", res);
        }
    }
    return 0;
}
