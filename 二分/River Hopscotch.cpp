//POJ 3258
Description
Every year the cows hold an event featuring a peculiar version of hopscotch that involves carefully jumping from rock to rock in a river. 
The excitement takes place on a long, straight river with a rock at the start and another rock at the end, L units away from the 
start (1 ≤ L ≤ 1,000,000,000). Along the river between the starting and ending rocks, N (0 ≤ N ≤ 50,000) more rocks appear, each at an 
integral distance Di from the start (0 < Di < L).

To play the game, each cow in turn starts at the starting rock and tries to reach the finish at the ending rock, jumping only from rock 
to rock. Of course, less agile cows never make it to the final rock, ending up instead in the river.

Farmer John is proud of his cows and watches this event each year. But as time goes by, he tires of watching the timid cows of the other
farmers limp across the short distances between rocks placed too closely together. He plans to remove several rocks in order to increase
the shortest distance a cow will have to jump to reach the end. He knows he cannot remove the starting and ending rocks, but he calculates
that he has enough resources to remove up to M rocks (0 ≤ M ≤ N).

FJ wants to know exactly how much he can increase the shortest distance *before* he starts removing the rocks. Help Farmer Johndetermine
the greatest possible shortest distance a cow has to jump after removing the optimal set of M rocks.


Input
Line 1: Three space-separated integers: L, N, and M
Lines 2..N+1: Each line contains a single integer indicating how far some rock is away from the starting rock. No two rocks share the 
same position.

Output
Line 1: A single integer that is the maximum of the shortest distance a cow has to jump after removing M rocks

Sample Input
25 5 2
2
14
11
21
17

Sample Output
4

Hint
Before removing any rocks, the shortest jump was a jump of 2 from 0 (the start) to 2. 
After removing the rocks at 2 and 14, the shortest required jump is a jump of 4 (from 17 to 21 or from 21 to 25).



#include <iostream>
#include <algorithm>
#define MAX_N 50010
using namespace std;

int L, N, M;
int rock[MAX_N];

bool judge(int x) {
    int del=0;
    int At=0;
    for(int i = 1; i <= N + 1; ) {
        if(x <= rock[i] - rock[At]) {
            i++;
            At=i-1;
        }
        else {
            i++;
            del++;
        }
    }
    if(del <= M) return false;
    return true;
}

int main() {
    cin >> L >> N >> M;
    rock[0]=0;
    for(int i = 1; i <= N; i++) {
        cin >> rock[i];
    }
    rock[N + 1] = L;
    sort(rock, rock + N + 1);
    int right = L * 2, left = 0;
    while(right > left + 1) {
        int mid = right + left >> 1;
        if(judge(mid)) right = mid;
        else left = mid;
    }
    cout << left << endl;
    return 0;
}
