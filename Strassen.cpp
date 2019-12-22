#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define INF 0x3f3f3f3f
#define mod 100000007
using namespace std;
typedef long long ll;

 
int **A;
int **B;
int maxn;


//普通算法，暴力求解
int** Violence(int **A, int **B, int len) {
	int **C;
	C = (int **)malloc(len * sizeof(int));
	for(int i = 0 ; i < len ; i++){
		C[i] = (int *)malloc(len * sizeof(int));
	}
	for (int i = 0; i < len ; i++) {
		for (int j = 0; j < len ; j++) {
			C[i][j] = 0;
			for (int k = 0; k < len ; k++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	return C;
}
 

//将N×N的大矩阵分割成四个N/2×N/2的小矩阵 （分治思想）
void copyMatrix(int **src, int startI, int lenI, int startJ, int lenJ, int **dest) {
	for (int i = 0; i < lenI; i++){
		for (int j = 0; j < lenJ; j++) {
			dest[i][j] = src[startI + i][startJ + j];
		}
	}
}


//矩阵加法
void addMatrix(int **srcA, int **srcB, int **dest, int len) {
	for (int i = 0; i < len ; i++)
		for (int j = 0; j < len ; j++)
			dest[i][j] = srcA[i][j] + srcB[i][j];
}

//矩阵减法
void subMatrix(int **srcA, int **srcB, int **dest, int len) {
	for (int i = 0; i < len ; i++)
		for (int j = 0; j < len ; j++)
			dest[i][j] = srcA[i][j] - srcB[i][j];
}

//将N/2 × N/2的小矩阵合并成 N×N的大矩阵
void combineMatrix(int **src, int startI, int lenI, int startJ, int lenJ, int **dest) {
	for (int i = 0; i < lenI ; i++){
		for (int j = 0; j < lenJ ; j++) {
			dest[startI + i][startJ + j] = src[i][j];
		}
	}
}

int** Strassen(int **A, int **B, int len) {
		int rows = len;
		int **C;
		C = (int **)malloc(rows * sizeof(int));
		for(int i = 0 ; i < rows ; i++){
			C[i] = (int *)malloc(rows * sizeof(int));
		}
		//终止条件
		if(rows == 1) {
			C[0][0] = A[0][0] * B[0][0];
		}else{
			int **A11;
			int **A12;
			int **A21;
			int **A22;
			A11 = (int **)malloc(rows / 2 * sizeof(int));
			A12 = (int **)malloc(rows / 2 * sizeof(int));
			A21 = (int **)malloc(rows / 2 * sizeof(int));
			A22 = (int **)malloc(rows / 2 * sizeof(int));
			for(int i = 0 ; i < rows / 2 ; i++){
				A11[i] = (int *)malloc(rows / 2 * sizeof(int));
				A12[i] = (int *)malloc(rows / 2 * sizeof(int));
				A21[i] = (int *)malloc(rows / 2 * sizeof(int));
				A22[i] = (int *)malloc(rows / 2 * sizeof(int));
			}

			//分成小矩阵
			copyMatrix(A, 0, rows / 2, 0, rows / 2, A11);
			copyMatrix(A, 0, rows / 2, rows / 2, rows / 2, A12);
			copyMatrix(A, rows / 2, rows / 2, 0, rows / 2, A21);
			copyMatrix(A, rows / 2, rows / 2, rows / 2, rows / 2, A22);

 
			int **B11;
			int **B12;
			int **B21;
			int **B22;

			B11 = (int **)malloc(rows / 2 * sizeof(int));
			B12 = (int **)malloc(rows / 2 * sizeof(int));
			B21 = (int **)malloc(rows / 2 * sizeof(int));
			B22 = (int **)malloc(rows / 2 * sizeof(int));
			for(int i = 0 ; i < rows / 2 ; i++){
				B11[i] = (int *)malloc(rows / 2 * sizeof(int));
				B12[i] = (int *)malloc(rows / 2 * sizeof(int));
				B21[i] = (int *)malloc(rows / 2 * sizeof(int));
				B22[i] = (int *)malloc(rows / 2 * sizeof(int));
			}
 
 			//分成小矩阵
			copyMatrix(B, 0, rows / 2, 0, rows / 2, B11);
			copyMatrix(B, 0, rows / 2, rows / 2, rows / 2, B12);
			copyMatrix(B, rows / 2, rows / 2, 0, rows / 2, B21);
			copyMatrix(B, rows / 2, rows / 2, rows / 2, rows / 2, B22);

 
			int **S1;
			int **S2;
			int **S3;
			int **S4;
			int **S5;
			int **S6;
			int **S7;
			int **S8;
			int **S9;
			int **S10;

			S1 = (int **)malloc(rows / 2 * sizeof(int));
			S2 = (int **)malloc(rows / 2 * sizeof(int));
			S3 = (int **)malloc(rows / 2 * sizeof(int));
			S4 = (int **)malloc(rows / 2 * sizeof(int));
			S5 = (int **)malloc(rows / 2 * sizeof(int));
			S6 = (int **)malloc(rows / 2 * sizeof(int));
			S7 = (int **)malloc(rows / 2 * sizeof(int));
			S8 = (int **)malloc(rows / 2 * sizeof(int));
			S9 = (int **)malloc(rows / 2 * sizeof(int));
			S10 = (int **)malloc(rows / 2 * sizeof(int));
			for(int i = 0 ; i < rows / 2 ; i++){
				S1[i] = (int *)malloc(rows / 2 * sizeof(int));
				S2[i] = (int *)malloc(rows / 2 * sizeof(int));
				S3[i] = (int *)malloc(rows / 2 * sizeof(int));
				S4[i] = (int *)malloc(rows / 2 * sizeof(int));
				S5[i] = (int *)malloc(rows / 2 * sizeof(int));
				S6[i] = (int *)malloc(rows / 2 * sizeof(int));
				S7[i] = (int *)malloc(rows / 2 * sizeof(int));
				S8[i] = (int *)malloc(rows / 2 * sizeof(int));
				S9[i] = (int *)malloc(rows / 2 * sizeof(int));
				S10[i] = (int *)malloc(rows / 2 * sizeof(int));
			}
 
			subMatrix(B12, B22, S1, rows / 2);	// S1 = B12 - B22
			addMatrix(A11, A12, S2, rows / 2);	// S2 = A11 + A12
			addMatrix(A21, A22, S3, rows / 2);	// S3 = A21 + A22
			subMatrix(B21, B11, S4, rows / 2);	// S4 = B21 - B11
			addMatrix(A11, A22, S5, rows / 2);	// S5 = A11 + A22
			addMatrix(B11, B22, S6, rows / 2);	// S6 = B11 + B22
			subMatrix(A12, A22, S7, rows / 2);	// S7 = A12 - A22
			addMatrix(B21, B22, S8, rows / 2);	// S8 = B21 + B22
			subMatrix(A11, A21, S9, rows / 2);	// S9 = A11 - A21
			addMatrix(B11, B12, S10, rows / 2);	// S10 = B11 + B12

 
			int **P1;
			int **P2;
			int **P3;
			int **P4;
			int **P5;
			int **P6;
			int **P7;

		    P1 = (int **)malloc(rows / 2 * sizeof(int));
			P2 = (int **)malloc(rows / 2 * sizeof(int));
			P3 = (int **)malloc(rows / 2 * sizeof(int));
			P4 = (int **)malloc(rows / 2 * sizeof(int));
			P5 = (int **)malloc(rows / 2 * sizeof(int));
			P6 = (int **)malloc(rows / 2 * sizeof(int));
			P7 = (int **)malloc(rows / 2 * sizeof(int));

			for(int i = 0 ; i < rows / 2 ; i++){
				P1[i] = (int *)malloc(rows / 2 * sizeof(int));
				P2[i] = (int *)malloc(rows / 2 * sizeof(int));
				P3[i] = (int *)malloc(rows / 2 * sizeof(int));
				P4[i] = (int *)malloc(rows / 2 * sizeof(int));
				P5[i] = (int *)malloc(rows / 2 * sizeof(int));
				P6[i] = (int *)malloc(rows / 2 * sizeof(int));
				P7[i] = (int *)malloc(rows / 2 * sizeof(int));
			}
 			

 			//递归，继续分成更小的矩阵。
			P1 = Strassen(A11, S1, rows / 2); 		// P1 = A11 X S1
			P2 = Strassen(S2, B22, rows / 2);		// P2 = S2 X B22
			P3 = Strassen(S3, B11, rows / 2);		// P3 = S3 X B11
			P4 = Strassen(A22, S4, rows / 2);		// P4 = A22 X S4
			P5 = Strassen(S5, S6, rows / 2);		// P5 = S5 X S6
			P6 = Strassen(S7, S8, rows / 2);		// P6 = S7 X S8
			P7 = Strassen(S9, S10, rows / 2);		// P7 = S9 X S10


			int **C11;
			int **C12;
			int **C21;
			int **C22;
			int **temp;

			C11 = (int **)malloc(rows / 2 * sizeof(int));
			C12 = (int **)malloc(rows / 2 * sizeof(int));
			C21 = (int **)malloc(rows / 2 * sizeof(int));
			C22 = (int **)malloc(rows / 2 * sizeof(int));
			temp = (int **)malloc(rows / 2 * sizeof(int));

			for(int i = 0 ; i < rows / 2 ; i++){
				C11[i] = (int *)malloc(rows / 2 * sizeof(int));
				C12[i] = (int *)malloc(rows / 2 * sizeof(int));
				C21[i] = (int *)malloc(rows / 2 * sizeof(int));
				C22[i] = (int *)malloc(rows / 2 * sizeof(int));
				temp[i] = (int *)malloc(rows / 2 * sizeof(int));
			}
 
			// C11 = P5 + P4 - P2 + P6
			addMatrix(P5, P4, temp, rows / 2);
			subMatrix(temp, P2, temp, rows / 2);
			addMatrix(temp, P6, C11, rows / 2);
 
			// C12 = P1 + P2
			addMatrix(P1, P2, C12, rows / 2);
 
			// C21 = P3 + P4
			addMatrix(P3, P4, C21, rows / 2);
 
			// C22 = P5 + P1 - P3 -P7
			addMatrix(P5, P1, temp, rows / 2);
			subMatrix(temp, P3, temp, rows / 2);
			subMatrix(temp, P7, C22, rows / 2);
 
			//将C11, C12, C21, C22四个子矩阵合并为最终矩阵C
			combineMatrix(C11, 0, rows / 2, 0, rows / 2, C);
			combineMatrix(C12, 0, rows / 2, rows / 2, rows / 2, C);
			combineMatrix(C21, rows / 2, rows / 2, 0, rows / 2, C);
			combineMatrix(C22, rows / 2, rows / 2, rows / 2, rows / 2, C);

		}
		return C;
}

void print(int **s, int len){
	for(int i = 0 ; i < len ; i++){
		for(int j = 0 ; j < len ; j++){
			printf("%d ", s[i][j]);
		}
		printf("\n");
	}
}

int main(){
	//freopen("test.txt", "r", stdin);
	//初始化A,B矩阵
	printf("Please input N of N*N Matrix:\n");
	scanf("%d", &maxn);
	A = (int **)malloc(maxn * sizeof(int));
	B = (int **)malloc(maxn * sizeof(int));
	for(int i = 0 ; i < maxn ; i++){
		A[i] = (int *)malloc(maxn * sizeof(int));
		B[i] = (int *)malloc(maxn * sizeof(int));
	}
	printf("Please input Matrix A:\n");
	for(int i = 0 ; i < maxn ; i++){
		for(int j = 0 ; j < maxn ; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Please input Matrix B:\n");
	for(int i = 0 ; i < maxn ; i++){
		for(int j = 0 ; j < maxn ; j++){
			scanf("%d", &B[i][j]);
		}
	}

	//暴力算法
	int **C1;
	C1 = (int **)malloc(maxn * sizeof(int));
	for(int i = 0 ; i < maxn ; i++){
		C1[i] = (int *)malloc(maxn * sizeof(int));
	}
	C1 = Violence(A, B, maxn);
	printf("Result of Violence:\n");
	print(C1, maxn);
	printf("\n");

	//Strassen算法
	int **C2;
	C2 = (int **)malloc(maxn * sizeof(int));
	for(int i = 0 ; i < maxn ; i++){
		C2[i] = (int *)malloc(maxn * sizeof(int));
	}
	C2 = Strassen(A, B, maxn);
	printf("Result of Strassen:\n");
	print(C2, maxn);
	return 0;
 }
