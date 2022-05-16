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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();  // customers和grumpy是等长的
        int ans = 0;
        // 基础的sum: 没有不生气buff的顾客总数
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += (grumpy[i]==0) ? customers[i] : 0;
        }
        // 加了buff => 固定尺寸的滑动窗口问题
        int left = 0;
        int right = 0;
        while(right < n){
            // 扩大右窗口
            sum += (grumpy[right]==1) ? customers[right] : 0;
            right++;
            // 收缩左窗口
            if(left + minutes < right){
                sum -= (grumpy[left]==1) ? customers[left] : 0;
                left++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

