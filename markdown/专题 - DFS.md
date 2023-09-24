### DFS

> [回溯法](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%9B%9E%E6%BA%AF%E6%B3%95.md)


#### 0. 其它题目

[LC22. 括号生成](/workspace/22.%E6%8B%AC%E5%8F%B7%E7%94%9F%E6%88%90.cpp): 注意每一次分解`left & right`时要解决一个括号

#### 1. 简单DFS
> 用`n * n`的`graph`矩阵存储边是否存在; `visited`数组可以通过修改矩阵数值被取代; 对所有未访问过的节点进行DFS

**[LC200. 岛屿数量](/workspace/200.%E5%B2%9B%E5%B1%BF%E6%95%B0%E9%87%8F.cpp)**: 求连通块数量, 在DFS外部cnt++

**[LC695. 岛屿的最大面积](/workspace/695.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%A2%E7%A7%AF.cpp)**: 求最大连通块, 在DFS内部cnt++

**[LC547. 省份数量](/workspace/547.%E7%9C%81%E4%BB%BD%E6%95%B0%E9%87%8F.cpp)**: 用`vector<vector<int>>& isConnected`存储是否存在边


##### 2. 从边缘出发
> 其实差不多, 只是这两题都是从边缘出发, 417的DFS判断条件多一点

**[LC130. 被围绕的区域](/markdown/LC130.%20%E8%A2%AB%E5%9B%B4%E7%BB%95%E7%9A%84%E5%8C%BA%E5%9F%9F.md)**

**[LC417. 太平洋大西洋水流问题](/workspace/417.%E5%A4%AA%E5%B9%B3%E6%B4%8B%E5%A4%A7%E8%A5%BF%E6%B4%8B%E6%B0%B4%E6%B5%81%E9%97%AE%E9%A2%98.cpp)**

**[LC1254. 统计封闭岛屿的数目](/workspace/1254.%E7%BB%9F%E8%AE%A1%E5%B0%81%E9%97%AD%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E7%9B%AE.cpp)**


##### 3. [回溯法](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%9B%9E%E6%BA%AF%E6%B3%95.md)

**[LC79. 单词回溯](/markdown/LC79.%20%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2.md)**
> Leetbook: https://leetcode.cn/leetbook/read/dfs/eqpew7/
> 
> ![LC79](/appendix/LC79.png)
>
> - 对于每一个单元格, 在第一个字符匹配的时候, 才执行一次深度优先遍历, 直到找到符合条件的一条路径结束; 如果第一个字符都不匹配, 当然没有必要继续遍历下去
> - 递归终止条件: 匹配到了`word`的最后一个字符
> - 回溯: 在不能匹配的时候, 需要原路返回, 尝试新的路径


**[LC112. 路径总和](/workspace/112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.cpp)**

**[LC113. 路径总和II](/workspace/113.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C-ii.cpp)**

> 这个问题已经建立在一棵存在的二叉树上, 不需要再考虑针对回溯如何建立一棵树的问题, 可以直接看成一个树的DFS问题
> 
> 注意路径可能是非正数, 因此不能用`sum>=targetSum`来剪枝或者作为return条件


##### 4. DFS ➕ 记忆化搜索

**[LC329. 矩阵中的最长递增路径](/workspace/329.%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E8%B7%AF%E5%BE%84.cpp)**

**[LC1387. 将整数按权重排序](/workspace/1387.%E5%B0%86%E6%95%B4%E6%95%B0%E6%8C%89%E6%9D%83%E9%87%8D%E6%8E%92%E5%BA%8F.cpp)**