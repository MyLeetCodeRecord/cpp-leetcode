/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(const int& num : nums){
            st.insert(num);
        }
        int ans = 0;
        for(const int& num : st){
            // 如果当前num可以作为某个序列的最小值, 才会向bigger方向搜索
            if(!st.count(num - 1)){
                int cur = num;
                int len = 1;
                while(st.count(cur + 1)){
                    cur += 1;
                    len += 1;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
// @lc code=end

