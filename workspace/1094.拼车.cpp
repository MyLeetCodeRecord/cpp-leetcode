/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        int maxReach = 0;
        for(vector<int> &trip: trips){
            int c = trip[0], l = trip[1], r = trip[2];
            diff[l] += c;
            diff[r] -= c;
            maxReach = max(maxReach, r);
        }
        int preSum = 0;
        for(int i=0; i<=maxReach; i++){
            preSum += diff[i];
            printf("%d ", preSum);
            if(preSum > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end

