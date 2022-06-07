/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

// @lc code=start
class Solution {
public:
    // 对时间 t 进行二分查找, 找到满足条件的最小 t
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long left = 0;
        long long right = 1e14;
        while(left <= right){
            long long mid = (right-left)/2 + left;
            // 找最左侧target, 就要在"=="的情况下收缩右边界
            long long cnt = 0;
            for(int t: time)
                cnt += mid/t;
            if(cnt >= totalTrips){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

