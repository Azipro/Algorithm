int n, v[26], w[26], x[55], y[55], last, last2;

int main(){
    //freopen("Test.txt", "r", stdin);
    scanf("%d", &n);
    while(n--){
        for(int i = 0 ; i < 26 ; i++){
            scanf("%d", &w[i]);
            v[i] = i + 1;
        }
        x[0] = 1;
        last = 0;
        for(int i = 0; i < 26 ; i++){
            last2 = min(50, last + v[i] * w[i]);
            memset(y, 0, sizeof(int) * (last2 + 1));
            for(int j = 0; j <= w[i] && j * v[i] <= last2 ; j++){
                for(int k = 0; k <= last && k + j * v[i] <= last2; k++){
                    y[k + j * v[i]] += x[k];
                }
            }
            memcpy(x, y, sizeof(int) * (last2 + 1));
            last = last2;
        }
        int sum = 0;
        for(int i = 1; i <= 50; i++){
            sum += x[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}
