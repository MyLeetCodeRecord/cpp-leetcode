#### 容斥原理

> **韦恩图**
> 
> ![韦恩图](/appendix/acwing-%E9%9F%A6%E6%81%A9%E5%9B%BE.png)

> **容斥原理**
> 
> ![容斥原理公式](/appendix/acwing-%E5%AE%B9%E6%96%A5%E5%8E%9F%E7%90%86.png)
>
> **复杂度**: 假设`m`个集合, 则一共有`2^m-1`个项 (对应`2^m-1`种选法), 再乘上计算每一项的复杂度即可


##### [Acwing890. 能被整除的数](/acwing/Section%204/3_%E5%AE%B9%E6%96%A5%E5%8E%9F%E7%90%86_%E8%83%BD%E8%A2%AB%E6%95%B4%E9%99%A4%E7%9A%84%E6%95%B0.cpp)

> 一共有个`2^M`项(集合), 每个集合(可能是同时满足多个性质的交集)怎么求?
> 
> - 用`M`位二进制表示满足哪几个集合的性质(第`j`位为`1`表示能整除`primes[j]`, 为`0`表示不能整除`primes[j]`)
>
> - 从`1`开始枚举`(1<<M) - 1`个状态, 解构`M`个状态位, 同时用`t`记录当前状态`i`下, 为`1`的位置对应的`primes[j]`的乘积, 表示第`i`个状态项对应的集合具有「能被这些`primes[j]`整除」的性质, 集合元素数量 = `n/t` 
> (因为所有元素都是质数, 所以最小公倍数就是元素乘积 -> 可以用n/t求解)
> 
> - e.g. `primes[0]`, `primes[1]` => `M=2` => 对应`00 ~ 11`共`2^M-1=3`个状态
>   - `M = 1 = (01)`时, 表示「能被`primes[0]`」整除的数的集合
>   - `M = 2 = (10)`时, 表示「能被`primes[1]`」整除的数的集合
>   - `M = 3 = (11)`时, 表示「能被`t = primes[0]*primes[1]`」整除的数的集合
>
> - 另外, 对于每个状态`i`, 需要对二进制为`1`的位置计数, 从而决定该项的符号
>   - 如果为**奇数**, `ans += n/1`
>   - 如果为**偶数**, `ans -= n/1`

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 16;
int prime[N];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d", &prime[i]);
    }
    // 容斥原理
    long long ans = 0;
    // 枚举(2^M - 1)个状态(或者看作「容斥原理公式中的(2^M - 1)个项」)
    for(int i=1; i<(1<<m); i++){
        // 用二进制表示集合所具有的性质(第j位为1表示能整除primes[j], 为0表示不能整除primes[j])
        int cnt = 0;        // 二进制状态 i 中 1 的个数, 公式一项为cnt个集合的交集
        long long t = 1;    // 乘积 = 容斥原理中的交集
        for(int j=0; j<m; j++){
            if(i >> j & 1){
                cnt++；
                t *= prime[j];
                // 大于n的数不能被n整除(公式中这个项及后面的项都为0, 不需要计算), 退出即可
                if(t > n){
                    t = -1;
                    break;
                }
            }
        }
        // 状态i下, 如果取交集的个数cnt为奇数, 则系数为+; cnt为偶数, 则系数为-
        // |某cnt个集合的交集| = n / 乘积t (该集合具有的「性质」)
        if(t == -1)
            continue;
        else if(cnt & 1)
            ans += n/t;
        else
            ans -= n/t;
    }
    cout<<ans<<endl;
    return 0;
}
```


##### [LC223. 矩形面积](/workspace/223.%E7%9F%A9%E5%BD%A2%E9%9D%A2%E7%A7%AF.cpp)

> 如果正向很难判断, 就做反向判断(无重叠情况)
> 
> 找到相交矩形求解的共同点: 
> 
> `unionArea = |min(ay2, by2)-max(ay1, by1)| * |min(ax2, bx2)-max(ax1, bx1)|`

```CPP
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area = (ax2-ax1) * (ay2-ay1) + (bx2-bx1) * (by2-by1);
    // 无重叠更好判断, 有重叠与无重叠互补
    if(!(ay1>=by2 || by1>=ay2 || ax2<=bx1 || bx2<=ax1)){
        int width = min(ax2, bx2) - max(ax1, bx1);
        int height = min(ay2, by2) - max(ay1, by1);
        area -= width * height;
    }
    return area;
}
```
https://leetcode.cn/problems/rectangle-area/


##### [Acwing873. 欧拉函数](/acwing/Section%204/3_%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0.cpp)的证明

> ![欧拉函数](/appendix/acwing-%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0.png)
> 
> **Step 1**: 对`N`做[质因数分解](/acwing/Section%204/1_%E5%88%86%E8%A7%A3%E8%B4%A8%E5%9B%A0%E6%95%B0.cpp) `N = p1^a1 + p2^a2 + ... + pk^ak`, `pi`表示质因数, `ai`表示`pi`的幂次
>  
> **Step 2**: `N`当中能被`pi`整除的数字个数为`N / pi`
> 
> 以`N=24`为例,
>   - 去掉`pi`的所有倍数, 比如12, 被2,3,4,6重复去掉了
>   - 补上`pi * pj`中的数字, 把两个质数的公共倍数的次数补回来, 但有一些数补多了, 比如12, 被<2,3>=6补了一次, 被<2,6>=12补了一次, 被<3,4>=12补了一次
>   - 在`pi * pj * pk`中把补多了的数字减掉
>   - 以此类推······
> 
> ![欧拉函数](/appendix/acwing-%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0-%E5%AE%B9%E6%96%A5%E5%8E%9F%E7%90%86.png)

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

/* 欧拉函数: 用公式做, 但是推导需要容斥原理 */
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        int ans = x;
        // 分解质因数
        for(int j=2; j<=x/j; j++){
            if(x % j==0){
                ans = ans / j * (j-1);
                // 虽然不涉及cnt, 但必须每次除尽
                while(x % j==0){
                    x /= j;
                }
            }
        }
        // 公式, 先除后乘可以减小数据规模
        if(x > 1)
            ans = ans / x * (x-1);
        printf("%d\n", ans);
    }
    return 0;
}
```


##### [LC878. 第n个神奇数字](/workspace/878.%E7%AC%AC-n-%E4%B8%AA%E7%A5%9E%E5%A5%87%E6%95%B0%E5%AD%97.cpp): `gcd`, `lcm`, `容斥原理`, `二分查找`

> - 容斥原理求`x`范围内的神奇数个数
> 
>   - 能被 a 或 b 整除 = 被 a 整除 + 被 b 整除 - 既能被 a 又能被 b 整除
> 
>   - x 中被 a 整除的正整数 = x // a
> 
> - 单调性 ➕ 第n个 ➡️ `二分查找` (target不唯一, 左边界模板)

```CPP
typedef long long LL;

int gcd(int a, int b){
    if(a % b == 0)
        return b;
    return gcd(b, a % b);   // "%"而不是"-"
}
int nthMagicalNumber(int n, int a, int b) {
    // a, b是定值, 应该先计算出最小公倍数, 减少重复计算, 并且lcm_ab不应该取模
    // [大上周周赛]最小公倍数 = a*b/gcd(a,b)
    LL lcm_ab = a / gcd(max(a, b), min(a, b)) * b;
    
    LL l = min(a, b);
    LL r = (LL) n * min(a, b);
    while(l < r){
        LL mid = (l+r)/2;
        LL magic = mid/a + mid/b - mid/lcm_ab;  // 容斥原理
        if (magic < n)
            l = mid+1;
        else
            r = mid;
    }
    return l % 1000000007;
}
```
https://leetcode.cn/problems/nth-magical-number/