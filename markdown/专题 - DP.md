### 动态规划

#### 1. 一维DP
##### [LC746. 使用最小花费爬楼梯](/workspace/746.%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF.cpp)
> 题目描述: https://leetcode.cn/problems/min-cost-climbing-stairs
> 
> <img src="https://img-blog.csdnimg.cn/2021010621363669.png">

##### [LC343. 整数拆分](/workspace/343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.cpp)
> 题目描述: https://leetcode.cn/problems/min-cost-climbing-stairs
> 
> `dp[i]`是拆分 i 能得到的最大乘积, **至少切分一次**
> 
> 假设枚举中间分界点 j, j左侧不做拆分(j), 右侧可以拆分(`dp[j]`)
> 
> 每个 j 作为分界点的最大乘积 `max(j*(i-j), j*dp[i-j])` 作为dp[i]的一个候选

##### [LC2266. 统计打字方案数](/markdown/LC6058.%20%E7%BB%9F%E8%AE%A1%E6%89%93%E5%AD%97%E6%96%B9%E6%A1%88%E6%95%B0.md)
> 周赛第三题: https://leetcode.cn/problems/count-number-of-texts
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

##### [LC91. 解码方法](/workspace/91.%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95.cpp)
> 题目描述: https://leetcode.cn/problems/decode-ways
> 
> 第一道坎是选择`dp`还是`backtrack`
> 
> 其实回溯时由于substring长度最多为2, 所以复杂度并不高(误), 另外回溯要向前看...动态规划向后看
> 
> <img src="./../appendix/LC91.png">
> 
> 如果使用`dp`, 区分`单个字符映射字母`和`与前一个字符组合一起映射字母`两种情况即可



#### 2. 矩阵DP / 路径问题
##### [LC62. 不同路径](/workspace/62.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.cpp)
> 题目描述: https://leetcode.cn/problems/decode-ways
> 
> ![LC62](/appendix/LC62.png)

##### [LC63. 不同路径Ⅱ](/workspace/63.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84-ii.cpp)
> 题目描述: https://leetcode.cn/problems/unique-paths-ii
> 
> 注意对第0行和第0列的初始化
> 
> <img src="https://img-blog.csdnimg.cn/20210104114513928.png">

##### [LC64. 最小路径和](/workspace/64.%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.cpp)
> 题目描述: https://leetcode.cn/problems/minimum-path-sum


#### 3. 二维DP

##### [剑指offer91. 粉刷房子](https://leetcode.cn/problems/JEj789/)
```CPP
// 可以直接用costs作为dp数组, 不用其它空间
int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    vector<vector<int> > dp(n, vector<int>(3, 0));
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for(int i=1; i<n; i++){
        dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}
```


#### 4. 状态转移DP

##### [股票问题](/markdown/%E4%B8%93%E9%A2%98%20-%20DP%20-%20%E8%82%A1%E7%A5%A8%E9%97%AE%E9%A2%98.md)

##### [LC376. 摆动序列](/workspace/376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.cpp)
> 题目描述: https://leetcode.cn/problems/wiggle-subsequence
> 
> ![LC376](/appendix/LC376.png)


##### [LC790. 多米诺和托米诺平铺](/workspace/790.%E5%A4%9A%E7%B1%B3%E8%AF%BA%E5%92%8C%E6%89%98%E7%B1%B3%E8%AF%BA%E5%B9%B3%E9%93%BA.cpp)
> 官方题解这个图画的挺好的, 状态要想全, `00`和`11`是两种情况
> 
> ![LC790](/appendix/LC790.png)
> 
> 另外, 对多次加法要进行多层取模
