#### 组合数

##### [Acwing885. 求组合数I](/acwing/Section%204/5_%E7%BB%84%E5%90%88%E6%95%B0I.cpp)

> 由于`0<=b<=a<=2000`数据范围比较小, 可以用直接用递推公式建立`dp`来做
> 
> 思路就是用递推关系, `a`个苹果中选择`b`个
> 
> - 第`a`个不选, 则前`a-1`个苹果中要选择`b`个
> - 第`a`个选, 则前`a-1`个苹果要选择`b-1`个
>
> 递归(状态转移)公式: `C(a, b) = C(a-1, b-1) + C(a-1, b)`


##### [Acwing886. 求组合数II](/acwing/Section%204/5_%E6%B1%82%E7%BB%84%E5%90%88%E6%95%B0II.cpp)

> `a`和`b`的数据范围是`0<=b<=a<100000`, 直接状态转移会超时, 需要进行**预处理**
> 
> `C(a, b) = (a!) / [(a-b)! * (b!)]`
> 
> **预处理**: 首先要提前计算好`a!`, `(a-b)!`, `b!`
> 
> 分母中的阶乘`(a-b)!`和`b!`可以用**逆元**(费马小定理, $a^{-2}$)表示
> 
> 要用到[快速幂求逆元](/acwing/Section%204/Acwing%20-%20%E5%BF%AB%E9%80%9F%E5%B9%82.md), 即`infact(a) = quickPow(a, p-2, p)`

```CPP
for(int i=1; i<N; i++){
    fact[i] = (long long)fact[i-1] * i % MOD;
    infact[i] = (long long)infact[i-1] * quickPow(i, MOD-2, MOD) % MOD;
}
```

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
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
// 预处理: 求出阶乘和阶乘的逆元
void prepareFact(){
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
```