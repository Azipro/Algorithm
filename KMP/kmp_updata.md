#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	next[len]:在子串的第len个字符与主串不匹配时，则跳到子串的next[len]
	位置重新与主串当前位置进行比较。
	KMP即利用最长相等前后缀来跳过无用的匹配。
	如子串p = "ababc"，当'c'与主串发生不匹配时，不需要从头开始匹配，
	此时"abab"已经匹配，即主串中与'c'不匹配的字符的前两个字符必是"ab"，
	只需要让子串右移两位，让后缀的"ab"与主串中的"ab"对齐，从'c'开始匹配。
*/
void prefix_next(int *next, char *p, int p_len){
	next[0] = -1;
	int i = 0;
	int len = -1;
	//只是判断子串是否是主串的子集，可改为 i < p_len - 1
	while(i < p_len){ // next数组比p子串长度多1，用来存放整个子串的最长相等前后缀，可以用来判断循环节等。
		if(len == -1 || p[i] == p[len]){ // len == -1，即当前最长相等前后缀为0
			i++;
			len++;
			if(p[i] != p[len]){ 
				next[i] = len;  // next[len + 1] = next[len] + 1
			}else{
				next[i] = next[len];	
				/* 设p = "aaab"，第3个a不匹配时，
				   不需要回到第2个a匹配，因为p[3] == p[2],
				   p[3]不匹配，p[2]也必不匹配。回到前面不等于	
				   p[3]的地方继续匹配。*/
			}
		}else{
			len = next[len]; // 当前匹配的前缀和后缀不相等时，回找尽可能长的前缀来与后缀比较。
		}
	}
}

// str为主串，p为子串
int kmp(int *next, char *str, char *p, int str_len, int p_len){
	prefix_next(next, p, p_len); // 构造前缀表

	int i = 0, j = 0;
	while(i < str_len && j < p_len){
		if(j == -1 || str[i] == p[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j >= p_len){
		return i - j;
	}else{
		return 0;
	}
}

int main(){
	char str[] = "ababcabcacbab";
	char p[] = "abcac";
	int str_len = strlen(str);
	int p_len = strlen(p);
	int *next = (int *)malloc((p_len + 1) * sizeof(int));

	int position = kmp(next, str, p, str_len, p_len);
	if(!position){
		printf("Not Found!\n");
	}else{
		printf("The positon of p in str is %d\n", position);
	}
	return 0;
}
