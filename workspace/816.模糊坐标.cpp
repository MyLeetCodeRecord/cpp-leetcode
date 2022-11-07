/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution {
public:
    vector<string> addDot(string s){
        if(s.size() == 1)
            return {s};
        if(s.size()>1 && s[0]=='0' && s.back()=='0')
            return {};
        if(s.size()==1 || s.back()=='0')
            return {s};
        if(s[0]=='0'){
            return {"0."+s.substr(1)};
        }
        vector<string> ans;
        ans.push_back(s);   // 不加小数点
        for(int i=1; i<s.size(); i++){
            string tmp = s.substr(0, i)+"."+s.substr(i);
            ans.push_back(tmp);
        }
        return ans;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.size()-2);
        int n = s.size();
        for(int i=1; i<n; i++){
            string strX = s.substr(0, i);
            string strY = s.substr(i);
            vector<string> X = addDot(strX);
            vector<string> Y = addDot(strY);
            for(string x: X){
                for(string y: Y){
                    ans.push_back("("+x+", "+y+")");
                }
            }
        }
        return ans;
    }
};
// @lc code=end

