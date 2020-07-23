#include<iostream>
#include<vector>
using namespace std;

void Counting_sort(vector<int> &q, int size){
    vector<int> cnt(101, 0); // 每个数的数值在0~100
    for(int i = 0 ; i < size ; i++) cnt[q[i]]++;
    for(int i = 0, k = 0 ; i <= 100 ; i++){
        while(cnt[i]--){
            q[k++] = i;
        }
    }
}

int main(){
    int n;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];

    Counting_sort(v, n);
    for(auto i : v) cout << i << " ";
    cout << endl;
    return 0;
}