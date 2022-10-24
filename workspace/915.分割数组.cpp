/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    // 简化成一维问题, 让right的后缀和成为已有知识
    // 然后移动left, 记录leftMax, 找对应的rightMin[left+1]比较即可
    // left的移动方向还可以保证left是最小答案
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMin(n, 0);
        rightMin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rightMin[i] = min(rightMin[i+1], nums[i]);
        }
        // "left和right都是非空的"
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

