#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    vector<int> f;
    cin >> n >> m;
    f.resize(m + 1, 0);
    int v, w;
    for(int i = 1 ; i <= n ; i++){
        cin >> v >> w;
        // for(int j = m ; j >= v ; j--) 0-1背包
        for(int j = v ; j <= m ; j++) // 完全背包
            f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m] << endl;
    return 0;
}