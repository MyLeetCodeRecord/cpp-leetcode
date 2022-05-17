/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    // 第一想法: 获得每个字母出现区间, 然后进行区间合并
    // 题解 => end相当于*区间覆盖问题*中的cover, i==end表示一个划分
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26, 0);
        for(int i=0; i<s.size(); i++){
            lastPos[s[i]-'a'] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        for(int i=0; i<s.length(); i++){
            end = max(end, lastPos[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};
// @lc code=end

