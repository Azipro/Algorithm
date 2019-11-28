// HDU 1251

Problem Description
Ignatius最近遇到一个难题,老师交给他很多单词(只有小写字母组成,不会有重复的单词出现),现在老师要他统计出以某个字符串为前缀的单词数量(单词本身也是自己的前缀).
 

Input
输入数据的第一部分是一张单词表,每行一个单词,单词的长度不超过10,它们代表的是老师交给Ignatius统计的单词,一个空行代表单词表的结束.第二部分是一连串的提问,每行一个提问,每个提问都是一个字符串.

注意:本题只有一组测试数据,处理到文件结束.
 

Output
对于每个提问,给出以该字符串为前缀的单词的数量.
 

Sample Input
banana
band
bee
absolute
acm

ba
b
band
abc
 

Sample Output
2
3
1
0



#include<iostream>
#include<cstdio>
#include<string.h>
#define maxn 500001
using namespace std;

int tree[maxn][26];
int num[maxn];
int pos = 1;

void creat(char* s) {
    int root = 0;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(!tree[root][x]) {
            tree[root][x] = pos++;
        }
        root = tree[root][x];
        num[root]++;
    }
}

int  find(char* s) {
    int root = 0;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(!tree[root][x]) {
            return 0;
        }
        root = tree[root][x];
    }
    return num[root];
}
int main() {
    memset(tree, 0, sizeof(tree));
    memset(num, 0, sizeof(num));
    char s[20];
    while(gets(s)) {
        if(s[0] == NULL)
            break;
        creat(s);
    }
    while(gets(s)) {
        if(s[0] == NULL)
            break;
        cout << find(s) << endl;
    }
    return 0;
}
