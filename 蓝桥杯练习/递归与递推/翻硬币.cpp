//第四届蓝桥杯省赛C++B组
#include <iostream>
#include <cstring>
using namespace std;

char target[105], s[105];
int ans;

void trun(int x){
    if(s[x] == 'o') s[x] = '*';
    else s[x] = 'o';
}

int main(){
    cin >> s >> target;
    for(int i = 0 ; i < strlen(s) - 1 ; i ++){
        if(s[i] != target[i]){
            ans ++;
            trun(i + 1);
        }
    }
    cout << ans << endl;
}