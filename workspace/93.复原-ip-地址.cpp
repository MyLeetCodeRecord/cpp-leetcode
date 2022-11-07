/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    bool isLegal(string sub){
        if(sub.size()>1 && sub[0]=='0')   // 不能有前导零
            return false;
        if(stoi(sub)>255)
            return false;
        return true;
    }
    vector<string> ans;
    vector<string> path;
    void backtrack(string s, int cur){
        if(path.size()==4 || cur==s.size()){
            if(path.size()==4 && cur==s.size()){
                ans.push_back(path[0]+"."+path[1]+"."+path[2]+"."+path[3]);
            }
            return ;
        }
        for(int i=cur; i<s.size() && i<cur+3; i++){
            string sub = s.substr(cur, i-cur+1);
            if(isLegal(sub) && path.size()<4){
                path.push_back(sub);
                backtrack(s, i+1);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return ans;
    }
};
// @lc code=end

