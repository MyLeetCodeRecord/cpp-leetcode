#### 快速幂
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
> **Step 2**: 将指数处理成二进制形式, e.g. `26=11010` ➡️
 $a^{26} = a^{2^1} * a^{2^3} * a^{2^5}$
```CPP
// 非递归方式实现快速幂
int quickPow(int a, int n){
    int ans = 1;
    while(n != 0){
        if(n & 1)       // 如果n的当前末位为1
            ans *= a;   // ans乘上当前的a
        a *= a;         // a自乘
        n >>= 1;        // n往右移一位,表示除以2
    }
    return ans;
}
```


```CPP
// 递归方式计算快速幂 (不考虑mod大素数)
int quickPow(int a, int n){
    if(n==0)
        return 1;
    if(n % 2 == 1)
        return a * quickPow(n-1);
    else
        return quickPow(n/2) ** 2;
}
```