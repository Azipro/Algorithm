//《算法竞赛进阶指南》
#include <iostream>
#include <vector>
using namespace std;

char map[5][5];
int MAX = 2147483647;
vector<pair<int, int> >v, backup;

void change(int x, int y){
    for(int i = 0 ; i < 4 ; i++){
        if(map[x][i] == '-') map[x][i] = '+';
        else map[x][i] = '-';
    }
    for(int i = 0 ; i < 4 ; i++){
        if(map[i][y] == '-') map[i][y] = '+';
        else map[i][y] = '-';
    }
    if(map[x][y] == '+') map[x][y] = '-';
    else map[x][y] = '+';
}

bool check(){
    for(int i = 0 ; i < 4 ; i ++){
        for(int j = 0 ; j < 4 ; j ++){
            if(map[i][j] == '+') return false;
        }
    }
    return true;
}

void dfs(int x, int y){
    if(x == 3 && y == 4){
        if(check()){
            if(backup.size() < v.size() || !v.size()){
                v = backup;
            }
        }
        return ;
    }
        
    if(y == 4) x++, y = 0;
    backup.push_back(make_pair(x, y));
    change(x, y);
    
    dfs(x, y + 1);
    
    backup.pop_back();
    change(x, y);
    
    dfs(x, y + 1);
    
    return ;
}

int main(){
    for(int i = 0 ; i < 4 ; i ++){
        scanf("%s", map[i]);
    }
    v.clear(), backup.clear();
    
    dfs(0, 0);
    
    printf("%d\n", v.size());
    for(auto i : v) printf("%d %d\n", i.first + 1, i.second + 1);
    return 0;
}

```
void dfs(int x, int y){
    if(x == 4){ // x == 4 || check() 
        if(check()){
            if(backup.size() < v.size() || !v.size()){
                v = backup;
            }
        }
        return ;
    }
    
    backup.push_back(make_pair(x, y));
    change(x, y);
    
    if(y == 3) dfs(x + 1, 0);
    else dfs(x, y + 1);
    
    backup.pop_back();
    change(x, y);
    
    if(y == 3) dfs(x + 1, 0);
    else dfs(x, y + 1);
    
    return ;
}
```