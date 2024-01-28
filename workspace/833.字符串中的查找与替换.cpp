/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        int k = indices.size();
        vector<int> ops(n, -1);
        // 遍历k个操作, 先标记n个位置哪些需要替换, 不需要的记为-1
        for(int i=0; i<k; i++){
            if(s.compare(indices[i], sources[i].size(), sources[i]) == 0){
                ops[indices[i]] = i;
            }
        }
        // 遍历n个位置, -1直接加上, 有值加target并且移动指针
        string ans = "";
        for(int i=0; i<n; ){
            if(ops[i]==-1){
                ans += s[i++];
            }
            else{
                ans += targets[ops[i]];
                i += sources[ops[i]].size();
            }
        }
        return ans;
    }
};
// @lc code=end

