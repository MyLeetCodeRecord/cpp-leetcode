#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n==1)
        return false;
    for(int i=2; i<=n/i; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main(){
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        if(isPrime(x))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}