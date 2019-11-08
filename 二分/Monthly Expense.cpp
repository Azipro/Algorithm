//POJ 3273
Description
Farmer John is an astounding accounting wizard and has realized he might run out of money to run the farm. He has already calculated and 
recorded the exact amount of money (1 ≤ moneyi ≤ 10,000) that he will need to spend each day over the next N (1 ≤ N ≤ 100,000) days.

FJ wants to create a budget for a sequential set of exactly M (1 ≤ M ≤ N) fiscal periods called "fajomonths". Each of these fajomonths 
contains a set of 1 or more consecutive days. Every day is contained in exactly one fajomonth.

FJ's goal is to arrange the fajomonths so as to minimize the expenses of the fajomonth with the highest spending and thus determine his
monthly spending limit.

Input
Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 contains the number of dollars Farmer John spends on the ith day

Output
Line 1: The smallest possible monthly limit Farmer John can afford to live with.

Sample Input
7 5
100
400
300
100
500
101
400

Sample Output
500

Hint
If Farmer John schedules the months so that the first two days are a month, the third and fourth are a month, and the last three are their
own months, he spends at most $500 in any month. Any other method of scheduling gives a larger minimum monthly limit.



#include <iostream>
#include <algorithm>
#define MAX_N 100001

using namespace std;

int main() {
    int N = 0, M = 0;
    int money[MAX_N] = { 0 };
    cin >> N >> M;
    long long L = 0;
    long long R = 0;
    for(int i = 0; i < N; i++) {
        cin >> money[i];
        if(L < money[i])L = money[i];
        R += money[i];
    }
    long long mid = 0;
    while(R>L){
        mid=(R+L)/2;
        long long cost=0;
        int Count=0;
        for(int i=0;i<N;i++){
            if(cost+money[i]>mid){
                Count++;
                cost=money[i];
            }
            else cost+=money[i];
        }
        Count++;
        if(Count <= M)
            R=mid;
        else
            L=mid+1;
    }
    cout << R << endl;
    return 0;
}
