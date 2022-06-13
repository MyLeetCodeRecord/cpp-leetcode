#### Weekly 2

##### 1. 计算应缴税款总额(10min)
> [题目](https://leetcode.cn/problems/calculate-amount-paid-in-taxes/) - `math`
> 
> 注意**不完整区间**的处理, 即最后一个

```CPP
double calculateTax(vector<vector<int>>& brackets, int income) {
    double ans = 0;
    bool lastOne = false;
    for(int i=0; i<brackets.size(); i++){
        if(brackets[i][0]>=income)
            lastOne = true;
        if(i!=0)
            ans += (min(brackets[i][0], income)-brackets[i-1][0]) * (brackets[i][1]/100.0);
        else
            ans += min(brackets[i][0], income) * (brackets[i][1]/100.0);
        if(lastOne)
            break;
    }
    return ans;
}
```


##### 2. 网格中的最小路径代价 (50min + 3*👿)
> 上来就写, 这道题如果直接`DFS`, 复杂度`O(n^m)`...
> 
> 同样可以用`DFS`去搜, 第二题考`DP`, 第三题暴力回溯... 够离谱

> [题目](https://leetcode.cn/problems/minimum-path-cost-in-a-grid/) - `动态规划`
> 
> > <img src="https://assets.leetcode.com/uploads/2022/04/28/griddrawio-2.png">
> 
> 求最上层节点到最底层节点的路径长度, `DFS`的计算复杂度来源于**多次重复计算子问题**
> 
> 不重复计算子问题 ==> 动态规划
> 
> 最初的想法是dp[m+1][n+1], 但是每层只用到上一层, 但又不能直接覆盖, 影响同层其他节点的计算, 因此用两个一维 dp 数组就够了, 即代码中的tmp_dp记录新一层计算结果, 同层计算完毕后更新至dp
> 
> - dp[i]表示第i个元素到最底层的最短路径长度
>   - 初始化: 最底层(例图中的2,1)
>   - 状态转移: dp[i] = weight[layer][i]+ min{moveCost[grid[layer][i]][j] + dp[j]}, j是layer-1层的所有节点

```CPP
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size();
    int n = grid[0].size();
    // dp[i]: 第i个元素到最底层的最短路径和
    vector<int> dp(n+1, 0);
    vector<int> tmp_dp(n+1, 0);
    
    // 初始化: 最底层置为本身weight
    for(int i=0; i<n; i++){
        dp[i] = grid[m-1][i];
    }
    // 状态转移: dp[layer_i] = self.weight + min_all{dp[layer_i-1]}
    for(int layer=m-2; layer>=0; layer--){
        for(int i=0; i<n; i++){
            int curMin = INT_MAX;
            for(int j=0; j<n; j++){
                curMin = min(curMin, moveCost[grid[layer][i]][j] + dp[j]);  // 距离+dp[layer_i-1]
            }
            tmp_dp[i] = grid[layer][i] + curMin;
        }
        dp = tmp_dp;
    }
    int ans = dp[0];
    for(int i=0; i<n; i++){
        ans = min(ans, dp[i]);
    }
    return ans;
}
```


##### 3. 公平分发饼干
> 周赛过程中没有分析复杂度

> [题目](https://leetcode.cn/problems/fair-distribution-of-cookies/) - `回溯法`
> 
> 为什么可以`DFS` or `backtrack`?
> 
> `cookies`长度和`K`都小于8, 最多构建一棵`8层 + 每个节点度为8`的完全树, 树的规模是`O(8^8)`
> 
> DFS / 回溯:
> - 深度是cookies
> - 宽度是序列长度K

```CPP
int ans = INT_MAX;

void backtrack(vector<int>& cookies, vector<int>& kChild, int k, int cur){
    if(curCookie==cookies.size()){
        int unfair = INT_MIN;
        for(int child: kChild){
            unfair = max(unfair, child);
        }
        ans = min(ans, unfair);
        return ;
    }
    // 当前cookie分给K个小朋友中的任何一个
    int unfair = INT_MAX;
    for(int i=0; i<k; i++){
        kChild[i] += cookies[cur];
        backtrack(cookies, kChild, k, cur+1);
        kChild[i] -= cookies[cur];
    }
}
int distributeCookies(vector<int>& cookies, int k) {
    vector<int> kChild(k, 0);
    backtrack(cookies, kChild, k, 0);
    return ans;
}
```
