/*
 * @lc app=leetcode.cn id=1781 lang=cpp
 *
 * [1781] 所有子字符串美丽值之和
 */

// @lc code=start
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int l=0; l<s.size(); l++){
            // 每个起点都要重新创建一个map, 没办法重复用
            // int数组模拟map
            int mp[26] = {0};
            for(int r=l; r<s.size(); r++){
                mp[s[r]-'a']++;
                int _min = 510;
                int _max = 0;
                for(int i=0; i<26; i++){
                    if(mp[i] > 0){
                        _min = min(_min, mp[i]);
                        _max = max(_max, mp[i]);
                    }
                }
                ans += (_max-_min);
            }
        }
        return ans;
    }
};
// @lc code=end

