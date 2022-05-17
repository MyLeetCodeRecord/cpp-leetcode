/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int cover = 0;
        int localCover = nums[0];
        int step = 0;
        for(int i=0; i<=cover; i++){
            // 可以覆盖
            if(cover >= nums.size()-1)
                break;
            // 维护一个区间maxCover, 到i==cover时更新
            if(i + nums[i] > cover){
                localCover = max(localCover, i + nums[i]);
            }
            if(i==cover && localCover > cover){
                cover = localCover;
                step++;
            }
        }
        return (cover>=nums.size()-1) ? step : -1;
    }
};
// @lc code=end

