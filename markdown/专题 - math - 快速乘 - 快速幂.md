#### 快速幂

#### 快速乘
> [offer1.整数除法](/剑指offer/1.%20整数除法.md)中需要不能用`*`, 只能用`+`求乘法

```CPP
long long mul(long long a, long long k) {
    long long ans = 0;
    while (k > 0) {
        if ((k & 1) == 1)
            ans += a;
        k >>= 1;
        a += a;
    }
    return ans;
}
```

##### 快速幂
> 快速幂能够使用`O(logn)`的时间复杂度计算乘方
> 
> ![快速幂](/appendix/acwing-%E5%BF%AB%E9%80%9F%E5%B9%82.png)
> 
> ![快速幂](/appendix/acwing-%E5%BF%AB%E9%80%9F%E5%B9%822.png)
> 
> **y总视角**
> 
> **Step 1**: 先预处理出 $a^{2^0} mod P$, $a^{2^1} mod P$, $a^{2^2} mod P$, ... , $a^{2^{\log_2k}}$
> 
> **Step 2**: 将指数处理成二进制形式, e.g. `26=11010` ➡️ $a^{26} = a^{2^1} * a^{2^3} * a^{2^5}$

###### 1. 迭代写法
```CPP
// 非递归方式实现快速幂
int quickPow(int a, int n){
    long long ans = 1;
    while(n != 0){
        if(n & 1)       // 如果n的当前末位为1
            ans *= a;   // ans乘上当前的a
        a *= a;         // a自乘
        n >>= 1;        // n往右移一位, 表示除以2
    }
    return ans;
}
```

###### 2. 递归写法
```CPP
// 递归方式计算快速幂 (不考虑mod大素数)
int quickPow(int a, int n){
    if(n==0)
        return 1;
    if(n % 2 == 1)
        return a * quickPow(a, n-1);
    else{
        long long half = quickPow(a, n/2);
        return half ** 2;
    }
}
```


##### [Acwing875. 快速幂](/acwing/Section%204/4_%E5%BF%AB%E9%80%9F%E5%B9%82.cpp): `a ^ b mod p`

```CPP
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
```
