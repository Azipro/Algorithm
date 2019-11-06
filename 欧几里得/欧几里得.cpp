引理：
欧几里得有个非常强的定理，即gcd(a,b)=gcd(b,a mod b)，让我们来证明一下（mod 是取余，gcd是最大公约数，| 是能整除） 
假设a、b的公约数为k，a = bx + y 
则 k | a，k | b，a mod b=y 
因为 k | b，所以 k |bx，又因为 k | a，所以 k | (a - bx)，即 k | y 
而a mod b = y，所以 k | a mod b 
再假设b、a mod b的公约数为kk，同理得 kk | a，所以（a，b）和（b，a mod b）的公约数是相同的，所以它们的最大公约数也是相同的 
所以gcd(a,b)=gcd(b,a mod b)


最大公约数
int gcd(int x, int y){
          return y == 0 ? x : gcd(y, x % y);
}
