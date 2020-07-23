#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Quick_sort(vector<int> &v, int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, pivot = v[l + r >> 1];
    while(i < j){
        do i++; while(v[i] < pivot);
        do j--; while(v[j] > pivot);
        if(i < j) swap(v[i], v[j]);
        else Quick_sort(v, l, j), Quick_sort(v, j + 1, r);
    }
}

int main(){
    int n, t;
    vector<int> v;
    v.clear();
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> t;
        v.push_back(t);
    }
    Quick_sort(v, 0, v.size() - 1);
    for(auto i : v) cout << i << " ";
    cout << endl;
    return 0;
}