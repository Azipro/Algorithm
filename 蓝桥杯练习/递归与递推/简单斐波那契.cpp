#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    int a = 0, b = 1;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            printf("%d ", a);
            continue;
        }else if(i == 1){
            printf("%d ", b);
            continue;
        } 
        int x = a + b;
        a = b;
        b = x;
        printf("%d ", x);
    }
    return 0;
}