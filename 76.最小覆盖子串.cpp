/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
private:
    map<char, int> t_mp;    // 如果不作为去全局变量, 放在check的参数列表中会出现超时
    map<char, int> s_mp;
public:
    bool check(){
        for(map<char, int>::iterator it=t_mp.begin(); it!=t_mp.end(); it++){
            if(s_mp.find(it->first)==s_mp.end() || s_mp[it->first] < it->second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        string ans = s;
        bool exist = false;
        for(int i=0; i<t.size(); i++){
            t_mp[t[i]]++;
        }
        int left = 0;
        for(int right=0; right<s.size(); right++){
            s_mp[s[right]]++;
            while(check()==true){
                exist = true;
                string sub = s.substr(left, right-left+1);
                if(sub.size() <= ans.size()){
                    ans = sub;
                }
                s_mp[s[left++]]--;
            }
        }
        return exist==true ? ans : "";
    }
};
// @lc code=end

