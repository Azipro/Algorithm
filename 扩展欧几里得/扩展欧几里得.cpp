简介
扩展欧几里得算法的功能就更强大了，它可以用来求二元一次方程的通解，还可以用来求乘法逆元。 
在此顺便简介一下乘法逆元： 
若有 a*x ≡ 1 （mod m），则称 x 为a关于m的乘法逆元，等价式 a * x+m * y = 1 

引理 
裴蜀定理：若ax+by = z，则 gcd（a，b）| z 
再顺手证明一下裴蜀定理： 
设k = gcd（a，b），则 k | a， k | b，根据整除的性质，有 k | （ax+by） 
设 s为ax+by的最小正数值 
再设 q = [a / s]（a整除s的值）；r = a mod s = a-q（ax+by） = a（1 - qx）+b（-qy）； 
由此可见r也为a，b的线性组合；（ax+by称为a，b的线性组合） 
又因为s为a，b的线性组合的最小正数值，0<= r < s，所以r的值为0，即 a mod s = r =0；s | a； 
同理可得 s | b，则 s | k； 
又因为 k | （ax+by），s为ax+by的最小正数值，所以 k | s； 
因为 s | k，k | s，所以s = k； 
原命题得证。

如何求解 （以下讨论a>b） 
显然当 b=0，gcd（a，b）=a。此时 x=1，y=0； 
当a>b>0 时 
设 ax1+ by1= gcd（a，b）； 
bx2+ （a mod b）y2= gcd（b，a mod b）； 
根据欧几里德原理有 gcd（a，b） = gcd（b，a mod b）； 
则：ax1+ by1= bx2+ （a mod b）y2； 
即：ax1+ by1= bx2+ （a - [a / b] * b）y2 = ay2+ bx2- [a / b] * by2；（a mod b = a - [a / b]*b；[a / b]代表a整除b） 
也就是ax1+ by1 = ay2 + b（x2- [a / b] *y2）； 
根据恒等定理得：x1=y2；y1=x2- [a / b] *y2； 
这样我们就得到了求解 x1，y1 的方法：x1，y1 的值基于 x2，y2 
由引理我们知道：ax+by = z，z为gcd（a，b）若干倍，所以我们先求解ax+by = gcd（a，b），再将求出的解乘以 z/gcd（a，b）就好了。

1.若gcd(a, b) == 1，则方程ax ≡ c(mod b)在[0, b - 1]上有唯一解。
2.若gcd(a, b) == d，则方程ax ≡ c(mod b)在[0, b / d]上有唯一解。

int exGcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = exGcd(b,a%b,y,x);
    y -= x*(a/b);
    return r;
}
