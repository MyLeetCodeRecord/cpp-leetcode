/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2){
        int k = s1.size();
        int n = s2.size();
        // 用vector代替map, 方便直接比较
        vector<int> mp1;
        vector<int> mp2;
        for(int i=0; i<k; i++){
            mp1[s1[i] - 'a']++;
            mp2[s2[i]-'a']++;
        }
        // 检查s2窗口是否和s1是异位词
        if(mp1 == mp2)
            return true;
        for(int i=k; i<n; i++){
            mp2[s1[i-k]-'a']--;
            mp2[s2[i]-'a']++;
            if(mp1 == mp2)
                return true;
        }
        return false;
    }
};
// @lc code=end

