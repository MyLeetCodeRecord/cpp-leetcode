#### 容斥原理

> **韦恩图**
> 
> ![韦恩图](/appendix/acwing-%E9%9F%A6%E6%81%A9%E5%9B%BE.png)

> **容斥原理**
> 
> ![容斥原理公式](/appendix/acwing-%E5%AE%B9%E6%96%A5%E5%8E%9F%E7%90%86.png)
>
> **复杂度**: 假设有m个集合, 则一共有`2^m-1`个项 (对应`2^m-1`种选法)


##### [Acwing980. 能被整除的数🧡](/acwing/Section%204/3_%E5%AE%B9%E6%96%A5%E5%8E%9F%E7%90%86_%E8%83%BD%E8%A2%AB%E6%95%B4%E9%99%A4%E7%9A%84%E6%95%B0.cpp)

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
    for(int i=1; i<(1<<m); i++){
        int cnt = 0;        // 二进制状态 i 中 1 的个数
        long long t = 1;    // 乘积 = 容斥原理中的交集
        for(int j=0; j<m; j++){
            if(i >> j & 1){
                cnt++;
                t *= prime[j];
                if(t > n){  // 大于n的数不能被n整除
                    t = -1;
                    break;
                }
            }
        }
        if(t == -1){
            continue;
        }
        else if(cnt & 1){
            ans += n/t;
        }
        else{
            ans -= n/t;
        }
    }
    cout<<ans<<endl;
    return 0;
}
```


##### [LC223. 矩形面积💚](/workspace/223.%E7%9F%A9%E5%BD%A2%E9%9D%A2%E7%A7%AF.cpp)

> 如果正向很难判断, 就做反向判断(无重叠情况)
> 
> 找到相交矩形求解的共同点: 
> 
> `unionArea = |min(ay2, by2)-max(ay1, by1)| * |min(ax2, bx2)-max(ax1, bx1)|`

```CPP
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2-ax1) * (ay2-ay1);
    int area2 = (bx2-bx1) * (by2-by1);
    // 无重叠更好判断
    if(ay1>=by2 || by1>= ay2 || ax2<=bx1 || bx2<=ax1){
        return area1 + area2;
    }
    else{
        int unionArea = abs(min(ay2, by2)-max(ay1, by1)) * abs(min(ax2, bx2)-max(ax1, bx1));
        return area1 + area2 - unionArea;
    }
}
```

##### [Acwing873. 欧拉函数🧡](/acwing/Section%204/3_%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0.cpp)

> ![欧拉函数](/appendix/acwing-%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0.png)
> 
> **Step 1**: 对`N`做[质因数分解](/acwing/Section%204/1_%E5%88%86%E8%A7%A3%E8%B4%A8%E5%9B%A0%E6%95%B0.cpp) `N = p1^a1 + p2^a2 + ... + pk^ak`, `pi`表示质因数, `ai`表示`pi`的幂次
>  
> **Step 2**: `N`当中能被`pi`整除的数字个数为`N / pi`
> 
> 以`N=24`
>   - 去掉`pi`的所有倍数, 比如12, 被2,3,4,6重复去掉了
>   - 补上`pi * pj`中的数字, 把两个质数的公共倍数的次数补回来, 但有一些数补多了, 比如12, 被<2,3>=6补了一次, 被<2,6>=12补了一次, 被<3,4>=12补了一次
>   - 在`pi * pj * pk`中把补多了的数字减掉
>   - 以此类推……
> 
> ![欧拉函数](/appendix/acwing-%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0-%E5%AE%B9%E6%96%A5%E5%8E%9F%E7%90%86.png)

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

/* 欧拉函数: 用公式做*/
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
                // 每次除尽
                while(x % j==0){
                    x /= j;
                }
            }
        }
        if(x > 1)
            ans = ans / x *(x-1);
        cout<<ans<<endl;
    }
    return 0;
}
```