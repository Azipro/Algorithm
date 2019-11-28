// HDU 1305

Problem Description
An encoding of a set of symbols is said to be immediately decodable if no code for one symbol is the prefix of a code for another symbol.
We will assume for this problem that all codes are in binary, that no two codes within a set of codes are the same, that each code has at
least one bit and no more than ten bits, and that each set has at least two codes and no more than eight.

Examples: Assume an alphabet that has symbols {A, B, C, D}

The following code is immediately decodable:
A:01 B:10 C:0010 D:0000

but this one is not:
A:01 B:10 C:010 D:0000 (Note that A is a prefix of C)
 

Input
Write a program that accepts as input a series of groups of records from input. Each record in a group contains a collection of 
zeroes and ones representing a binary code for a different symbol. Each group is followed by a single separator record containing 
a single 9; the separator records are not part of the group. Each group is independent of other groups; the codes in one group are
not related to codes in any other group (that is, each group is to be processed independently).
 

Output
For each group, your program should determine whether the codes in that group are immediately decodable, and should print a single
output line giving the group number and stating whether the group is, or is not, immediately decodable.
 

Sample Input
01
10
0010
0000
9
01
10
010
0000
9
 

Sample Output
Set 1 is immediately decodable
Set 2 is not immediately decodable



#include<iostream>
#include<cstdio>
#include<string.h>
#define maxn 50005
using namespace std;

char dic[maxn][15];
int t = 1, ans = 0;
bool is;

struct node {
    int count;
    node* next[2];
    node() {
        count = 0;
        for(int i = 0; i < 2; i++) {
            next[i] = NULL;
        }
    }
}*tree;

void creat(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - '0';
        if(p->next[x] == NULL) {
            p->next[x] = new node();
        }
        p = p->next[x];
        p->count++;
    }
}

bool find(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - '0';
        p = p->next[x];
    }
    if(p->count != 1) {
        return false;
    }
    return true;
}

void Delete(node* p) {
    if(p == NULL) {
        return ;
    }
    for(int i = 0; i < 2; i++) {
        if(p->next[i] != NULL) {
            Delete(p->next[i]);
        }
    }
    delete p;
}

int main() {
    memset(dic, '0', sizeof(dic));
    tree = new node();
    is = true;
    while(scanf("%s", dic[ans]) != EOF) {
        if(dic[ans][0] == '9') {
            if(ans == 0) {
                continue;
            }
            for(int i = 0; i < ans; i++) {
                if(!find(dic[i])) {
                    is = false;
                    break;
                }
            }
            if(is)
                cout << "Set " << t++ << " is immediately decodable" << endl;
            else {
                cout << "Set " << t++ << " is not immediately decodable" << endl;
            }
            Delete(tree);
            memset(dic, '0', sizeof(dic));
            tree = new node();
            ans = 0;
            is = true;
            continue;
        }
        creat(dic[ans]);
        ans++;
    }
    return 0;
}
