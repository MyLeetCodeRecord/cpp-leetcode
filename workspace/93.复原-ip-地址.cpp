/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    string path;
    int done = 0;
    void backtrack(string s, int cur){
        if(done>=4 || cur==s.size()){
            if(done==4 && cur==s.size()){
                ans.push_back(path.substr(0, path.size()-1));
            }
            return ;
        }
        for(int i=cur; i<s.size() && i<cur+3; i++){ // 简单剪枝: 不检查长度大于3的子串
            string sub = s.substr(cur, i-cur+1);
            if(isLegal(sub)){
                string tmp = path;
                path += (sub+".");
                done++;
                backtrack(s, i+1);
                path = tmp;
                done--;
            }
        }
    }
    bool isLegal(string s){
        if(s.size()==0 || s.size()>3)
            return false;
        // 首 0 情况处理
        if(s.size()>1 && s[0]=='0')
            return false;
        if(stoi(s)>=0 && stoi(s)<=255)
            return true;
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return ans;
    }
};
// @lc code=end

