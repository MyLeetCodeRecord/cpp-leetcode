#### DFS

##### 1. 简单DFS
> 用n * n的矩阵存储边是否存在; visit数组可以通过修改矩阵数值被取代; 对所有未访问过的节点进行DFS

[LC200. 岛屿数量](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/workspace/200.%E5%B2%9B%E5%B1%BF%E6%95%B0%E9%87%8F.cpp) : 求连通块数量, 在DFS外部cnt++

[LC695. 岛屿的最大面积](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/workspace/695.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%A2%E7%A7%AF.cpp) : 求最大连通块, 在DFS内部cnt++

[LC547. 省份数量](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/workspace/547.%E7%9C%81%E4%BB%BD%E6%95%B0%E9%87%8F.cpp) : 用`vector<vector<int>>& isConnected`存储是否存在边

##### 2. 从边缘出发
> 其实差不多, 只是这两题都是从边缘出发, 417的DFS判断条件多一点

[LC130. 被围绕的区域](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC130.%20%E8%A2%AB%E5%9B%B4%E7%BB%95%E7%9A%84%E5%8C%BA%E5%9F%9F.md)

[LC417. 太平洋大西洋水流问题](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC417.%20%E5%A4%AA%E5%B9%B3%E6%B4%8B%E5%A4%A7%E8%A5%BF%E6%B4%8B%E6%B0%B4%E6%B5%81%E9%97%AE%E9%A2%98.md)


##### 3. 回溯
> 代码随想录上的不列举了, 再做的时候再说

[LC79. 单词回溯](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC79.%20%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2.md)


[LC112. 路径总和](../workspace/112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.cpp)

[LC113. 路径总和Ⅱ](../workspace/113.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C-ii.cpp)

> 这个问题已经建立在一棵存在的二叉树上, 不需要再考虑针对回溯如何建立一棵树的问题, 可以直接看成一个树的DFS问题
> 
> 注意路径可能是非正数, 因此不能用`sum>=targetSum`来剪枝或者作为return条件
