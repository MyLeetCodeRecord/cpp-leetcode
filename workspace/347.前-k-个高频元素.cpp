/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(unordered_map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
            pq.push({it->second, it->first});
        }
        vector<int> ans;
        while(k > 0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
// @lc code=end

