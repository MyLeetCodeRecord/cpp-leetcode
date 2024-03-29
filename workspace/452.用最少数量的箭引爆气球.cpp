/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    // 按右边界排序
    bool static cmp(vector<int> &l, vector<int> &r){
        return l[1] < r[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ed = INT_MIN;
        int cnt = 0;
        for(int i=0; i<points.size(); i++){
            if(points[i][0] > ed){
                ed = points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

