/*基数排序
	空间复杂度：一共使用r个队列，O(r)
	时间复杂度：
		需要d趟分配和收集
		一趟分配需要O(n)
		一趟收集需要O(r)
		O(d(n+r))
	稳定性：稳定
	与序列初始状态无关。
*/
queue<int> q[10];

void init(){
	for(int i = 0 ; i < 10 ; i++){
		while(!q[i].empty()) q[i].pop();
	}
}

void Radix_Sort(int *A, int bitNum, int r, int n){
	int bitGet = 1;
	while(bitNum--){
		for(int i = 0 ; i < n ; i++){
			int bit = (A[i] / bitGet) % 10;
			q[bit].push(A[i]);
		}
		int k = 0;
		for(int i = 0 ; i < r ; i++){
			while(!q[i].empty()){
				A[k++] = q[i].front();
				q[i].pop();
			}
		}
		bitGet *= 10;
	}
}
