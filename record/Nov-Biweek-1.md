#### Biweek 1

##### []()
> 对数据结构的类型要敏感一些, `set<int>`还找了半天...


##### []()
> `dp[i] = dp[i-zero] + dp[i-one]`
> 
> 初始化, 对所有`zero`, `one`的倍数计数 => `dp[k*zero]+=1` & `dp[k*one]+=1`