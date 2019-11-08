//HDU 1556
Problem Description
N个气球排成一排，从左到右依次编号为1,2,3....N.每次给定2个整数a b(a <= b),lele便为骑上他的“小飞鸽"牌电动车从气球a开始到气球b依次给每个气球涂
一次颜色。但是N次以后lele已经忘记了第I个气球已经涂过几次颜色了，你能帮他算出每个气球被涂过几次颜色吗？
 

Input
每个测试实例第一行为一个整数N,(N <= 100000).接下来的N行，每行包括2个整数a b(1 <= a <= b <= N)。
当N = 0，输入结束。
 

Output
每个测试实例输出一行，包括N个整数，第I个数代表第I个气球总共被涂色的次数。
 

Sample Input
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0
 

Sample Output
1 1 1
3 2 1




#include<iostream>
#include<cstdio>
#include<string.h>
#define maxn 100005
using namespace std;

int n, a, b;
int c[maxn];

int lowbit(int x) {
    return x & (-x);
}

int query(int x) {
    int ans = 0;
    while(x <= n) {
        ans += c[x];
        x += lowbit(x);
    }
    return ans;
}

void update(int x, int val) {
    while(x > 0) {
        c[x] += val;
        x -= lowbit(x);
    }
}

int main() {
    //freopen("text.txt", "r", stdin);
    while(scanf("%d", &n) && n) {
        int N = n;
        memset(c, 0, sizeof(c));
        while(N--) {
            scanf("%d%d", &a, &b);
            update(b, 1);
            update(a - 1, -1);
        }
        cout << query(1);
        for(int i = 2; i <= n; i++) {
            cout << " " << query(i);
        }
        cout << endl;
    }
    return 0;
}
