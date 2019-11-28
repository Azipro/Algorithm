// POJ 2001

Description
A prefix of a string is a substring starting at the beginning of the given string. The prefixes of "carbon" are: "c", "ca", "car",
"carb", "carbo", and "carbon". Note that the empty string is not considered a prefix in this problem, but every non-empty string 
is considered to be a prefix of itself. In everyday language, we tend to abbreviate words by prefixes. For example, "carbohydrate" 
is commonly abbreviated by "carb". In this problem, given a set of words, you will find for each word the shortest prefix that 
uniquely identifies the word it represents.

In the sample input below, "carbohydrate" can be abbreviated to "carboh", but it cannot be abbreviated to "carbo" (or anything shorter) 
because there are other words in the list that begin with "carbo".

An exact match will override a prefix match. For example, the prefix "car" matches the given word "car" exactly. Therefore, it is 
understood without ambiguity that "car" is an abbreviation for "car" , not for "carriage" or any of the other words in the list that
begins with "car".
Input

The input contains at least two, but no more than 1000 lines. Each line contains one word consisting of 1 to 20 lower case letters.

Output
The output contains the same number of lines as the input. Each line of the output contains the word from the corresponding line of 
the input, followed by one blank space, and the shortest prefix that uniquely (without ambiguity) identifies this word.

Sample Input
carbohydrate
cart
carburetor
caramel
caribou
carbonic
cartilage
carbon
carriage
carton
car
carbonate

Sample Output
carbohydrate carboh
cart cart
carburetor carbu
caramel cara
caribou cari
carbonic carboni
cartilage carti
carbon carbon
carriage carr
carton carto
car car
carbonate carbona

#include<iostream>
#include<cstdio>
#include<string.h>
#define maxn 1005
using namespace std;

char dic[maxn][26];
int ans = 0;

struct node {
    int count;
    node* next[26];
    node() {
        count = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
}*tree;

void creat(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(p->next[x] == NULL) {
            p->next[x] = new node();
        }
        p = p->next[x];
        p->count++;
    }
}

int find(char* s) {
    node* p = tree;
    for(int i = 0; i < strlen(s); i++) {
        int x = s[i] - 'a';
        if(!p->next[x]) {
            return 0;
        }
        p = p->next[x];
    }
    return p->count;
}

int main() {
    tree = new node();
    bool is = true;
    char d[26];
    while(scanf("%s", dic[ans]) != EOF) {
        creat(dic[ans]);
        ans++;
    }
    for(int i = 0; i < ans; i++) {
        int len = strlen(dic[i]);
        is = true;
        memset(d, '\0', sizeof(d));
        for(int j = 0; j < len; j++) {
            strncpy(d, dic[i], j);
            if(find(d) == 1) {
                cout << dic[i] << " " << d << endl;
                is = false;
                break;
            }
        }
        if(is) {
            cout << dic[i] << " " << dic[i] << endl;
        }
    }
    return 0;
}
