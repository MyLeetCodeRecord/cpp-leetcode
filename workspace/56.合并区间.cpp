/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    // 从开始早的开始, 扩散cover范围
    bool static cmp(vector<int> l, vector<int> r){
        // 其实没必要, 默认的sort就是优先按start排序
        if(l[0]==r[0])
            return l[1] < r[1];
        return l[0] < r[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int> > ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        // last one
        ans.push_back({start, end});
        return ans;
    }
};
// @lc code=end

