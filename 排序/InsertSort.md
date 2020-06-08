/*直接插入排序
	空间复杂度：O(1)
	时间复杂度：
		最好情况，表中元素已经有序。 O(n)
		最坏情况，表中元素逆序。 O(n^2)
		平均情况，O(n^2)
	稳定性：稳定
	适用性：使用于顺序存储和链式存储的线性表	
*/
void Straight_Insert_Sort(int *A, int n){
	int i, j;
	for(i = 2 ; i <= n ; i++){
		if(A[i] < A[i - 1]){
			A[0] = A[i];
			for(j = i - 1 ; A[0] < A[j] ; j--){
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}

/*折半插入排序
	空间复杂度：O(1)
	时间复杂度：
		比较次数与待排序表的初始状态无关
		平均情况，O(n^2)
	稳定性：稳定
	适用性：使用于顺序存储的线性表
*/
void Binary_Insert_Sort(int *A, int n){
	int i, j, low, high, mid;
	for(int i = 2 ; i <= n ; i++){
		A[0] = A[i];
		low = 1;
		high = i - 1;
		while(low <= high){
			mid = (low + high) >> 1;
			if(A[mid] > A[0]) high = mid - 1;
			else low = mid + 1;
		}
		for( j = i - 1 ; j > high ; j--){
			A[j + 1] = A[j];
		}
		A[high + 1] = A[0];
	}
}

/*希尔排序
	空间复杂度：O(1)
	时间复杂度：
		n在某个特定范围内，O(n^1.3)
		平均情况，O(n^2)
	稳定性：不稳定
	适用性：使用于顺序存储的线性表
*/
void Shell_Sort(int *A, int n){
	int i, j, dk;
	for(dk = n / 2; dk >= 1; dk >>= 1){
		for(i = dk + 1 ; i <= n ; i++){
			if(A[i] < A[i - dk]){
				A[0] = A[i];
				for(j = i - dk ; j > 0 && A[0] < A[j] ; j -= dk){
					A[j + dk] = A[j];
				}
				A[j + dk] = A[0];
			}
		}
	}
}
