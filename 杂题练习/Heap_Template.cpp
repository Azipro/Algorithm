#include <iostream>
#include <vector>
using namespace std;

// 大根堆
void push_down(vector<int> &heap, int size, int u){
    int t = u, left = u << 1, right = (u << 1) + 1;
    if(left <= size && heap[left] > heap[t]) t = left;
    if(right <= size && heap[right] > heap[t]) t = right;
    if(t != u){
        swap(heap[u], heap[t]);
        push_down(heap, size, t);
    }
}

void push_up(vector<int> &heap, int u){
    while(u >> 1 && heap[u >> 1] < heap[u]){
        swap(heap[u], heap[u >> 1]);
        u >>= 1;
    }
}

void insert(vector<int> &heap, int &size, int x){
    heap[++size] = x;
    push_up(heap, size);
}

void remove_top(vector<int> &heap, int &size){
    heap[1] = heap[size--];
    push_down(heap, size, 1);
}

void heap_sort(vector<int> &heap, int n){
    int size = n;
   // for(int i = 1 ; i <= n ; i++) push_up(heap, i);  // 自顶向下建堆，O(nlogn) 裂项求和
    for(int i = n >> 1 ; i >= 1 ; i--) push_down(heap, size, i); // 自底向上建堆，O(n) 裂项求和
    
    for(int i = 1 ; i <= n ; i++){
        swap(heap[1], heap[size]);
        size--;
        push_down(heap, size, 1);
    }
}

int main(){
    int n, t;
    vector<int> v;
    cin >> n;
    v.resize(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> v[i];
    heap_sort(v, n);
    for(int i = 1 ; i <= n ; i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}