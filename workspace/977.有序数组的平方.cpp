/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int idx = n-1;
        int l=0, r=n-1;
        while(idx >= 0){
            if(abs(nums[l]) >= abs(nums[r])){
                ans[idx--] = nums[l]*nums[l];
                l++;
            }
            else{
                ans[idx--] = (nums[r]*nums[r]);
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

