/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    // 想复杂了xd, 这是个固定窗口的问题, ans是原始的sum+因为buff窗口而新增的顾客的最大值
    // 如果不分解问题, 不固定窗口大小, 难度就来到 “维护最左和最右1” 这边
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int ans = 0;
        int sum = 0;
        int left = 0;
        int right = 0;
        for(int i=0; i<customers.size(); i++){
            sum += (grumpy[i]==0) ? customers[i] : 0;
        }
        while(right < customers.size()){
            // 扩大右窗口
            sum += ((grumpy[right]==1) ? customers[right] : 0);
            right++;
            // 收缩左窗口
            if(right-left == k){
                ans = max(ans, sum);
                sum -= ((grumpy[left]==1) ? customers[left] : 0);
                left++;
            }
        }
        return ans;
    }
};
// @lc code=end

