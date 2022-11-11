#include <cstdio>
#include <iostream>
using namespace std;

int quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n != 0){
        // 二进制为1时, 计当前位
        if(n & 1){
            ans *= a;
            ans %= mod;
        }
        // 注意这里也要对a^k做mod处理
        a = (long long)a * a % mod;     // 7^1, 7^2, 7^4 ...
        n >>= 1;
    }
    return ans % mod;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);
        cout<<quickPow(a, b, p)<<endl;
    }
    return 0;
}