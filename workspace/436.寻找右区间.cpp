/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // 建立interval到index的映射
        map<int, int> mp;
        int index = 0;
        for(auto interval: intervals){
            mp[interval[0]] = index++;
        }
        vector<int> result;
        for(auto interval: intervals) {
            auto it = mp.lower_bound(interval[1]);
            if(it == mp.end())
                result.push_back(-1);
            else
                result.push_back((*it).second);     // 使用map找到对应的index
        }
        return result;
    }
};
// @lc code=end

