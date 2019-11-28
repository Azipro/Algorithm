// HDU 1247

Problem Description
A hat’s word is a word in the dictionary that is the concatenation of exactly two other words in the dictionary.
You are to find all the hat’s words in a dictionary.


Input
Standard input consists of a number of lowercase words, one per line, in alphabetical order. There will be no more than 50,000 words.
Only one case.
 

Output
Your output should contain all the hat’s words, one per line, in alphabetical order.
 

Sample Input
a
ahat
hat
hatword
hziee
word
 

Sample Output
ahat
hatword




#include<iostream>
#include<cstdio>
#include<string.h>
#include<map>
#include<queue>
#define maxn 50005
using namespace std;

char dic[maxn][15];
priority_queue<string, vector<string>, greater<string> >q;
int ans = 0;

struct node {
    int count;
    node* next[26];
    node() {
        count = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
}*tree;

void creat(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(p->next[x] == NULL) {
            p->next[x] = new node();
        }
        p = p->next[x];
    }
    p->count++;
}

int find(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(p == NULL) {
            return 0;
        }
        p = p->next[x];
    }
    if(p == NULL)
        return 0;
    else
        return p->count;
}

int main() {
    tree = new node();
    char one[15];
    char two[15];
    while(scanf("%s", dic[ans]) != EOF) {
        creat(dic[ans]);
        ans++;
    }
    for(int i = 0; i < ans; i++) {
        int len = strlen(dic[i]);
        for(int j = 0; j < len; j++) {
            memset(one, '\0', sizeof(one));
            memset(two, '\0', sizeof(two));
            strncpy(one, dic[i], j);
            strncpy(two, dic[i] + j, len - j);
            if(find(one) > 0 && find(two) > 0) {
                q.push(dic[i]);
                break;
            }
        }
    }
    while(!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
    return 0;
}
