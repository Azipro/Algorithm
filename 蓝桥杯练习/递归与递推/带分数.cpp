//第四届蓝桥杯省赛C++B组
#include <iostream>
#include <cstring>
using namespace std;

typedef long long int ll;

const int maxn = 10;
int n, ans;
int st[maxn], backup[maxn];

bool check(int a, int c){
    ll b = c * (ll)n - c * a;
    if(!a || !b || !c) return false;

    memcpy(backup, st, sizeof st);

    while(b){
        int p = b % 10;
        b /= 10;
        if(!p || backup[p]) return false;
        backup[p] = 1;
    }
    for(int i = 1; i <= 9; i ++){
        if(!backup[i]) return false;
    }
    return true;
}

void dfs_next(int a, int c){
    if(check(a, c)) ans ++;

    for(int i = 1; i <= 9; i ++){
        if(!st[i]){
            st[i] = 1;
            dfs_next(a, c * 10 + i);
            st[i] = 0;
        }
    }
}

void dfs(int a){
    if(a >= n) return ;
    if(a) dfs_next(a, 0);

    for(int i = 1; i <= 9; i ++){
        if(!st[i]){
            st[i] = 1;
            dfs(a * 10 + i);
            st[i] = 0;
        }
    }
}

int main(){
    cin >> n;

    dfs(0);

    cout << ans << endl;
    return 0;
}