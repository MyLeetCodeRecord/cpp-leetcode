/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // 建立interval[start]到index的映射
        map<int, int> mp;
        int idx = 0;
        for(auto interval: intervals){
            mp[interval[0]] = idx++;
        }
        vector<int> result;
        for(auto interval: intervals) {
            auto it = mp.lower_bound(interval[1]);  // lower_bound找到第一个key>=interval[end]
            if(it == mp.end())
                result.push_back(-1);
            else
                result.push_back((*it).second);     // 使用map找到对应的idx
        }
        return result;
    }
};
// @lc code=end

