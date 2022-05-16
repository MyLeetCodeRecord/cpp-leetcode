/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    // 先放高的, 直接放在k位置, 如果高度相同先放k小的
    bool static cmp(vector<int> &l, vector<int> &r){
        if(l[0]==r[0])
            return l[1] < r[1];
        return l[0] > r[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans;
        for (vector<int> p: people) {
            ans.insert(ans.begin() + p[1], p);  //  在指定位置loc前插入值为val的元素
        }
        return ans;
    }
};
// @lc code=end
