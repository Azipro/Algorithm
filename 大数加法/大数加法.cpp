        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        cin >> a_str >> b_str;
        a_len = a_str.length();
        b_len = b_str.length();
        int Len = max(a_len, b_len);
        for(int i = 0; i < a_len; i++) {
            a[i] = a_str[a_len - 1 - i] - '0';
        }
        for(int i = 0; i < b_len; i++) {
            b[i] = b_str[b_len - 1 - i] - '0';
        }
        for(int i = 0; i < Len; i++) {
            c[i + 1] = (a[i] + b[i] + c[i]) / 10;
            c[i] = (a[i] + b[i] + c[i]) % 10;
        }
        while(Len && c[Len] == 0)
            Len--;

            for(int i = Len; i >= 0; i--) {
                cout << c[i];
            }


A Fibonacci sequence is calculated by adding the previous two members the sequence, with the first two members being both 1. 
F(1) = 1, F(2) = 1, F(3) = 1,F(4) = 1, F(n>4) = F(n - 1) + F(n-2) + F(n-3) + F(n-4) 
Your task is to take a number as input, and print that Fibonacci number. 
Input
Each line will contain an integers. Process to end of file. 
Output
For each case, output the result in a line.
Sample Input
100
Sample Output
4203968145672990846840663646


#include<iostream>
#include <cstdio>
#include <string.h>
#define maxn 10001
using namespace std;

int n;
int s[maxn][600];

void getSequence() {
    memset(s, 0, sizeof(s));
    s[1][0] = 1;
    s[2][0] = 1;
    s[3][0] = 1;
    s[4][0] = 1;
    for(int k = 5; k < maxn - 1; k++) {
        for(int i = 0; i <= 550; i++) {
            s[k][i] += s[k - 4][i] + s[k - 3][i] + s[k - 2][i] + s[k - 1][i];
            s[k][i + 1] += s[k][i] / 100000;
            s[k][i] %= 100000;  //一个格子存五位数
        }
    }
}

int main() {
    getSequence();
    while(cin >> n) {
        int at = 550;
        while(s[n][at] == 0)
            at--;
        cout << s[n][at];
        for(int i = at - 1; i >= 0; i--) {
            printf("%05d", s[n][i]);
        }
        cout << endl;
    }
    return 0;
}


大正小数相加（长度不大于400的正小数）
#include<iostream>
#include<string.h>
#define maxn 500
using namespace std;

string a_str, b_str;
bool is;
int a_len, b_len, a_site, b_site, judge, integer_len;
int a_integer[maxn], a_decimals[maxn], b_integer[maxn], b_decimals[maxn];
int c_integer[maxn], c_decimals[maxn];

int main() {
    while(cin >> a_str >> b_str) {
        a_site = -1;
        b_site = -1;
        integer_len = 1;
        judge = 0;
        is = true;
        a_len = a_str.length();
        b_len = b_str.length();
        memset(a_integer, 0, sizeof(a_integer));
        memset(b_integer, 0, sizeof(b_integer));
        memset(a_decimals, 0, sizeof(a_decimals));
        memset(b_decimals, 0, sizeof(b_decimals));
        memset(c_integer, 0, sizeof(c_integer));
        memset(c_decimals, 0, sizeof(c_decimals));
        for(int i = 0; i < a_len; i++) {
            if(a_str[i] == '.') {
                a_site = i;
                break;
            }
        }
        for(int i = 0; i < b_len; i++) {
            if(b_str[i] == '.') {
                b_site = i;
                break;
            }
        }
        if(a_site != -1 && b_site != -1) {
            int a = a_len - a_site - 1;
            int b = b_len - b_site - 1;
            int Max = max(a, b);
            if(Max == a) {
                for(int i = 0; i < a - b; i++) {
                    b_str += '0';
                }
                b_len = b_str.length();
            } else {
                for(int i = 0; i < b - a; i++) {
                    a_str += '0';
                }
                a_len = a_str.length();
            }
            judge = Max;
            integer_len = max(a_len - a, b_len - b);
        } else if(a_site == -1 && b_site != -1) {
            judge = b_len - b_site - 1;
            integer_len = max(a_len, b_len - (b_len - b_site - 1));
        } else if(a_site != -1 && b_site == -1) {
            judge = a_len - a_site - 1;
            integer_len = max(a_len - (a_len - a_site - 1), b_len);
        } else {
            integer_len = max(a_len, b_len);
        }
        if(a_site == -1) {
            for(int i = 0; i < a_len; i++) {
                a_integer[i] = a_str[a_len - i - 1] - '0';
            }
        } else {
            for(int i = 0; i < a_site; i++) {
                a_integer[i] = a_str[a_site - i - 1] - '0';
            }
            for(int i = 0; i < a_len - a_site - 1; i++) {
                a_decimals[i] = a_str[a_len - i - 1] - '0';
            }
        }
        if(b_site == -1) {
            for(int i = 0; i < b_len; i++) {
                b_integer[i] = b_str[b_len - i - 1] - '0';
            }
        } else {
            for(int i = 0; i < b_site; i++) {
                b_integer[i] = b_str[b_site - i - 1] - '0';
            }
            for(int i = 0; i < b_len - b_site - 1; i++) {
                b_decimals[i] = b_str[b_len - i - 1] - '0';
            }
        }
        for(int i = 0; i < judge; i++) {
            c_decimals[i + 1] = (a_decimals[i] + b_decimals[i] + c_decimals[i]) / 10;
            c_decimals[i] = (a_decimals[i] + b_decimals[i] + c_decimals[i]) % 10;
        }
        if(c_decimals[judge] != 0) {
            a_integer[0] += c_decimals[judge];
            c_decimals[judge] = 0;
        }
        for(int i = 0; i < integer_len; i++) {
            c_integer[i + 1] = (a_integer[i] + b_integer[i] + c_integer[i]) / 10;
            c_integer[i] = (a_integer[i] + b_integer[i] + c_integer[i]) % 10;
        }
        while(c_integer[integer_len] == 0)
            integer_len--;
        if(integer_len < 0)
            cout << "0";
        for(int i = integer_len; i >= 0; i--) {
            cout << c_integer[i];
        }
        for(int i = 0; i <= judge; i++) {
            if(c_decimals[i] != 0)
                is = false;
        }
        if(!is) {
            int at = 0;
            cout << ".";
            while(c_decimals[at] == 0)
                at++;
            for(int i = judge - 1; i >= at; i--) {
                cout << c_decimals[i];
            }
        }
        cout << endl;
    }
    return 0;
}
