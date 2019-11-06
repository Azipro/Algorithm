int quick_pow(int x, int n){
	int base = x;
	int ans = 1;
	while(n){
		if(n & 1){
			ans *= base;
		}
		base *= base;
		n >>= 1;
	}
	return ans;
}
