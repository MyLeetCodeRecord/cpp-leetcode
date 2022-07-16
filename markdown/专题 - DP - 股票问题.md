#### 股票问题

##### [LC121. 买卖股票的最佳时机Ⅰ](/workspace/121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/): 只买卖一次
> 
> 用一个`int变量`或者`dp[i]数组`记录第i天(包括第i天本身)的最低价值, 作为买入时间, 尝试用`price[i]-dp[i]`更新ans


##### [LC122. 买卖股票的最佳时机Ⅱ](/workspace/122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-ii.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii): 同一时间最多持有一只股票, 可以不重叠地重复购买
> 
> 不需要手续费, 不需要最少买卖次数, 只要`prices[i-1] < prices[i]`就应该买入


##### [LC123. 买卖股票的最佳时机Ⅲ](/workspace/123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iii.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/): 只能进行两笔交易
> 
> ![LC123](/appendix/LC123.png)


##### [LC188. 买卖股票的最佳时机Ⅳ](/workspace/188.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iv.cpp)

> [题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)
> 
> 做了上面的[LC123](/workspace/123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA-iii.cpp), 这道题就不难了, 把交易次数从2次改为k次, 也就是引入一个`for(k)`
>
> 踢完球写
