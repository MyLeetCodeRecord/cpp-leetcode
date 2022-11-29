/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    // 分界点相当于*区间覆盖问题*中的cover, i==cover表示一个划分
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> lastPos(26, INT_MAX);
        for(int i=0; i<s.size(); i++){
            lastPos[s[i]-'a'] = i;
        }
        int cover = 0;
        int last = -1;
        // cover是至少要达到的距离, 每次i==cover后可以截断一次, cover要根据下一个子串重置
        for(int i=0; i<=cover; i++){
            // 根据lastPos扩大cover
            cover = max(cover, lastPos[s[i]-'a']);
            if(i==cover){
                ans.push_back(i-last);
                last = i;
                // 如果没到末尾, 需要重置cover, 继续遍历下个子串, 或者外层循环直接用s.size()也可以
                if(i!=s.size()-1)
                    cover = lastPos[s[i+1]-'a'];
            }
        }
        return ans;
    }
};
// @lc code=end

