int a[maxn], f[maxn];
int n,ans = -INF;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) 
    {
        scanf("%d", &a[i]);
        f[i] = 1;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<i; j++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j]+1);
    for(int i=1; i<=n; i++) 
        ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}



贪心+二分

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int maxn =300003, INF = 0x7f7f7f7f;
int low[maxn], a[maxn];
int n, ans;
 
int binary_search(int *a, int r, int x)
//二分查找，返回a数组中第一个>=x的位置 
{
    int l = 1, mid;
    while(l <= r)
    {
        mid = (l+r) >> 1;
        if(a[mid] <= x)
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return l;
}
 
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) 
    {
        scanf("%d", &a[i]); 
        low[i] = INF;   //由于low中存的是最小值，所以low初始化为INF 
    }
    low[1] = a[1]; 
    ans = 1;   //初始时LIS长度为1 
    for(int i=2; i<=n; i++)
    {
        if(a[i] > low[ans])    //若a[i]>=low[ans]，直接把a[i]接到后面 
            low[++ans] = a[i];
        else       //否则，找到low中第一个>=a[i]的位置low[j]，用a[i]更新low[j] 
            low[binary_search(low, ans, a[i])] = a[i];
    }
    printf("%d\n", ans);   //输出答案 
    return 0;
}


用C++自带函数lower_bound( )函数。
#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
  
using namespace std;  
  
int num[10]={3,6,3,2,4,6,7,5,4,3};  
  
const int INF=0x3f3f3f3f;  
int l=10, g[100], d[100];  
 
int main()  
{  
    fill(g, g+l, INF);  
    int max_=-1;  
    for(int i=0; i<l; i++)  
    {  
        int j = lower_bound(g, g+l, num[i]) - g;  
        d[i] = j+1;  
        if(max_<d[i])  
            max_=d[i];  
        g[j] = num[i];  
    }  
    printf("%d\n", max_);  
    return 0;  
}  
  
这个算法其实已经不是DP了，有点像贪心。至于复杂度降低其实是因为这个算法里面用到了二分搜索。
本来有N个数要处理是O(n)，每次计算要查找N次还是O(n)，一共就是O(n^2)；
现在搜索换成了O(logn)的二分搜索，总的复杂度就变为O(nlogn)了。
这里主要注意一下lower_bound函数的应用，注意减去的g是地址。
地址 - 地址 = 下标。
