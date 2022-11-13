#### Biweek 1

##### 1. [不同的平均值数目](https://leetcode.cn/problems/number-of-distinct-averages/)
> 对数据结构的类型要敏感一些, `set<int>`还找了半天...
> 
> 更明智的做法是不除2...


##### 2. [统计构造好字符串的方案数](https://leetcode.cn/problems/count-ways-to-build-good-strings/): `一维dp`
> `dp[i] = dp[i-zero] + dp[i-one]`
> 
> 初始化, 对所有`zero`, `one`的倍数计数 => `dp[k*zero]+=1` & `dp[k*one]+=1`