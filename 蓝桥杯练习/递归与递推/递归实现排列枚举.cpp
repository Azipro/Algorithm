//《算法竞赛进阶指南》
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> v;

void dfs(int x, int u){
    if(x >= n){
        for(int i : v) printf("%d ", i);
        puts("");
        return ;
    }
    for(int i = 0 ; i < n ; i ++){
        if(!(u >> i & 1)){
            v.push_back(i + 1);
            dfs(x + 1, u | 1 << i);
            v.pop_back();
        }
    }
}

int main(){
    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}