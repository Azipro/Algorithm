#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<algorithm>
#define maxn 200000
using namespace std;

int N, M, sum[maxn * 4], add[maxn * 4];
int p, k, a[maxn + 5];
char in;

void pushup(int t) {
    sum[t] = max(sum[t << 1] ,sum[t << 1 | 1]);
}

void build(int l, int r, int t) {
    if(l == r) {
        sum[t] = a[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, t << 1);
    build(m + 1, r, t << 1 | 1);
    pushup(t);
}

void update(int L, int l, int r, int t) {
    if(l == r) {
        sum[t] = a[L];
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


int main() {
    while(cin >> N >> M && N != 0) {
        for(int i = 1; i <= N; i++) {
            scanf("%d", &a[i]);
        }
        build(1, N, 1);
        while(M--) {
            cin >> in >> p >> k;
            if(in == 'Q') {
                cout << query(p, k, 1, N, 1) << endl;
            } else {
                a[p] = k;
                update(p, 1, N, 1);
            }
        }
    }
    return 0;
}
