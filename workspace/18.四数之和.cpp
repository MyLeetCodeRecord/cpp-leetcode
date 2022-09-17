/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int n = nums.size();
        for(int i=0; i+3<n; i++){
            for(int j=i+1; j+2<n; j++){
                long long sum_ij = nums[i] + nums[j];
                int left = j+1;
                int right = n-1;
                while(left<right){
                    long long sum_lr = nums[left] + nums[right];
                    if(sum_lr == target-sum_ij){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left<right && nums[left]==nums[left+1])
                            left++;
                        while(left<right && nums[right]==nums[right-1])
                            right--;
                        left++;
                        right--;
                    }
                    else if(sum_lr > target-sum_ij){
                        while(left<right && nums[right]==nums[right-1])
                            right--;
                        right--;
                    }
                    else{
                        while(left<right && nums[left]==nums[left+1])
                            left++;
                        left++;
                    }
                }
                while(j+2<n && nums[j]==nums[j+1])
                    j++;
            }
            while (i+1<n && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};
// @lc code=end

