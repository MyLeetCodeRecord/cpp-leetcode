/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    // [numPassengers, from, to] => (一维)差分中的[c, l, r]
    void diff_operation(vector<int>& diff, int l, int r, int c){
        diff[l] += c;
        diff[r+1] -= c;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int N = 1010;
        vector<int> a(N, 0);        // preSum[], 可以简化成两个cumSum
        vector<int> diff(N, 0);     // 计算差分(Index 从 0 开始)

        for(vector<int> trip: trips)
            diff_operation(diff, trip[1], trip[2]-1, trip[0]);

        if(diff[0]>capacity)        // 对0位置特判
            return false;
        a[0] = diff[0];

        for(int i=1; i<1010; i++){  // 求前缀和, 这里可以通过记录最远距离(出现过的最大trip[2])来减少遍历距离
            a[i] = diff[i] + a[i-1];
            if(a[i] > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end

