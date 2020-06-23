#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 200005
#define mod 10007
using namespace std;
typedef long long ll;;

int t, n, k, sum[maxn * 4], arr[maxn + 5], add[maxn * 4];
int times, which;
bool is;
int h, w;

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
    arr[t] = w;
    if(l == r) {
        //sum[t] = arr[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, t << 1);
    build(m + 1, r, t << 1 | 1);
    //pushup(t);
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

int query(int L, int R, int l, int r, int t) {
    if(L <= l && r <= R) {
        return sum[t];
    }
    int m = (l + r) >> 1;
    pushdown(m - l + 1, r - m, t);
    int ans = 0;
    if(L <= m) {
        ans += query(L, R, l, m, t << 1);
    }
    if(R > m) {
        ans += query(L, R, m + 1, r, t << 1 | 1);
    }
    return ans;
}

int query(int c, int l, int r, int t){
    if(l == r){
        arr[t] -= c;
        return l;
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if(arr[t << 1] >= c) {
        ans = query(c, l, m, t << 1);
    }else{
        ans = query(c, m + 1, r, t << 1 | 1);
    }
    arr[t] = max(arr[t << 1], arr[t << 1 | 1]);
    return ans;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    while( scanf("%d %d %d", &h, &w, &n) !=EOF ){
        if(h > n) h = n;
        build(1, h, 1);
        while( n-- ){
            scanf("%d", &k);
            if(k > arr[1]){
                printf("-1\n");
            }else{
                printf("%d\n", query(k, 1, h, 1));
            }
        }
    }
    return 0;
}
