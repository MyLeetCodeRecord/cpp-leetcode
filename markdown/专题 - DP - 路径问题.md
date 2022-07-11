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
> ➡️[直接DP]((/workspace/1289.%E4%B8%8B%E9%99%8D%E8%B7%AF%E5%BE%84%E6%9C%80%E5%B0%8F%E5%92%8C-ii.cpp))
> 
> 与前两题类似, 但这里状态转移来自上一行任意下标不同的dp[i-1][p], 即复杂度`O(n^3)`
> 
> ➡️[空间优化](/workspace/1289.下降路径最小和-ii-improve.cpp)
> 
> ![LC1289](/appendix/LC1289.png)
> 
> 效果对比
> 
> ![LC1289-improve](/appendix/LC1289-2.png)

```CPP
// 空间优化 => 有限变量来代替遍历查找
int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    // 有限变量替代二维dp数组, 需要两个sum, 以及最小值列号
    int first_sum = 0;
    int first_pos = -1;
    int second_sum = 0;
    for(int i=0; i<n; i++){
        int layer_first_sum = INT_MAX;
        int layer_first_pos = -1;
        int layer_second_sum = INT_MAX;
        for(int j=0; j<n; j++){
            // 仅当j==firstPos时使用secondSum
            int curPathSum = ((j!=first_pos) ? first_sum : second_sum) + grid[i][j];
            // 遇到最小 => 更新最小和次小
            if(curPathSum < layer_first_sum){
                layer_second_sum = layer_first_sum;
                layer_first_sum = curPathSum;
                layer_first_pos = j;
            }
            // 遇到次小 => 更新次小
            else if(curPathSum < layer_second_sum){
                layer_second_sum = curPathSum;
            }
        }
        first_sum = layer_first_sum;
        first_pos = layer_first_pos;
        second_sum = layer_second_sum;
    }
    return first_sum;
}
```

![小结](/appendix/路径问题.png)

---


##### [1575. 统计所有可行路径](/workspace/1575.%E7%BB%9F%E8%AE%A1%E6%89%80%E6%9C%89%E5%8F%AF%E8%A1%8C%E8%B7%AF%E5%BE%84.cpp)

> ![LC1575](/appendix/LC1575.png)