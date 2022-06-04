/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string email: emails){
            string cur = "";
            bool add = false;
            for(int i=0; i<email.size(); i++){
                if(email[i] == '@'){
                    cur += email.substr(i, email.size()-i);
                    break;
                }
                if(email[i] == '+')
                    add = true;
                if(add == true)
                    continue;
                if(email[i] == '.')
                    continue;
                cur += email[i];
            }
            st.insert(cur);
        }
        return st.size();
    }
};
// @lc code=end

