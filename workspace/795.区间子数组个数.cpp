/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int not_legal = -1;
        int last_legal = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=right && nums[i]>=left){
                last_legal = i;
            }
            if(nums[i]>right){
                not_legal = i;  // 上一个不能包含的点
                last_legal = -1;
            }
            if(last_legal != -1)
                ans += (last_legal - not_legal);  // 起点的选择一定在(not_legal, last_legal]之间
        }
        return ans;
    }
};
// @lc code=end

