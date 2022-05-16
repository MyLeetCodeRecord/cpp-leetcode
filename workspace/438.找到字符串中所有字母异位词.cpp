/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        // 异位词  ==>  单词字符串 p 应该存在 map 中
        map<char, int> mp;
        map<char, int> mp_copy;
        for(char ch : p){
            mp[ch]++;
            mp_copy[ch]++;
        }
        // 滑动窗口 - 甚至是固定大小的窗口
        int matchCnt = 0;       // 不然用两个map?
        int left = 0;
        int right = 0;
        while(right < s.size()){
            // 跳过无效字符, 比如p="ab", substr包含'c'
            if(mp.find(s[right])==mp.end()){
                left = right + 1;
                right = left;
                matchCnt = 0;
                mp = mp_copy;
                continue;
            }
            while(left<right && mp.find(s[right]) != mp.end() && mp[s[right]] == 0){
                mp[s[left++]]++;
                matchCnt--;
            }
            mp[s[right++]]--;
            matchCnt++;
            if(matchCnt==p.size()){
                ans.push_back(left);
            }
        }
        return ans;
    }
};
// @lc code=end

