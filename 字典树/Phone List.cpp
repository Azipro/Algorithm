// HDU 1671

Problem Description
Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another. Let’s say the phone catalogue listed these numbers:
1. Emergency 911
2. Alice 97 625 999
3. Bob 91 12 54 26
In this case, it’s not possible to call Bob, because the central would direct your call to the emergency line as soon as you had dialled the first three digits of Bob’s phone number. So this list would not be consistent.
 

Input
The first line of input gives a single integer, 1 <= t <= 40, the number of test cases. Each test case starts with n, the number of phone numbers, on a separate line, 1 <= n <= 10000. Then follows n lines with one unique phone number on each line. A phone number is a sequence of at most ten digits.
 

Output
For each test case, output “YES” if the list is consistent, or “NO” otherwise.
 

Sample Input
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
 

Sample Output
NO
YES



#include<iostream>
#include<cstdio>
#include<string.h>
#define maxn 100001
using namespace std;

int tree[maxn][26];
int num[maxn];
int pos;

void creat(char* s) {
    int root = 0;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - '0';
        if(!tree[root][x]) {
            tree[root][x] = pos++;
        }
        root = tree[root][x];
        num[root]++;
    }
}

int find(char* s) {
    int root = 0;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - '0';
        if(!tree[root][x]) {
            return 0;
        }
        root = tree[root][x];
    }
    return num[root];
}
int main() {
    int n, T;
    cin >> T;
    while(T--) {
        memset(tree, 0, sizeof(tree));
        memset(num, 0, sizeof(num));
        pos = 1;
        cin >> n;
        char s[maxn][15];
        for(int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            creat(s[i]);
        }
        bool is = true;
        for(int i = 0; i < n; i++) {
            if(find(s[i]) > 1) {
                is = false;
                break;
            }
        }
        if(is)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
