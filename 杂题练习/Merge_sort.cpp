#include <iostream>
#include <vector>
using namespace std;

int merge_sort(vector<int> &q, int l, int r){
    if(l >= r) return 0;
    
    int count = 0; //逆序对个数
    int mid = (l + r) >> 1;
    count += merge_sort(q, l, mid);
    count += merge_sort(q, mid + 1, r);
    
    static vector<int> m;
    m.clear();
    
    int i, j;
    for(i = l, j = mid + 1 ; i <= mid && j <= r ; ){
        if(q[i] <= q[j]){
            m.push_back(q[i++]);
        }else{
            count += mid - i + 1;
            m.push_back(q[j++]);
        }
    }
    
    while(i <= mid) m.push_back(q[i++]);
    while(j <= r) m.push_back(q[j++]);
    
    for(i = 0, j = l ; i < (int)m.size() ; i++, j++) q[j] = m[i];
    return count;
}

int main(){
    vector<int> arr;
    arr.clear();
    int n, t;
    cin >> n;
    while(n--){
        cin >> t;
        arr.push_back(t);   
    }
    cout << merge_sort(arr, 0, (int)arr.size() - 1) << endl;
    for(auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
}