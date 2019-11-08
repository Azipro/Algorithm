```
prefix数组就是一个字符串从1个字符到n-1个字符的最长公共前缀，prefix[0]补 -1.
i 和  j 分别指向原字符串的匹配位置，以及匹配字符串的匹配位置。
一个一个向后匹配。 若不相同，则 j = prefix[j]， 即让匹配字符串的匹配位置指向prefix[j]，并与原字符串匹配位置对齐。 
也就是说i，j始终要对齐。


int n, m, prefix[maxn];
char s[maxn], in[maxn];

        n = strlen(s);
        m = strlen(in);
        setPrefix();
        KMP();

void setPrefix() {
    int i = 0;
    int len = -1;
    prefix[0] = -1;
    while(i < m) {
        if(len == -1 || in[i] == in[len]) {
            len++;
            i++;
            prefix[i] = len;
        } else {
            len = prefix[len];
        }
    }
}

void KMP() {
    int i = 0;
    int j = 0;
    while(i < n && j < m) {
        if(j == -1 || s[i] == in[j]) {
            i++;
            j++;
        } else {
            j = prefix[j];
        }
        if(j == m) {
            ans++;  //已经找到匹配的一个字符串
            j = 0;  //继续往下查找，与找过的不重复
  （j=prefix[j];) // 继续找，与找过的可重复
        }
    }
}

如 azazaza  中找有几个aza
与找过的不重复，则找到俩个
与找过的重复，则找到三个


例：
aaa  需要补0个，构成循环
abca  需要补2个，构成循环
abcde 需要补5个，构成循环
int p = prefix[n];
if(n % (n - p) == 0){
         printf("0");
}else if(p == 0){
         printf("%d", n);
}else{
        printf("%d", (n - p - n % (n - p)));
}
即 n - p 就为一个循环节的长度
```
