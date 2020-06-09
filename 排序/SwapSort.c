/*冒泡排序
	空间复杂度：O(1)
	时间复杂度：
		最好情况，表中元素已经有序。 O(n)
		最坏情况，表中元素逆序。 O(n^2)
		平均情况，O(n^2)
	稳定性：稳定
	冒泡排序中所产生的有序子序列一定是全局有序的，
	每趟排序都会将一个元素放置到其最终的位置上。
*/
void Bubble_Sort(int *A, int n){
	int flag;
	for(int i = 0 ; i < n - 1 ; i++){
		flag = 0;
		for(int j = n - 1 ; j > i ; j--){
			if(A[j] < A[j - 1]){
				int t = A[j];
				A[j] = A[j - 1];
				A[j - 1] = t;
				flag = 1;
			}
		}
		if(!flag){
			break;
		}
	}
}


/*快速排序
	空间复杂度：
		最好情况，O(log₂n)
		最坏情况，O(n)
		平均情况，O(log₂n)
	时间复杂度：
		最好情况，O(nlog₂n)
		最坏情况，极度不对称，O(n^2)
		平均情况，O(nlog₂n)
	稳定性：不稳定
	快速排序过程中不产生有序子序列，但每趟排序后
	会将枢轴(基准)元素放到最终的位置上。
*/
int Partition(int *A, int low, int high){
	int povit = A[low];
	while(low < high){
		while(low < high && A[high] >= povit) high--;
		A[low] = A[high];
		while(low < high && A[low] <= povit) low++;
		A[high] = A[low];
	}
	A[low] = povit;
	return low;
}
void Quick_Sort(int *A, int low, int high){
	if(low < high){
		int partition = Partition(A, low, high);
		Quick_Sort(A, low, partition - 1);
		Quick_Sort(A, partition + 1, high);
	}
}
