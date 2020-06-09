/*归并排序
	空间复杂度：O(n)
	时间复杂度：
		每趟归并的时间复杂度为O(n)
		共需 ⌈log₂n⌉趟归并
		O(nlog₂n)
	稳定性：稳定
*/
void Merge(int *A, int low, int mid, int high, int n){
	int *sup = (int *)malloc(n * sizeof(int));
	for(int i = low ; i <= high ; i++){
		sup[i] = A[i];
	}
	int i, j;
	int k = low;
	for(i = low, j = mid + 1; i <= mid && j <= high ; ){
		if(sup[i] <= sup[j]){
			A[k++] = sup[i++];
		}else{
			A[k++] = sup[j++];
		}
	}
	while(i <= mid) A[k++] = sup[i++];
	while(j <= high) A[k++] = sup[j++];
}

void Merge_Sort(int *A, int low, int high, int n){
	if(low < high){
		int mid = (low + high) >> 1;
		Merge_Sort(A, low, mid, n);
		Merge_Sort(A, mid + 1, high, n);
		Merge(A, low, mid, high, n);
	}
}
