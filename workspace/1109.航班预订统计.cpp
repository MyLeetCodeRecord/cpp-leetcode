/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    // 一维差分
    void diff_operation(vector<int>& diff, int l, int r, int c){
        diff[l] += c;
        diff[r+1] -= c;
    }
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 没有错位, 但是对n位置的右边界+1会越界
        vector<int> diff(n+1, 0);
        for(vector<int> book: bookings){
            diff_operation(diff, book[0]-1, book[1]-1, book[2]);
        }
        vector<int> prefixSum(n);
        prefixSum[0] = diff[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = diff[i] + prefixSum[i-1];
        }
        return prefixSum;
    }
};
// @lc code=end

