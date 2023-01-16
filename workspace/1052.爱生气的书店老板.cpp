/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    // 固定尺寸滑动窗口
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size();
        int satisfied = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0)
                satisfied += customers[i];
        }
        // 初始化窗口在[0,k-1]
        for(int i=0; i<k; i++){
            if(grumpy[i] == 1)
                satisfied += customers[i];
        }
        int ans = satisfied;
        // 逐个位置枚举右端点, 每次右端点和左端点都移动一个位置, 维持窗口大小为k
        for(int i=k; i<n; i++){
            if(grumpy[i] == 1)
                satisfied += customers[i];
            if(grumpy[i-k] == 1)
                satisfied -= customers[i-k];
            ans = max(ans, satisfied);
        }
        return ans;
    }
};
// @lc code=end

