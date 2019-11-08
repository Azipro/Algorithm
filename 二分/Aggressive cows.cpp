//POJ 2456
Description
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions 
x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two 
of them is as large as possible. What is the largest minimum distance?

Input
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
* Line 1: One integer: the largest minimum distance

Sample Input
5 3
1
2
8
4
9

Sample Output
3

Hint
OUTPUT DETAILS:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.
Huge input data,scanf is recommended.




#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#define M(i,n,m) for(int i = n;i < m;i ++)
#define N(n,m) memset(n,m,sizeof(n));
using namespace std;
const int MAX = 100010;
int a[MAX],n,m;
bool C(int d)
{
    int last = 0;
    M(i,1,m)
    {
        int crt = last + 1;
        while(crt < n && a[crt] - a[last] < d)
            crt ++;
        if(crt == n)
            return false;
        last = crt;
    }
    return true;
}
void solve()
{
    int x = 0,y = a[n-1] - a[0];    ///分别找出此时对应的x和y的值
    while(y - x > 1)
    {
        int mid=(x+y)/2;
        if(C(mid))
            x=mid;
        else
            y=mid;
    }
    printf("%d\n",x);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        N(a,0);
        M(i,0,n)
        scanf("%d",&a[i]);
        sort(a,a+n);
        solve();
    }
    return 0;
}
