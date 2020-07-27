// 从 1~n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。 《算法竞赛进阶指南》
#include <iostream>
using namespace std;

int arr[50];
int n, m;

void dfs(int k, int len){
    if(len > m + 1 || n - k + 1 + len - 1 < m) return ;
    if(k == n + 1){
        for(int i = 1 ; i <= m ; i++) cout << arr[i] << " ";
        cout << endl;
        return ;
    }
    
    arr[len ++] = k;
    dfs(k + 1, len);
    len--;
    
    dfs(k + 1, len);
    
    return ;
}

int main(){
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}