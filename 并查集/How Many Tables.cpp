// HDU 1213

Problem Description
Today is Ignatius' birthday. He invites a lot of friends. Now it's dinner time. Ignatius wants to know how many tables he needs at least. 
You have to notice that not all the friends know each other, and all the friends do not want to stay with strangers.

One important rule for this problem is that if I tell you A knows B, and B knows C, that means A, B, C know each other, so they can stay 
in one table.

For example: If I tell you A knows B, B knows C, and D knows E, so A, B, C can stay in one table, and D, E have to stay in the other one.
So Ignatius needs 2 tables at least.
 

Input
The input starts with an integer T(1<=T<=25) which indicate the number of test cases. Then T test cases follow. Each test case starts
withtwo integers N and M(1<=N,M<=1000). N indicates the number of friends, the friends are marked from 1 to N. Then M lines follow. Each
lineconsists of two integers A and B(A!=B), that means friend A and friend B know each other. There will be a blank line between two 
cases.
 

Output
For each test case, just output how many tables Ignatius needs at least. Do NOT print any blanks.
 

Sample Input
2
5 3
1 2
2 3
4 5

5 1
2 5
 

Sample Output
2
4


#include <iostream>
#define maxn 1005
using namespace std;

int gather[maxn];
int n, m, sum;

int Find(int x) {
    if(gather[x] == x) return x;
    return gather[x] = Find(gather[x]);
}

void Link(int x, int y) {
    int u = Find(x);
    int v = Find(y);
    if(u == v) return;
    gather[u] = v;
    sum--;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
    sum=n;
        for(int i = 1; i <= n; i++) {
            gather[i] = i;
        }
        while(m--) {
            int a, b;
            cin >> a >> b;
            Link(a, b);
        }
        cout<<sum<<endl;
    }
    return 0;
}

 
