/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    // 简化成一维问题, 让rightMin[i]成为已有知识
    // 然后移动left, 计算leftMax的同时, 比较对应的rightMin[left+1]即可
    // left的移动方向还可以保证left是最小答案
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        // "left和right都是非空的" => 注意范围
        vector<int> rightMin(n, 0);
        rightMin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightMin[i] = min(rightMin[i+1], nums[i]);
        }
        int maxLeft = nums[0];
        for(int l=0; l<n-1; l++){
            maxLeft = max(maxLeft, nums[l]);
            if(maxLeft <= rightMin[l+1])
                return l+1;
        }
        return 0;
    }
};
// @lc code=end

