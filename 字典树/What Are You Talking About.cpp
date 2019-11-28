// HDU 1075

Problem Description
Ignatius is so lucky that he met a Martian yesterday. But he didn't know the language the Martians use. The Martian gives him a history book of Mars and a dictionary when it leaves. Now Ignatius want to translate the history book into English. Can you help him?
 

Input
The problem has only one test case, the test case consists of two parts, the dictionary part and the book part. The dictionary part starts with a single line contains a string "START", this string should be ignored, then some lines follow, each line contains two strings, the first one is a word in English, the second one is the corresponding word in Martian's language. A line with a single string "END" indicates the end of the directory part, and this string should be ignored. The book part starts with a single line contains a string "START", this string should be ignored, then an article written in Martian's language. You should translate the article into English with the dictionary. If you find the word in the dictionary you should translate it and write the new word into your translation, if you can't find the word in the dictionary you do not have to translate it, and just copy the old word to your translation. Space(' '), tab('\t'), enter('\n') and all the punctuation should not be translated. A line with a single string "END" indicates the end of the book part, and that's also the end of the input. All the words are in the lowercase, and each word will contain at most 10 characters, and each line will contain at most 3000 characters.
 

Output
In this problem, you have to output the translation of the history book.
 

Sample Input
START
from fiwo
hello difh
mars riwosf
earth fnnvk
like fiiwj
END
START
difh, i'm fiwo riwosf.
i fiiwj fnnvk!
END
 

Sample Output
hello, i'm from mars.
i like earth!

Hint
Huge input, scanf is recommended.



#include<iostream>
#include<cstdio>
#include<string.h>
#include<map>
#define maxn 500005
using namespace std;

int at = 1;
string dic[maxn];
map<string, int>pp;

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

void creat(string s) {
    node* p = tree;
    for(int i = 0; i < s.length(); i++) {
        int x = s[i] - 'a';
        if(p->next[x] == NULL) {
            p->next[x] = new node();
        }
        p = p->next[x];
    }
    p->count++;
}

int find(string s) {
    node* p = tree;
    for(int i = 0; i < s.length(); i++) {
        int x = s[i] - 'a';
        if(p == NULL) {
            return 0;
        }
        p = p->next[x];
    }
    if(p == NULL)
        return 0;
    else
        return p->count;
}

int main() {
    tree = new node();
    while(1) {
        string a, b;
        cin >> a;
        if(a == "START") {
            continue;
        }
        if(a == "END") {
            break;
        }
        cin >> b;
        pp[b] = at;
        dic[at] = a;
        at++;
        creat(b);
    }
    getchar();
    while(1) {
        char c[5000];
        string a, b;
        gets(c);
        for(int i = 0; i < strlen(c); i++) {
            a += c[i];
        }
        if(a == "START") {
            continue;
        }
        if( a == "END") {
            break;
        }
        b = "";
        for(int i = 0; i < strlen(c); i++) {
            if(c[i] >= 'a' && c[i] <= 'z') {
                b += c[i];
            } else {
                if(b != "") {
                    if(find(b) > 0) {
                        cout << dic[pp[b]];
                    } else {
                        cout << b;
                    }
                    b = "";
                }
                cout << c[i];

            }
        }
        if(b != "") {
            if(find(b) > 0) {
                cout << dic[pp[b]];
            } else {
                cout << b;
            }
        }
        cout << endl;
    }
    return 0;
}
