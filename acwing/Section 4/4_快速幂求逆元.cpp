#include <cstdio>
#include <iostream>
using namespace std;

/* 费马小定理...
 * 也没听懂反正就是 a·a^(p-2) = 1 mod P
 * 答案是 a^(p-2), 复习一下快速幂
 */

int quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n != 0){
        if(n & 1){
            ans = ans * a % mod;
        }
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, p;
        scanf("%d %d", &a, &p);
        int a_reverse = quickPow(a, p-2, p);
        if(a % p == 0)
            printf("impossible\n");
        else
            printf("%d\n", a_reverse);
    }
    return 0;
}