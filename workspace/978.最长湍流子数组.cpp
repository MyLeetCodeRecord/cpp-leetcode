/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int ans = 1;
        int up = 1;
        int down = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                up = down + 1;
                down = 1;
            }
            else if(nums[i]<nums[i-1]){
                down = up + 1;
                up = 1;
            }
            else if(nums[i] == nums[i-1]){
                up = 1;
                down = 1;
            }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};
// @lc code=end

