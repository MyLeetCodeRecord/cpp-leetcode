### 动态规划

##### 1. 简单DP
##### [LC746. 使用最小花费爬楼梯](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/746.%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF.cpp)
<img src="https://img-blog.csdnimg.cn/2021010621363669.png">


##### [LC63. 不同路径Ⅱ](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/63.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84-ii.cpp)
> 注意对第0行和第0列的初始化
> <img src="https://img-blog.csdnimg.cn/20210104114513928.png">


##### [LC343. 整数拆分](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.cpp)
> dp[i]是拆分 i 能得到的最大乘积
> 假设枚举中间分界点 j, j左侧不做拆分(j), 右侧可以拆分(dp[j])
> 每个 j 作为分界点的最大乘积 max(j*(i-j), j*dp[i-j]) 作为dp[i]的一个候选

##### [LC6058. 统计打字方案数]()
> 周赛第三题
>
> 为`{7,9}`和`others`设计两个递推公式
> 
> 以`{7, 9}`为例, 状态转移方程就是`dp[i] = dp[i-1] + dp[i-2] + dp[i-3]`
> 
> 相当于固定了最后一段的长度(分别是`x = 1,2,3`), 要求其不可分割, 前面`i-x`用`dp[i-x]`表示
> 
> [7 ... 7  7  7] **7**
>  
> [7 ... 7  7] **7  7**
> 
> [7 ... 7] **7  7  7**