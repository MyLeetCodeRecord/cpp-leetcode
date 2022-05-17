/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = nums[0];
        // 只能到cover!
        for(int i=0; i<=cover; i++){
            // 到达最后一个下标
            if(cover >= nums.size()-1)
                return true;
            if(cover < i + nums[i]){
                cover = i + nums[i];
            }
        }
        return false;
    }
};
// @lc code=end

