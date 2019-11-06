void init(){
    re[0] = 1;
    for(int i = 1; i <= 35 ; i++){
        for(int j = 0; j < i ; j++){
            re[i] += re[j] * re[i - j - 1];
        }
    }
}
