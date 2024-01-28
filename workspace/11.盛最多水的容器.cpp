/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    // 相向双指针, 移动短板
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i = 0, j = n-1;
        while(i < j){
            int area = min(height[i], height[j]) * (j-i);
            ans = max(ans, area);
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};
// @lc code=end

