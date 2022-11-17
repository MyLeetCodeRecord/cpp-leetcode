#### 耍杂技的牛

> 从上到下, 每个位置`i`上奶牛的危险值 = `W1 + W2 + ... + Wi-1 - Si`
> 
> 假设已有一种排序`「<W1, S1>, <W2, S2>, ... , <Wi, Si>, <Wi+1, Si+1>, ... , <Wn, Sn>」`
> 
> 若`Wi+Si > Wi+1+Si+1`, 现将`i`放在`i+1`上方, 试图交换`<Wi,Si>` & `<Wi+1,Si+1>`
>
> |  |交换前|交换后|
> |---|:-:|:-:|
> |第 i 头牛|`sum(1~i-1)-Si`|`sum(1~i-1)+Wi+1-Si`|
> |第i+1头牛|`sum(i~i-1)+Wi-Si+1`|`sum(1~i-1)-Si+1` |
> 
> 去掉公共项`sum(1~i-1)`
> 
> |  |交换前|交换后|
> |---|:-:|:-:|
> |第 i 头牛|-Si|Wi+1-Si|
> |第i+1头牛|Wi-Si+1|-Si+1|
> 
> 只要满足 `Wi-Si+1 > Wi+1-Si`  =>  `Wi + Si > Wi+1 + Si+1` => 交换后不会更差 => `Wi+Si`越大的应该放在越下面
>
> 结论: 将更大的`Wi+Si`的牛放到底下, 结果不会变差


```CPP
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
 
typedef pair<int,int> PII;  // first存储w+s, 方便排序

const int N = 50010;
PII cows[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int w, s;
        scanf("%d %d", &w, &s);
        cows[i] = {w+s, w};
    }
    // 按 w+s 排序
    sort(cows, cows+n);
    int ans = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        int w = cows[i].second;
        int s = cows[i].first - w;
        ans = max(ans, sum - s);
        sum += cows[i].second;
    }
    cout<<ans<<endl;
    return 0;
}
```