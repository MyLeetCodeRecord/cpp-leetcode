/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int sum = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    while(left<right-1 && nums[right-1]==nums[right])
                        right--;
                    while(left+1<right && nums[left+1]==nums[left])
                        left++;
                    ans.push_back({nums[i],nums[left++],nums[right--]});
                }
                else if(sum > 0){
                    right--;
                }
                else{
                    left++;
                }
            }
            while(i<nums.size()-2 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};
// @lc code=end

