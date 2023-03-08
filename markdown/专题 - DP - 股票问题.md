#### 股票问题

##### [LC121. 买卖股票的最佳时机Ⅰ](/workspace/121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/): 只买卖一次
> 
> 用一个`int变量`或者`dp[i]数组`记录第i天(包括第i天本身)的最低价值, 作为买入时间, 尝试用`price[i]-dp[i]`更新ans


##### [LC122. 买卖股票的最佳时机II](/workspace/122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-ii.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii): 同一时间最多持有一只股票, 可以不重叠地重复购买
> 
> 不需要手续费, 不需要最少买卖次数, 只要`prices[i-1] < prices[i]`就应该买入


##### [LC123. 买卖股票的最佳时机Ⅲ](/workspace/123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iii.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/): 只能进行两笔交易
> 
> ![LC123](/appendix/LC123.png)

```CPP
int maxProfit(vector<int>& prices) {
    // dp[0][i]: 第一股持有中, 到第i天能获得的最大余额
    // dp[1][i]: 已经卖出第一股, 暂时没有买入第二股, 到第i天能获得的最大余额
    // dp[2][i]: 第二股持有中, 到第i天能获得的最大余额
    // dp[3][i]: 已经卖出第二股, 到第i天能获得的最大余额
    vector<vector<int> > dp(4, vector<int>(prices.size(), 0));
    dp[0][0] = -prices[0];
    dp[1][0] = 0;
    dp[2][0] = -prices[0];
    dp[3][0] = 0;
    for(int i=1; i<prices.size(); i++){
        dp[0][i] = max(-prices[i], dp[0][i-1]);
        dp[1][i] = max(dp[0][i-1]+prices[i], dp[1][i-1]);
        dp[2][i] = max(dp[1][i-1]-prices[i], dp[2][i-1]);
        dp[3][i] = max(dp[2][i-1]+prices[i], dp[3][i-1]);
    }
    return max(dp[1].back(), dp[3].back());
}
```


##### [LC188. 买卖股票的最佳时机Ⅳ](/workspace/188.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iv.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/): 最多可以买卖k次
> 
> 做了上面的[LC123. 买卖股票的最佳时机Ⅲ](/workspace/123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iii.cpp), 这道题就不难了, 把交易次数从2次改为k次, 也就是引入一个`for(k)`
>
> 注意: 状态0是没有前一个状态的, 要单独处理

```CPP
int maxProfit(int k, vector<int>& prices) {
    if(prices.size()<=1)
        return 0;
    vector<vector<int> > dp(2*k, vector<int>(prices.size()));
    // 初始化
    for(int i=0; i<k; i++)
        dp[2*i][0] = -prices[0];
    for(int i=0; i<k; i++)
        dp[2*i+1][0] = 0;
    int ans = 0;
    for(int i=1; i<prices.size(); i++){
        for(int a=0; a<k; a++){
            if(a==0){
                dp[0][i] = max(-prices[i], dp[0][i-1]);
                dp[1][i] = max(dp[0][i-1]+prices[i], dp[1][i-1]);
            }
            else{
                dp[2*a][i] = max(dp[2*a-1][i-1]-prices[i], dp[2*a][i-1]);
                dp[2*a+1][i] = max(dp[2*a][i-1]+prices[i], dp[2*a+1][i-1]);
            }
            ans = max(ans, dp[2*a+1][i]);
        }
    }
    return ans;
}
```


##### [LC309. 买卖股票的最佳时机含冷冻期](/workspace/309.%E6%9C%80%E4%BD%B3%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E6%97%B6%E6%9C%BA%E5%90%AB%E5%86%B7%E5%86%BB%E6%9C%9F.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown) - 卖出后至少一天后才能买入
> 
> 同样是分析可能的状态
> - 0 - 持有股票 -> 只能保持 or 由状态2转化而来
> - 1 - 刚卖出股票 -> 只能由状态0转化而来
> - 2 - 卖出股票一天以上 -> 只能保持 or 由状态1转化而来
```CPP
int maxProfit(vector<int>& prices) {
    vector<vector<int> > dp(3, vector<int>(prices.size()));
    dp[0][0] = -prices[0];
    dp[1][0] = 0;
    dp[2][0] = 0;
    for(int i=1; i<prices.size(); i++){
        dp[0][i] = max(dp[0][i-1], dp[2][i-1] - prices[i]);
        dp[1][i] = dp[0][i-1] + prices[i];
        dp[2][i] = max(dp[2][i-1], dp[1][i-1]);
    }
    return max(dp[1].back(), dp[2].back());
}
```

##### [LC714. 买卖股票的最佳时机含手续费](/workspace/714.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA%E5%90%AB%E6%89%8B%E7%BB%AD%E8%B4%B9.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee) - 每笔交易需要付手续费
>
> 分析状态, 别想太复杂
> - 0 - 未持有股票
> - 1 - 持有股票

```CPP
int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int> > dp(2, vector<int>(prices.size()));
    dp[0][0] = 0;
    dp[1][0] = -prices[0]-fee;
    for(int i=1; i<prices.size(); i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]+prices[i]);
        dp[1][i] = max(dp[1][i-1], dp[0][i-1]-prices[i]-fee);
    }
    return dp[0].back();
}
```