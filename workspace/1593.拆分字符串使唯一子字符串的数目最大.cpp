/*
 * @lc app=leetcode.cn id=1593 lang=cpp
 *
 * [1593] 拆分字符串使唯一子字符串的数目最大
 */

// @lc code=start
class Solution {
public:
    // s.length<=16  ==>  暴力回溯
    int ans = 0;
    unordered_map<string, int> mp;
    void backtrack(string s, int cur, int cnt){
        if(cur == s.size()){
            ans = max(ans, cnt);
            return ;
        }
        for(int i=cur; i<s.size(); i++){
            string sub = s.substr(cur, i-cur+1);
            if(mp.find(sub)==mp.end() || mp[sub]==false){
                mp[sub] = true;
                backtrack(s, i+1, cnt+1);
                mp[sub] = false;
            }
        }
    }
    int maxUniqueSplit(string s) {
        backtrack(s, 0, 0);
        return ans;
    }
};
// @lc code=end

