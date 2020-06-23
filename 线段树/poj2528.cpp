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

int t, n, k, sum[maxn * 4], arr[maxn + 5], add[maxn * 4];
int times, which;
bool is;

struct node{
    int l, r;
    bool vis;
}tree[maxn * 2];

struct point{
    int id, x;
}po[maxn * 2];

bool cmp_1(point a, point b){
    return a.x < b.x;
}

int cmp_2(point a, point b){
    if(a.id == b.id){
        return a.x < b.x;
    }
    return a.id > b.id;
}

void pushup(int t) {
    tree[t].vis = tree[t << 1].vis && tree[t << 1 | 1].vis;
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
    tree[t].l = l;
    tree[t].r = r;
    tree[t].vis = false;
    if(tree[t].l == tree[t].r) {
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, t << 1);
    build(m + 1, r, t << 1 | 1);
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

void query(int L, int R, int t) {
    if(tree[t].vis){
        return ;
    }
    if(tree[t].l == L && tree[t].r == R) {
        tree[t].vis = true;
        is = true;
        return ;
    }
    int m = (tree[t].l + tree[t].r) >> 1;
    if(R <= m) {
        query(L, R, t << 1);
    }else if(L >= m + 1) {
        query(L, R, t << 1 | 1);
    }else{
        query(L, m, t << 1);
        query(m + 1, R, t << 1 | 1);
    }
    pushup(t);
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &t);
    while( t-- ){
        scanf("%d", &n);
        for(int i = 0 ; i < 2 * n ; i += 2){
            scanf("%d %d", &po[i].x, &po[i + 1].x);
            po[i].id = po[i + 1].id = i;
        }
        sort(po, po + 2 * n, cmp_1);
        int a = 0, b = 0;
        for(int i = 0; i < 2 * n ; i ++ ){
            if(po[i].x == b){
                po[i].x = a;
            }else{
                b = po[i].x;
                po[i].x = ++a;
            }
        }
        build(1, 2 * n, 1);
        sort(po, po + 2 * n, cmp_2);
        int ans = 0;
        for(int i = 0 ; i < 2 * n ; i += 2){
            int l = po[i].x;
            int r = po[i + 1].x;
            is = 0;
            query(l, r, 1);
            if(is){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
