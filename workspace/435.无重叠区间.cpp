/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    // 按结束时间排序, 先结束后面才有可能容纳更多区间
    bool static cmp(vector<int>& l, vector<int>& r){    // 加引用, 说多少回加引用
        return l[1] < r[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 0;
        int preEnd = INT_MIN;   // 范围不是从0开始
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] >= preEnd){
                cnt++;
                preEnd = intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};
// @lc code=end

