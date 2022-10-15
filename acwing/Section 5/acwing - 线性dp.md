#### 线性dp

##### 1. [数组三角形](/acwing/Section%205/2_%E6%95%B0%E5%AD%97%E4%B8%89%E8%A7%92%E5%BD%A2.cpp) / 路径和
> [路径问题](/markdown/%E4%B8%93%E9%A2%98%20-%20DP%20-%20%E8%B7%AF%E5%BE%84%E9%97%AE%E9%A2%98.md)

##### 2. [最长上升子序列](/acwing/Section%205/2_%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97.cpp)
> `子序列`: 不要求连续

##### 3. [最长上升子序列II](/acwing/Section%205/2_%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97II.cpp)
> todo: 优化做法

##### 4. [最长公共子序列]
> `dp[i][j]`: `s1[:i-1]`和`s2[:j-1]`的LCS
> - 如果`text1[i-1] == text2[j-1])` => dp[i][j] = dp[i-1][j-1] + 1;
> 
> - 否则, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`

##### 5. [最短编辑距离](/acwing/Section%205/2_%E6%9C%80%E7%9F%AD%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.cpp)
> - `s[i-1]==t[i-1]` => 不做操作 => `dp[i][j] = dp[i-1][j-1]`
> 
> - `s[i-1]!=t[i-1]` => 修改/添加/删除 => `dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))`

##### 6. [编辑距离](/acwing/Section%205/2_%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.cpp)
> ❗️`TLE`: 
> 
> - 注意`editDistance(s1, s2)`的参数列表记得使用`引用类型&`
> 
> - 用`int[][]`而不是`vector<vector<int>>`
