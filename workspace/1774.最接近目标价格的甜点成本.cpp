/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
class Solution {
public:
    // 0-1背包的话, 可以比 C 稍多一点, 好像不太方便
    
    // DFS
    int res = -1;
    void DFS(vector<int>&tops, int i, int sum, int target){
        if (i == tops.size()) {
            if (res == -1 || abs(sum - target) < abs(res - target) || (abs(sum - target) == abs(res - target) && sum < res)) {
                res = sum; 
            }  
            return;
        } 
        DFS(tops, i+1, sum, target);
        DFS(tops, i+1, sum+tops[i], target);
        DFS(tops, i+1, sum+tops[i]*2, target);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for(int base: baseCosts){
            DFS(toppingCosts, 0, base, target);
        }
        return res;
    }
};
// @lc code=end

