// POJ 1182

Description
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这N个动物所构成的食物链关系进行描述：
第一种说法是"1 X Y"，表示X和Y是同类。
第二种说法是"2 X Y"，表示X吃Y。
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
1） 当前的话与前面的某些真的话冲突，就是假话；
2） 当前的话中X或Y比N大，就是假话；
3） 当前的话表示X吃X，就是假话。
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。

Input
第一行是两个整数N和K，以一个空格分隔。
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。
若D=1，则表示X和Y是同类。
若D=2，则表示X吃Y。

Output
只有一个整数，表示假话的数目。

Sample Input
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5

Sample Output
3


#include <iostream>
#include<cstdio>
#define maxn 50005
using namespace std;

int gather[maxn * 3];
int n, k, sum = 0;

int Find(int x) {
    if(gather[x] == x) return x;
    return gather[x] = Find(gather[x]);
}

void Link(int x, int y) {
    int u = Find(x);
    int v = Find(y);
    if(u == v) return;
    gather[u] = v;
}

int main() {
    scanf("%d %d",&n,&k);
    for(int i = 1; i <= n * 3; i++) {
        gather[i] = i;
    }
    int d, x, y;
    while(k--) {
        scanf("%d %d %d",&d,&x,&y);
        if(x <= 0 || x > n || y <= 0 || y > n || (d == 2 && x == y)) {
            sum++;
            continue;
        }
        if(d == 1) {
            if(Find(x) == Find(y + n) || Find(x + n) == Find(y)) {
                sum++;
            } else {
                Link(x, y);
                Link(x + n, y + n);
                Link(x + 2 * n, y + 2 * n);
            }
        } else {
            if(Find(x) == Find(y) || Find(x) == Find(y + 2 * n)) {
                sum++;
            } else {
                Link(x, y + n);
                Link(x + n, y + 2 * n);
                Link(x + 2 * n, y);
            }
        }
    }
    cout << sum << endl;
    return 0;
}
