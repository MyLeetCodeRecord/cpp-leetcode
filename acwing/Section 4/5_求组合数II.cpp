#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000010;
const int MOD = 1000000007;
int fact[N], infact[N];

int quickPow(int a, int n, int p){
    long long ans = 1;
    while(n != 0){
        if(n & 1){
            ans *= a;
            ans %= p;
        }
        a = (long long)a*a % p;
        n >>= 1;
    }
    return ans;
}
void calcCombination(){
    fact[0] = 1;
    infact[0] = 1;
    for(int i=1; i<N; i++){
        fact[i] = (long long)fact[i-1] * i % MOD;
        infact[i] = (long long)infact[i-1] * quickPow(i, MOD-2, MOD) % MOD;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    calcCombination();
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = (long long)fact[a] * infact[a-b] % MOD * infact[b] % MOD;
        printf("%d\n", ans);
    }
    return 0;
}