（一）   Fibonacci数列f[n]=f[n-1]+f[n-2],f[1]=f[2]=1的第n项快速求法（不考虑高精度）

解法：

考虑1×2的矩阵【f[n-2],f[n-1]】。根据Fibonacci数列的递推关系，我们可以通过乘以一个2×2的矩阵A，得到矩阵：【f[n-1],f[n]】。

即：【f[n-2],f[n-1]】*A = 【f[n-1],f[n]】=【f[n-1],f[n-1]+f[n-2]】

很容易构造出这个2×2矩阵A，即：
０ １ 
１ １

所以，有【f[1],f[2]】×A＝【f[2],f[3]】
又因为矩阵乘法满足结合律，故有：
【f[1],f[2]】×A ^(n-1) =【f[n],f[n+1]】
这个矩阵的第一个元素f[n]即为所求。

 

（二）   数列f[n]=f[n-1]+f[n-2]+1,f[1]=f[2]=1的第n项的快速求法（不考虑高精度）

解法：
仿照前例，考虑1×3的矩阵【f[n-2],f[n-1],1】，希望求得某3×3的矩阵A，使得此1×3的矩阵乘以A得到矩阵：【f[n-1],f[n],1】

即：【f[n-2],f[n-1],1】* A ＝【f[n-1],f[n],1】=【f[n-1],f[n-1]+f[n-2]+1,1】

容易构造出这个3×3的矩阵A，即：
０ １ ０ 
１ １ ０ 
０ １ １

故：【f[1],f[2],1】* A^(n-1) = 【f[n],f[n+1],1】

 

（三）数列f[n]=f[n-1]+f[n-2]+n+1,f[1]=f[2]=1的第n项的快速求法（不考虑高精度）.
解法：
仿照前例，考虑1×4的矩阵【f[n-2],f[n-1],n,1】，希望求得某4×4的矩阵A，使得此1×4的矩阵乘以A得到矩阵：【f[n-1],f[n],n+1,1】
即：【f[n-2],f[n-1],n,1】* A  = 【f[n-1],f[n],n+1,1】＝【f[n-1],f[n-1]+f[n-2]+n+1,n+1,1】
容易构造出这个4×4的矩阵A，即：
０ １ ０ ０ 
１ １ ０ ０ 
０ １ １ ０ 
０ １ １ １

故：【f[1],f[2],3,1】* A^(n-1) = 【f[n],f[n+1],n+2,1】

 

 

（四）   数列f[n]=f[n-1]+f[n-2],f[1]=f[2]=1的前n项和s[n]=f[1]+f[2]+……+f[n]的快速求法（不考虑高精度）.

解法：

仿照之前的思路，考虑1×3的矩阵【f[n-2],f[n-1],s[n-2]】，我们希望通过乘以一个3×3的矩阵A，得到1×3的矩阵：【f[n-1],f[n],s[n-1]】
即：【f[n-2],f[n-1],s[n-2]】 * A  = 【f[n-1],f[n],s[n-1]】=【f[n-1],f[n-1]+f[n-2],s[n-2]+f[n-1]】
容易得到这个3×3的矩阵A是：
０ １ ０ 
１ １ １ 
０ ０ １

这种方法的矩阵规模是(r+1)*(r+1)

f(1)=f(2)=s(1)=1 ，所以，有

【f(1),f(2),s(1)】* A  = 【f(2),f(3),s(2)】

故：【f(1),f(2),s(1)】* A^(n-1)  = 【f(n),f(n+1),s(n)】

 

（五）   数列f[n]=f[n-1]+f[n-2]+n+1,f[1]=f[2]=1的前n项和s[n]=f[1]+f[2]+……+f[n]的快速求法（不考虑高精度）.

解法：

考虑1×5的矩阵【f[n-2],f[n-1],s[n-2],n,1】,
我们需要找到一个5×5的矩阵A，使得它乘以A得到如下1×5的矩阵【f[n-1],f[n],s[n-1],n+1,1】
即：【f[n-2],f[n-1],s[n-2],n,1】* A  =【f[n-1],f[n],s[n-1],n+1,1】

=【f[n-1], f[n-1]+f[n-2]+n+1,s[n-2]+f[n-1],n+1,1】
容易构造出A为：
０ １ ０ ０ ０ 
１ １ １ ０ ０ 
０ ０ １ ０ ０ 
０ １ ０ １ ０ 
０ １ ０ １ １

故：【f(1),f(2),s(1),3,1】* A^(n-1)  = 【f(n),f(n+1),s(n),n+2,1】




一般地，如果有f[n]=p*f[n-1]+q*f[n-2]+r*n+s
可以构造矩阵A为：
0  q  0  0  0 
1  p  1  0  0 
0  0  1  0  0 
0  r  0  1  0 
0  s  0  1  1

 

更一般的，对于f[n]=Sigma(a[n-i]*f[n-i])+Poly(n)，其中0<i<=某常数c, Poly (n)表示n的多项式，我们依然可以构造类似的矩阵A来解决问题。
设Degree(Poly(n))=d, 并规定Poly(n)=0时，d=-1，此时对应于常系数线性齐次递推关系。则本方法求前n项和的复杂度为：
((c+1)+(d+1))3*logns

 

例如：A(0) = 1 , A(1) = 1 , A(N) = X * A(N - 1) + Y * A(N - 2) (N >= 2)；给定三个值N，X，Y求S(N):S(N) = A(0)2 +A(1)2+……+A(n)2。

解：

考虑1*4 的矩阵【s[n-2],a[n-1]^2,a[n-2]^2,a[n-1]*a[n-2]】

我们需要找到一个4×4的矩阵A，使得它乘以A得到1×4的矩阵

【s[n-1],a[n]^2,a[n-1]^2,a[n]*a[n-1]】

即：【s[n-2],a[n-1]^2,a[n-2]^2,a[n-1]*a[n-2]】* A = 【s[n-1],a[n]^2,a[n-1]^2,a[n]*a[n-1]】

= 【s[n-2]+a[n-1]^2 , x^2 * a[n-1]^2 + y^2 * a[n-2]^2 + 2*x*y*a[n-1]*a[n-2] ,

a[n-1]^2 , x*a[n-1]^2 + y*a[n-2]a[n-1]】

可以构造矩阵A为：

1     0    0    0

1    x^2   1    x

0    y^2   0    0

0    2xy   0    y

故：【S[0],a[1]^2,a[0]^2,a[1]*a[0]】 * A^(n-1) = 【s[n-1],a[n]^2,a[n-1]^2,a[n]*a[n-1]】

所以：【S[0],a[1]^2,a[0]^2,a[1]*a[0]】 * A^(n) = 【s[n],a[n+1]^2,a[n]^2,a[n+1]*a[n]】

若A = (B * C ) 则AT = ( B * C )T = CT * BT
故
Sn			       1     1      0        0		            S(0)
a(n+1)^2	               0    x^2    y^2      2xy                    a(1)^2
		=     [                                       ]^n   [	    	       ]
a(n)^2			       0     1      0        0		           a(0)^2
a(n+1)a(n)		       0     x      0        y	 	           a(1)a(0)




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
                c.g[i][j] = (a.g[i][k] * b.g[k][j] + c.g[i][j]) % m;
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
