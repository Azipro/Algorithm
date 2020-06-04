#include<stdio.h>
#include<stdlib.h>

typedef struct{
	unsigned int w;
	unsigned int parent, lchild, rchild;
}Htree;

typedef char** Hcode;

int getMin(Htree *ht, int n){
	unsigned int min = 0x3f3f3f3f;
	int at = n + 1;
	for(int i = 0 ; i <= n ; i++){
		if(ht[i].parent == -1 && (min > ht[i].w)){
			min = ht[i].w;
			at = i;
		}
	}
	return at;
}

void HaffmanCoding(Htree *ht, Hcode hc, unsigned int *w, int n, int m){
	for(int i = 0 ; i < n ; i++){
		ht[i].w = w[i];
		ht[i].parent = ht[i].rchild = ht[i].lchild = -1;
	}
	for(int i = n ; i < m ; i++){
		ht[i].w = 0;
		ht[i].parent = ht[i].rchild = ht[i].lchild = -1;
	}
	for(int i = n ; i < m ; i++){
		int min1 = getMin(ht, i - 1);
		ht[min1].parent = i;
		int min2 = getMin(ht, i - 1);
		ht[min2].parent = i;

		if(min1 < min2){
			ht[i].lchild = min1;
			ht[i].rchild = min2;
		}else{
			ht[i].lchild = min2;
			ht[i].rchild = min1;
		}
		ht[i].w = ht[min1].w + ht[min2].w;
	}

	char *code = (char*)malloc(n * sizeof(char));
	for(int i = 0 ; i < n ; i++){
		int t = 0;
		int j, f;
		for(j = i, f = ht[i].parent; f != -1 ; j = f, f = ht[f].parent){
			if(ht[f].lchild == j){
				code[t++] = '0';
			}else{
				code[t++] = '1';
			}
		}
		hc[i] = (char*)malloc((t + 1) * sizeof(char));
		hc[i][t] = '\0';
		for(j = 0 ; j < t ; j++){
			hc[i][j] = code[t - j - 1];
		}
	}
	free(code);
}

int main(){
	unsigned int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
	int n = 8;
	int m = (n << 1) - 1;
	Htree *Ht = (Htree*)malloc(m * sizeof(Htree));
	Hcode Hc = (Hcode)malloc(n * sizeof(char *));

	HaffmanCoding(Ht, Hc, w, n, m);

	for(int i = 0 ; i < m ; i++){
		printf("i = %d : w = %d, parent = %d, lchild = %d, rchild = %d\n", i, Ht[i].w, Ht[i].parent, Ht[i].lchild, Ht[i].rchild);
	}

	for(int i = 0 ; i < n ; i++){
		printf("%s\n", Hc[i]);
	}
	return 0;
}
