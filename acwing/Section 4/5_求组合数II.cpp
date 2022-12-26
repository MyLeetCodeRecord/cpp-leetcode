#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
const int MOD = 1000000007;
int fact[N], infact[N];

int quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n != 0){
        if(n & 1)
            ans = ans * a % mod;
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return ans % mod;
}
void prepareFacts(){
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
    prepareFacts();
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = (long long)fact[a] * infact[b] % MOD * infact[a-b] % MOD;
        printf("%d\n", ans);
    }
    return 0;
}