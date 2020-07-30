//《算法竞赛进阶指南》
```
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> v;

void dfs(int x, bool is){
    if(v.size() && is){
        for(auto i : v) printf("%d ", i);
        puts("");
    }
    if(x > n) return;
    
    v.push_back(x);
    dfs(x + 1, true);
    
    v.pop_back();
    dfs(x + 1, false);
}

int main(){
    scanf("%d", &n);
    
    puts("");
    dfs(1, true);
    
    return 0;
}
```

```
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;

void dfs(int x, int u){ // u的第i位代表第i个数有没有被选
    if(x >= n){
        for(int i = 0; i < n ;i ++){
            if(u >> i & 1){
                printf("%d ", i + 1);
            }
        }
        puts("");
        return;
    }
    

    dfs(x + 1, u | 1 << x);
    
    dfs(x + 1, u);
    
}

int main(){
    scanf("%d", &n);
    
    dfs(0, 0);
    
    return 0;
}
```