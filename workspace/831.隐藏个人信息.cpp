/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */

// @lc code=start
class Solution {
public:
    string phone_prefix[4] = {"", "+*-", "+**-", "+***-"};

    string maskPII(string s) {
        int at = s.find("@");
        if(at != string::npos){
            string ans = s.substr(0,1) + "*****" + s.substr(at-1, 1) + s.substr(at);
            for(int i=0; i<ans.size(); i++)
                ans[i] = tolower(ans[i]);
            return ans;
        }
        else{
            string phone = "";
            for(char ch: s){
                if(isdigit(ch))
                    phone += ch;
            }
            return phone_prefix[phone.size()-10] + "***-***-" + phone.substr(phone.size()-4);
        }
    }
};
// @lc code=end

