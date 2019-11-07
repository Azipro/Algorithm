//CodeForces - 185A
Description
Dwarfs have planted a very interesting plant, which is a triangle directed "upwards". This plant has an amusing feature. 
After one year a triangle plant directed "upwards" divides into four triangle plants: 
three of them will point "upwards" and one will point "downwards". 
After another year, each triangle plant divides into four triangle plants: three of them will be directed in the same direction as the 
parent plant, and one of them will be directed in the opposite direction. Then each year the process repeats. 
The figure below illustrates this process.
Help the dwarfs find out how many triangle plants that point "upwards" will be in n years.



Input
The first line contains a single integer n (0 ≤ n ≤ 1018) — the number of full years when the plant grew.
Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or 
the %I64d specifier.

Output
Print a single integer — the remainder of dividing the number of plants that will point "upwards" in n years by 1000000007 (109 + 7).


Examples
input
1
output
3
input
2
output
10


Note
The first test sample corresponds to the second triangle on the figure in the statement. 
The second test sample corresponds to the third one.





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 2
#define mod 1000000007
using namespace std;
typedef long long ll;;

int t, sum[maxn], arr[maxn], add[maxn];
int times, which;
bool is;
ll n, m;

struct mat{
    ll g[maxn][maxn];
    mat(){
        memset(g, 0, sizeof(g));
    }
};

mat multi(mat &a, mat &b){
    mat c;
    for(int i = 0 ; i < maxn ; i++){
        for(int j = 0 ; j < maxn ; j++){
            for(int k = 0 ; k < maxn ; k++){
                c.g[i][j] = (a.g[i][k] * b.g[k][j] + c.g[i][j]) % mod;
            }
        }
    }
    return c;
}

mat mat_quick_pow(mat a, ll x){
    mat b;
    for(int i = 0 ; i < maxn ; i++){
        b.g[i][i] = 1;
    }
    while(x){
        if(x & 1){
            b = multi(b, a);
        }
        a = multi(a, a);
        x >>= 1;
    }
    return b;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    scanf("%lld", &n);
    if(n == 0){
        printf("1\n");
        return 0;
    }
    if(n == 1){
        printf("3\n");
        return 0;
    }
    mat a;
    a.g[0][0] = 2;
    a.g[0][1] = 4;
    a.g[1][0] = 0;
    a.g[1][1] = 4;
    mat b;
    b.g[0][0] = 3;
    b.g[1][0] = 1;
    a = mat_quick_pow(a, n - 1);
    b = multi(a, b);
    printf("%lld\n", b.g[0][0] % mod);
    return 0;
}
