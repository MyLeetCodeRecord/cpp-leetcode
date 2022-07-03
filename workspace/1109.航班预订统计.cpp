/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 计算差分
        vector<int> diff(n, 0);
        for(vector<int> book: bookings){
            diff[book[0]-1] += book[2];
            if(book[1] < n)
                diff[(book[1]-1)+1] -= book[2];
        }
        // 如果不创建额外空间prefixSum可以直接覆盖在diff上
        vector<int> prefixSum(n, 0);
        prefixSum[0] = diff[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1]+diff[i];
        }
        return prefixSum;
    }
};
// @lc code=end

