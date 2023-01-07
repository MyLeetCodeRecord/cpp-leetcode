/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举最左侧一个元素
        for(int i=0; i+2<nums.size(); i++){
            // 相向双指针
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];   // 减少重复计算
                if(sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left]==nums[left+1])   // 去重
                        left++;
                    while(left<right && nums[right]==nums[right-1]) // 去重
                        right--;
                    left++;
                    right--;
                }
                else if(sum > 0){
                    while(left<right && nums[right]==nums[right-1]) // 去重
                        right--;
                    right--;
                }
                else{
                    while(left<right && nums[left]==nums[left+1])   // 去重
                        left++;
                    left++;
                }
            }
            // 对i也要去重
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};
// @lc code=end

