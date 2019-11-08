//HDU 3486
Problem Description
YaoYao has a company and he wants to employ m people recently. Since his company is so famous, there are n people coming for the interview.
However, YaoYao is so busy that he has no time to interview them by himself. So he decides to select exact m interviewers for this task.
YaoYao decides to make the interview as follows. First he queues the interviewees according to their coming order. 
Then he cuts the queue into m segments. The length of each segment is floor(n/m), which means he ignores the rest interviewees 
(poor guys because they comes late). Then, each segment is assigned to an interviewer and the interviewer chooses the best 
one from them as the employee.
YaoYao’s idea seems to be wonderful, but he meets another problem. He values the ability of the ith arrived interviewee as a number 
from 0 to 1000. Of course, the better one is, the higher ability value one has. He wants his employees good enough, so the sum of the 
ability values of his employees must exceed his target k (exceed means strictly large than). On the other hand, he wants to employ as 
less people as possible because of the high salary nowadays. Could you help him to find the smallest m?
 

Input
The input consists of multiple cases.
In the first line of each case, there are two numbers n and k, indicating the number of the original people and the sum of the ability 
values of employees YaoYao wants to hire (n≤200000, k≤1000000000). In the second line, there are n numbers v1, v2, …, vn 
(each number is between 0 and 1000), indicating the ability value of each arrived interviewee respectively.
The input ends up with two negative numbers, which should not be processed as a case.
 

Output
For each test case, print only one number indicating the smallest m you can find. If you can’t find any, output -1 instead.
 

Sample Input
11 300
7 100 7 101 100 100 9 100 100 110 110
-1 -1
 

Sample Output
3


Hint
We need 3 interviewers to help YaoYao. The first one interviews people from 1 to 3, the second interviews people from 4 to 6, 
and the third interviews people from 7 to 9. And the people left will be ignored. And the total value you can get is 100+101+100=301>300.


#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 200005
#define mod 10007
using namespace std;
typedef long long ll;

int t, n, m, a, b, ans, which, num[maxn], arr[maxn][20];
bool is, vis[maxn];
char ch, s[maxn], str[maxn];

void RMQ(){
    for(int j = 1 ; j <= log(n) / log(2) ; j++){
        for(int i = 1 ; i <= n ; i++){
            if(i + (1 << j) - 1 <= n)
            arr[i][j] = max(arr[i][j - 1], arr[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int k = (int)(log(r - l + 1) / log(2.0));
    int mx = max(arr[l][k], arr[r - (1 << k) + 1][k]);
    return mx;
}

int main() {
    //freopen("Test.txt", "r", stdin);
    int x, sum;
    while( scanf("%d %lld", &n, &x) && (n > 0 || x > 0) ){
        sum = 0;
        b = -1;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &arr[i][0]);
            sum += arr[i][0];
            b = max(b, arr[i][0]);
        }
        if(b > x){
            printf("1\n");
            continue;
        }
        if(sum <= x){
            printf("-1\n");
            continue;
        }
        RMQ();
        is = true;
        b = max(2, x / b);
        for(int i = b; i <= n; i++){
            m = n / i;
            a = 1;
            ans = 0;
            for(int j = 0; j < i ; j++){
                a = m * j + 1;
                b = a + m - 1;
                ans += query(a, b);
            }
            if(ans > x){
                printf("%d\n", i);
                is = false;
                break;
            }
        }
        if(is){
            printf("-1\n");
        }
    }
    return 0;
}
