/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

// @lc code=start
class Solution {
public:
    // 对时间t进行二分查找
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0;
        long long r = 1e14+10;
        while(l<r){
            long long mid = (l+r)/2;
            long long cnt = 0;
            for(int t: time){
                cnt += mid/t;
            }
            if(cnt < totalTrips)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};
// @lc code=end

