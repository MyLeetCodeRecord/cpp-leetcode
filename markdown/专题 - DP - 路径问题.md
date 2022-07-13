#### 路径问题

> [宫水三叶-路径专题](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247485037&idx=1&sn=d6d52c48600e655161e84f25d3402514&chksm=fd9cad72caeb2464e1d8adcd991ec178001472a6c6ddc02a1764bc74ea27a97f71fddbce9975&scene=178&cur_album_id=1773144264147812354#rd)
> 
> [宫水三叶-路径问题总结](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247485580&idx=1&sn=84c99a0a8ab7b543c3678db577309b97&chksm=fd9ca393caeb2a859fafb0cb12683669ed1a0086cb22e1eaaa9ec323e033ab2cf3a77dfc5561&cur_album_id=1773144264147812354&scene=189#wechat_redirect)
>
> 大神竟然也在ms养老, 所以三叶大神alias是什么呢 (bushi

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

下面这几道题注意关注哪些**变化维度**作为dp的维度(比如start, maxMove), 不变的参数(比如终点)不作为dp维度。

##### [LC1575. 统计所有可行路径](/workspace/1575.%E7%BB%9F%E8%AE%A1%E6%89%80%E6%9C%89%E5%8F%AF%E8%A1%8C%E8%B7%AF%E5%BE%84.cpp)

> 题目描述: https://leetcode.cn/problems/count-all-possible-routes
> 
> ![LC1575](/appendix/LC1575.png)
>
> 代码是CV的...

```CPP
int mod = 1000000007;
// 4个params, 只有start, fuel是变化的, 所以用二维dp来表示这两个可变参数
int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int n = locations.size();

    // f[i][j] 代表从位置 i 出发，当前油量为 j 时，到达目的地的路径数
    vector<vector<int> > dp(n, vector<int>(fuel+1, 0));
    
    // 对于本身位置就在目的地的状态，路径数为 1
    for (int i = 0; i <= fuel; i++)
        dp[finish][i] = 1;

    // 从状态转移方程可以发现 f[i][fuel]=f[i][fuel]+f[k][fuel-need]
    // 在计算 f[i][fuel] 的时候依赖于 f[k][fuel-need]
    // 其中 i 和 k 并无严格的大小关系
    // 而 fuel 和 fuel-need 具有严格大小关系：fuel >= fuel-need
    // 因此需要先从小到大枚举油量
    for (int cur = 0; cur <= fuel; cur++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (i != k) {
                    int need = abs(locations[i] - locations[k]);
                    if (cur >= need) {
                        dp[i][cur] += dp[k][cur-need];
                        dp[i][cur] %= mod;
                    }
                }
            }
        }
    }
    return dp[start][fuel];
}
```


##### [LC576. 出界的路径数](/workspace/576.%E5%87%BA%E7%95%8C%E7%9A%84%E8%B7%AF%E5%BE%84%E6%95%B0.cpp)
> 题目描述: https://leetcode.cn/problems/out-of-boundary-paths
> 
> ![LC576](/appendix/LC576.png)

```CPP
// 将(x,y)平铺成一维, 使用getIndex()和parseIndex()转换
int getIndex(int x, int y, int n){
    return x*n + y;
}
vector<int> parseIndex(int index, int n){
    return {index/n, index%n};
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // dp[index][move]: 从index=(x*n+y)出发, 最多move步能够到达边缘的路径数
    vector<vector<int> > dp(m*n, vector<int>(maxMove+1, 0));
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    // 初始化
    // - 注意这里是对所有临界pos的dp值"+1",而不是"=1"
    // - 并且第二维move是"最多move步", 所以每个非0 move值都要初始化
    for(int move=1; move<=maxMove; move++){
        for(int x=0; x<m; x++){
            dp[getIndex(x, 0, n)][move] += 1;
            dp[getIndex(x, n-1, n)][move] += 1;
        }
        for(int y=0; y<n; y++){
            dp[getIndex(0, y, n)][move] += 1;
            dp[getIndex(m-1, y, n)][move] += 1;
        }
    }
    
    // 状态转移
    for(int move=1; move<=maxMove; move++){
        // 状态转移第二维只使用[move-1], 所以idx顺序(或者展开成(x,y))不重要
        for(int idx=0; idx<m*n; idx++){
            int x = parseIndex(idx, n)[0];
            int y = parseIndex(idx, n)[1];
            for(int d=0; d<4; d++){
                int nextX = x+directions[d][0];
                int nextY = y+directions[d][1];
                if(nextX>=0 && nextX<m && nextY>=0 && nextY<n){
                    dp[idx][move] += dp[getIndex(nextX, nextY, n)][move-1];
                    dp[idx][move] %= 1000000007;
                }
            }
        }
    }
    return dp[getIndex(startRow, startColumn, n)][maxMove];
}
```


##### [LC1301. 最大得分的路径数目](/workspace/1301.%E6%9C%80%E5%A4%A7%E5%BE%97%E5%88%86%E7%9A%84%E8%B7%AF%E5%BE%84%E6%95%B0%E7%9B%AE.cpp)
> 题目描述: https://leetcode.cn/problems/number-of-paths-with-max-score/
>
> 有缘再做...