#### Weekly 326

> 元旦福利场之第一次ak
>
> 打扰了, t4被rej了...

##### 1. [统计能整除数字的位数](https://leetcode.cn/problems/count-the-digits-that-divide-a-number/): `十进制数`

> tips: 十进制逐位处理, 可以直接转为字符串

```CPP
int countDigits(int num) {
    int ans = 0;
    int n = num;
    while(n != 0){
        int cur = n % 10;
        if(num % cur==0)
            ans++;
        n /= 10;
    }
    return ans;
}
```


##### 2. [数组乘积中的不同质因数数目](https://leetcode.cn/problems/distinct-prime-factors-of-product-of-array/): `math` `质因数分解`

```CPP
unordered_set<int> st;
void dividePrimes(int n){
    for(int i=2; i<=n/i; i++){
        while(n % i==0){    // 每次除尽
            st.insert(i);
            n /= i;
        }
    }
    if(n != 1)
        st.insert(n);
}
int distinctPrimeFactors(vector<int>& nums) {
    for(int n: nums){
        dividePrimes(n);
    }
    return st.size();
}
```


##### 3. [将字符串分割成值不超过 K 的子字符串](https://leetcode.cn/problems/partition-string-into-substrings-with-values-at-most-k/): `dp`

> 当一道题连`0`都没有, 它可真是一道大水题
> 
> `dp[i]`: 将`s[:i]`分割成值不超过`K`的子串的最少个数
> 
> - 初始化: `dp[0] = 0`
> 
> - 状态转移方程: `dp[i]=dp[j]+`, `j & j<i & s[j:i]<=k` 

```CPP
int minimumPartition(string s, int k) {
    int k_len = to_string(k).size();
    int n = s.size();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=max(0, i-k_len); j<i; j++){
            if(i-j<=k_len && stoi(s.substr(j, i-j)) <= k){
                if(dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n]>=INT_MAX ? -1 : dp[n];
}
```


##### 4. [范围内最接近的两个质数](https://leetcode.cn/problems/closest-prime-numbers-in-range/): `math` `质数筛法`

- [x] 复习`素数筛法`

###### 方法一: 埃式筛法 - `O(nloglogn)`
> 朴素筛法: 从小到大, 把每个数的倍数筛掉, 剩下的数没有因数, 所以是质数
> - 每个非质数会被**所有因子**标记
> - 标记次数: `n/2 + n/3 + n/4 + ··· + 1 = O(nlnn)`
> 
> 埃式筛法: 进一步, 只筛掉质数的倍数, 减少一定量的重复标记
> - 每个数被**所有质因子**标记, (但`6`还是会被**所有质因子**`2`和`3`都标记一遍)
> - 标记次数: `n/2 + n/3 + n/5 + ···`, 只保留质数对应的项 (质数定理: 1~n中约有`n/lnn`个质数)

```CPP
int prime[N], idx = 0;
bool state[N];
int getPrimes(int n){
    for(int i=2; i<=n; i++){
        // 当前数 i 未被标记为非质数, 那说明它是质数
        if(!state[i]){
            prime[idx++] = i;
            // 埃氏筛法: 只标记「质数」的倍数
            for(int j=2*i; j<=n; j+=i){
                state[j] = true;
            }
        }
    }
    return idx;
}
getPrimes(n);
```

###### 方法二: 线性筛法 - `O(n)`
> `n`只会被它的**最小质因子**筛选掉, 不会重复筛选

```CPP
int prime[N], idx = 0;
bool state[N];
void getPrimes_linear(int n){
    for(int i=2; i<=n; i++){
        if(!state[i])
            prime[idx++] = i;
        for(int j=0; prime[j]<=n/i; j++){
            state[prime[j]*i] = true;
            if(i%prime[j]==0)       // primes[j]是i的最小质因子
                break;
        }
    }
}
getPrimes_linear(n);
```

> `rej`没过的原因: 如果`[L, R]`范围内没有质数, 也要返回`{-1, -1}`

```CPP
class Solution {
private:

public:
    int idx = 0;
    void getPrimes(vector<int> &prime, vector<bool> &state, int n){
        for(int i=2; i<=n; i++){
            // 当前数 i 未被标记为非质数, 那说明它是质数
            if(!state[i]){
                prime[idx++] = i;
                // 埃氏筛法: 只标记“质数”的倍数
                for(int j=2*i; j<=n; j+=i){
                    state[j] = true;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime(1000010, 0);
        vector<bool> state(1000010, false);
        getPrimes(prime, state, 1000010);
        int startIndex = -1;
        for(int i=0; prime[i]<=right; i++){
            if(prime[i]>=left){
                startIndex = i;
                break;
            }
        }
        // rej: 没有质数也要返回{-1, -1}
        if(startIndex == -1)
            return {-1, -1};
        int ans = right-left+1;
        vector<int> pii = {-1, -1};
        for(int i=startIndex; prime[i]<=right; i++){
            if(prime[i+1] <= right){
                if(prime[i+1]-prime[i] < ans){
                    pii[0] = prime[i];
                    pii[1] = prime[i+1];
                    ans = prime[i+1]-prime[i];
                }
            }
        }
        return pii;
    }
};
```