//整数二分
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    int n, q, k, in;
    scanf("%d %d", &n, &q);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d", &in);
        v.push_back(in);
    }

    while(q--){
        scanf("%d", &k);
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(v[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if(v[l] == k) printf("%d ", l);
        else{
            printf("-1 -1\n");
            continue;
        }
        l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) >> 1; // 向上取整，防止死循环
            if(v[mid] <= k) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}