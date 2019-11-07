//HDU 3974
Description
Andy the smart computer science student was attending an algorithms class when the professor asked the students a simple question, 
"Can you propose an efficient algorithm to find the length of the largest palindrome in a string?"

A string is said to be a palindrome if it reads the same both forwards and backwards, for example "madam" is a palindrome while "acm" 
is not.

The students recognized that this is a classical problem but couldn't come up with a solution better than iterating over all substrings 
and checking whether they are palindrome or not, obviously this algorithm is not efficient at all, after a while Andy raised his hand 
and said "Okay, I've a better algorithm" and before he starts to explain his idea he stopped for a moment and then said "Well, I've an 
even better algorithm!".

If you think you know Andy's final solution then prove it! Given a string of at most 1000000 characters find and print the length of the 
largest palindrome inside this string.



Input
Your program will be tested on at most 30 test cases, each test case is given as a string of at most 1000000 lowercase characters on a 
line by itself. The input is terminated by a line that starts with the string "END" (quotes for clarity).



Output
For each test case in the input print the test case number and the length of the largest palindrome.



Sample Input
abcbabcbabcba
abacacbaaaab
END



Sample Output
Case 1: 13
Case 2: 6





#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include <queue>
#include<map>
#define maxn 3000005
#define mod 10007
using namespace std;

int t, n, m, a, b, ans, which, arr[maxn], prefix[maxn];
bool vis[maxn];
char s[maxn], str[maxn];

void init(){
    str[0] = '$';
    str[1] = '#';
    for(int i = 0; i < m ; i++){
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    n = m * 2 + 2;
    str[n] = '*';
}

void manacher(){
    int id = 0, mx = 0;
    for(int i = 1; i < n ; i++){
        if(mx > i) arr[i] = min(arr[2 * id - i], mx - i);
        else{
            arr[i] = 1;
        }
        while( str[i + arr[i]] == str[i - arr[i]])  arr[i]++;
         if(arr[i] + i > mx){
            mx = arr[i] + i;
            id = i;
        }
        ans = max(ans , arr[i]);
    }
}

int main() {
    //freopen("Test.txt", "r", stdin);
    which = 1;
    while( scanf("%s", s) ){
        if(s[0] == 'E'){
            break;
        }
        ans = 0;
        m = strlen(s);
        init();
        manacher();
        printf("Case %d: %d\n", which++, ans - 1);
    }
    return 0;
}
