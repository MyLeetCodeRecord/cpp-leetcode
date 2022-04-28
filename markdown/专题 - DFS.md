#### DFS

<<<<<<< HEAD
##### 1. 简单DFS
> 用n * n的矩阵存储边是否存在; visit数组可以通过修改矩阵数值被取代; 对所有未访问过的节点进行DFS

[LC200. 岛屿数量](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/200.%E5%B2%9B%E5%B1%BF%E6%95%B0%E9%87%8F.cpp) : 求连通块数量, 在DFS外部cnt++

[LC695. 岛屿的最大面积](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/695.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%A2%E7%A7%AF.cpp) : 求最大连通块, 在DFS内部cnt++

[LC547. 省份数量](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/547.%E7%9C%81%E4%BB%BD%E6%95%B0%E9%87%8F.cpp) : 用`vector<vector<int>>& isConnected`存储是否存在边

##### 2. 从边缘出发
> 其实差不多, 只是这两题都是从边缘出发, 417的DFS判断条件多一点

[LC130. 被围绕的区域](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC130.%20%E8%A2%AB%E5%9B%B4%E7%BB%95%E7%9A%84%E5%8C%BA%E5%9F%9F.md)

[LC417. 太平洋大西洋水流问题](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC417.%20%E5%A4%AA%E5%B9%B3%E6%B4%8B%E5%A4%A7%E8%A5%BF%E6%B4%8B%E6%B0%B4%E6%B5%81%E9%97%AE%E9%A2%98.md)
=======
##### [LC200. 岛屿数量]()
> 统计连通块数目, 在DFS外部进行cnt++

##### [LC695. 岛屿的最大面积]()
> 计算最大连通面积, 在DFS内部进行cnt++

##### [LC547. 省份数量]()
> 这道题用矩阵存储<i, j>边是否存在

##### [LC130. 被围绕的区域]()
> 从边缘出发, 如果连续 O 则标记为 A 

##### [LC417. 太平洋大西洋水流问题]()
> 从边缘开始DFS, 逆序解决问题
>>>>>>> 83476ca2c08920d344141cd7166cd09df968f415
