void init(){
    re[0] = 1;
    for(int i = 1; i <= 19 ; i++){
        for(int j = 0; j < i ; j++){
            re[i] += re[j] * re[i - j - 1];
        }
    }
}

 
void DO(int pstr, int len, int pst, int pt){
	if(pt == len){
		t[pt] = 0;
		l.insert(t);
		return;
	}
	if(pstr < len){
		st[pst] = str[pstr];
		DO(pstr + 1, len, pst + 1, pt);
	}
	if(pst > 0){
		char c = st[pst - 1];
		t[pt] = st[pst - 1];
		DO(pstr, len, pst - 1, pt + 1);
		st[pst - 1] = c;
	}
}
