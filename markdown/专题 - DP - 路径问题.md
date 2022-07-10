#### 路径问题

> [宫水三叶-路径专题](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247485037&idx=1&sn=d6d52c48600e655161e84f25d3402514&chksm=fd9cad72caeb2464e1d8adcd991ec178001472a6c6ddc02a1764bc74ea27a97f71fddbce9975&scene=178&cur_album_id=1773144264147812354#rd)

![路径问题](/appendix/LC62.png)


##### [LC62. 不同路径](/workspace/62.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.cpp)
> 题目描述: https://leetcode.cn/problems/unique-paths
> 初始化`row 0`和`col 0`, 然后进行状态转移


##### [LC63. 不同路径Ⅱ](/workspace/63.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84-ii.cpp)
> 题目描述: https://leetcode.cn/problems/unique-paths-ii
> 
> 注意对第0行和第0列的初始化

---


##### [LC64. 最小路径和](/workspace/64.%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.cpp)
> 题目描述: https://leetcode.cn/problems/minimum-path-sum
> 
> ➡️ 求最小路径
> 
> ![LC64](/appendix/LC64.png)


##### [LC120. 三角形最小路径和](/workspace/120.%E4%B8%89%E8%A7%92%E5%BD%A2%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.cpp)
> 题目描述:https://leetcode.cn/problems/triangle/
> 
> ➡️ 二维dp实现
> 
> ![LC120-1](/appendix/LC120-1.png)
> 
> ➡️ 空间优化
> 
> ![LC120-2](/appendix/LC120-2.png)


##### [LC931. 下降路径最小和](/workspace/931.%E4%B8%8B%E9%99%8D%E8%B7%AF%E5%BE%84%E6%9C%80%E5%B0%8F%E5%92%8C.cpp)
> 题目描述: https://leetcode.cn/problems/minimum-falling-path-sum/
> 
> 与[LC120. 三角形最小路径和](/workspace/120.%E4%B8%89%E8%A7%92%E5%BD%A2%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C.cpp)类似, 不同点在于形状为矩阵, 且状态转移时有三个候选


##### [1289. 下降路径最小和Ⅱ](/workspace/1289.%E4%B8%8B%E9%99%8D%E8%B7%AF%E5%BE%84%E6%9C%80%E5%B0%8F%E5%92%8C-ii.cpp)
> 题目描述: https://leetcode.cn/problems/minimum-falling-path-sum-ii/
> 
> ➡️直接DP
> 
> 与前两题类似, 但这里状态转移来自上一行任意下标不同的dp[i-1][p], 即复杂度`O(n^3)`
> 
> ➡️空间优化
> 
> ![LC1289](/appendix/LC1289.png)
> 
> 下次再写吧...累了

---

