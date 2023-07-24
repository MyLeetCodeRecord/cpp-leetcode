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
        // 维护大小为k的小顶堆, 排序依据为「出现次数」
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(auto &[key, val]: mp){
            pq.push({val, key});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

