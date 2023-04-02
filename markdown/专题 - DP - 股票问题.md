#### 股票问题 - `状态机dp`

|   |   |   |
|:-:|:-:|:-:|
|`买卖一次`|[121. 买卖股票的最佳时机I]()|   |
|`无限次`|[122. 买卖股票的最佳时机II]()|[1911. 最大子序列交替和]()|   |
|`无限次` / `有冷冻期`|[309. 买卖股票的最佳时机含冷冻期]()|   |   |
|`无限次` / `有手续费`|[714. 买卖股票的最佳时机含手续费]()|
|`最多K次`|[188. 买卖股票的最佳时机IV]()|[123. 买卖股票的最佳时机III]()|

##### [LC121. 买卖股票的最佳时机I](/workspace/121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA.cpp): `只买卖一次`
> 题目: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
> 
> 用一个`int变量`或者`minLeft[i]`数组记录第i天前(包括第i天本身)的最低价值, 作为买入时间, 尝试用`price[i]-dp[i]`更新ans

```CPP
int maxProfit(vector<int>& prices) {
    int ans = 0;
    int minLeft = INT_MAX;
    for(int i=0; i<prices.size(); i++){
        minLeft = min(minLeft, prices[i]);
        ans = max(ans, prices[i] - minLeft);
    }
    return ans;
}
```

<br/>

##### [LC122. 买卖股票的最佳时机II](/workspace/122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-ii.cpp): `无冷冻期` `无限次`

###### **简单做法**
> 题目: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii
> 
> 不需要手续费, 不需要最少买卖次数, 因此只要满足`prices[i-1] < prices[i]`就应该执行买入

```CPP
int maxProfit(vector<int>& prices) {
    int ans = 0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i-1] < prices[i])
            ans += (prices[i]-prices[i-1]);
    }
    return ans;
}
```

###### [灵神](https://www.bilibili.com/video/BV1ho4y1W7QK/)的`状态机dp`做法
> ![LC122](/appendix/LC122.png)
> 
> ⚠️ 需要注意`dp[0][1]`的初始化
>
> ![LC122-2](/appendix/LC122-2.png)

```CPP
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n <= 1)
        return 0;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
    }
    return dp[n-1][0];
}
```


<br/>

##### [LC309. 买卖股票的最佳时机含冷冻期](/workspace/309.%E6%9C%80%E4%BD%B3%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E6%97%B6%E6%9C%BA%E5%90%AB%E5%86%B7%E5%86%BB%E6%9C%9F.cpp): `冷冻期(1天)` `无限次`

###### 做法一: 状态转移时跳过冷冻期
> 题目: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown
>
> ![LC309](/appendix/LC309.png)

```CPP
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // 涉及 i-2 , 所以dp数组错开一位比较方便
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[1][0] = 0;
    dp[1][1] = -prices[0];
    for(int i=2; i<=prices.size(); i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
        dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i-1]);
    }
    return dp[n][0];
}
```

###### 做法二: 加一个冷冻状态
> (这一做法的问题在于, 如果冷冻期很长, 要加的状态节点就会很多)
> - 0 - 持有股票 -> 「由状态0保持」or 「由状态2转化」
> - 1 - 刚卖出股票 -> 只能「由状态0转化」
> - 2 - 卖出股票一天以上 -> 「由状态1保持」 or 「由状态1转化」

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

<br/>

##### [LC714. 买卖股票的最佳时机含手续费](/workspace/714.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA%E5%90%AB%E6%89%8B%E7%BB%AD%E8%B4%B9.cpp): `无限次` `有手续费`

> 题目: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
>
> 在[LC122. 买卖股票的最佳时机II]()的基础上, 买股票时扣除手续费, 并且不退回

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

<br/>

##### [LC188. 买卖股票的最佳时机IV](/workspace/188.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iv.cpp): `限制K次` `无冷冻期`

> 题目: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
>
> ![LC188](/appendix/LC188.png)

```CPP
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
    for(int j=0; j<=k; j++){
        dp[0][j][1] = -k*1000;  // n=0时状态1为不可能状态
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i-1]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i-1]);
        }
    }
    return dp[n][k][0];
}
```

<br/>

##### [LC123. 买卖股票的最佳时机III](/workspace/123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iii.cpp): `次数限制`

> 题目: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
>
> 灵神做法 ➡️ 同[LC188](), 将`k`固定为2的情况

> 另一种状态设置方法⬇️
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

<br/>

