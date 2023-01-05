/*
 * @lc app=leetcode.cn id=1387 lang=cpp
 *
 * [1387] 将整数按权重排序
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
    // 注意: 题目中的3*x+1有点迷惑性, 绝不代表计算范围是3*hi这么小...因此要开map或者超大数组
    unordered_map<int, int> dp;
public:
    int DFS(int x){
        if(dp.find(x) != dp.end())
            return dp[x];
        if(x%2==1)
            dp[x] = DFS(3*x+1) + 1;
        else
            dp[x] = DFS(x/2) + 1;
        return dp[x];
    }
    int getKth(int lo, int hi, int k) {
        dp[1] = 0;
        vector<PII> ans;
        for(int x=lo; x<=hi; x++){
            DFS(x);
            ans.push_back({dp[x], x});
        }
        sort(ans.begin(), ans.end());
        return ans[k-1].second;
    }
};
// @lc code=end

