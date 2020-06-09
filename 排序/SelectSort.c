/*简单选择排序
	空间复杂度：O(1)
	时间复杂度：
		最好情况，元素移动操作 0次
		最坏情况，元素移动操作 3(n-1)次
		平均情况，比较次数与序列初始状态无关，n(n-1)/2
				 O(n^2)
	稳定性：不稳定
	每趟排序都会将一个元素放置到其最终的位置上。
*/
void Select_Sort(int *A, int n){
	int min;
	for(int i = 0 ; i < n - 1; i++){
		min = i;
		for(int j = i + 1 ; j < n ; j++){
			if(A[j] < A[min]) min = j;
		}
		if(min != i){
			int t = A[min];
			A[min] = A[i];
			A[i] = t;
		}
	}
}



/*堆排序
	空间复杂度：O(1)
	时间复杂度：
		建堆时间为O(n)
		n - 1次向下调整操作，每次操作O(n)
		最好、最坏和平均情况，O(nlog₂n)
	稳定性：不稳定
	适合关键字较多的情况。
	A[0]为哨兵。
*/
void Heap_Adjust(int *A, int n, int k){
	A[0] = A[k];
	for(int i = k << 1 ; i <= n ; i <<= 1){
		if(i < n && A[i] > A[i + 1]){
			i++;
		}
		if(A[0] <= A[i]) break;
		A[k] = A[i];
		k = i;
	}
	A[k] = A[0];
}

void Build_Heap(int *A, int n){
	for(int i = n >> 1 ; i > 0 ; i--){
		Heap_Adjust(A, n, i);
	}
}

void Heap_Sort(int *A, int n){
	Build_Heap(A, n);
	for(int i = n ; i > 0 ; i--){
		int t = A[i];
		A[i] = A[1];
		A[1] = t;

		Heap_Adjust(A, i - 1, 1);
	}
}
