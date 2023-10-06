/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 将nums[i]放到对应的i-1位置上(不符合的跳过)
        for(int i=0; i<n; i++){
            if(nums[i]>=1 && nums[i]<=n){
                if(nums[i]!=nums[nums[i]-1]){
                    swap(nums[i], nums[nums[i]-1]);
                    i--;    // 交换后, i应该原地踏步
                }
            }
        }
        // 遍历整理过的nums[i], nums[i]!=i+1的就是缺失的第一个正数
        for(int i=0; i<n; i++){
            cout<<nums[i]<<" ";
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};
// @lc code=end

