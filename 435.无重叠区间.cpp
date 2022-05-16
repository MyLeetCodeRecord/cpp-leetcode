/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    bool static cmp(vector<int>& l, vector<int>& r){
        return l[1]<r[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int end = INT_MIN;
        int cnt = 0;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] >= end){
                cnt++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};
// @lc code=end

