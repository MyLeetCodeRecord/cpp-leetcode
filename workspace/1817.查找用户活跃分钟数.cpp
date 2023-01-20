/*
 * @lc app=leetcode.cn id=1817 lang=cpp
 *
 * [1817] 查找用户活跃分钟数
 */

// @lc code=start
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for(vector<int> & log: logs){
            int id = log[0];
            int minute = log[1];
            mp[id].insert(minute);
        }
        vector<int> ans(k, 0);
        for(auto& [id, st]: mp){
            int minute = st.size();
            if(minute > k)
                break;
            ans[minute-1]++;
        }
        return ans;
    }
};
// @lc code=end

