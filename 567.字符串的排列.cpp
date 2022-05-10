/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    // 滑动窗口 + map
    // LC3, LC438[同一道题], LC1695
    bool checkInclusion(string s1, string s2) {
        // s1的任意排列 => map统计字符频次
        map<char, int> mp;
        map<char, int> mp_copy;
        for(char ch : s1){
            mp[ch]++;
            mp_copy[ch]++;
        }
        // 滑动窗口 - 甚至是固定大小的窗口
        int matchCnt = 0;       // 协助判断substr和p是否相等, 不然需要用两个map逐个比较?
        int left = 0;
        int right = 0;
        while(right < s2.size()){
            // 跳过无效字符, 比如s1="ab", substr包含'c'
            if(mp.find(s2[right])==mp.end()){
                left = right + 1;
                right = left;
                matchCnt = 0;
                mp = mp_copy;
                continue;
            }
            // 收缩左边界: 可能s2[right]='c', 但s2[left]一直是非'c', 无效收缩, 所以用while
            while(left<right && mp.find(s2[right]) != mp.end() && mp[s2[right]] == 0){
                mp[s2[left++]]++;
                matchCnt--;
            }
            // 扩大右边界
            mp[s2[right++]]--;
            matchCnt++;
            if(matchCnt == s1.size()){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

