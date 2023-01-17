/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
// 维护窗口时使用一个变量cnt记录已经满足条件的mp_t中的key, 作为子串包含t的判断条件
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp_t;  // 静态
        unordered_map<char, int> mp_s;  // 动态维护
        for(char ch: t){
            mp_t[ch]++;
        }
        bool exist = false;
        string ans = s;
        int cnt = 0;
        int left = 0;
        for(int right=0; right<s.size(); right++){
            mp_s[s[right]]++;
            // 如果t中的字符s[right]已经够了, 记录cnt
            if(mp_t.find(s[right])!=mp_t.end() && mp_s[s[right]] == mp_t[s[right]])
                cnt++;
            // left收缩的条件: 1. 其它字符  2. 个数超额的字符
            // 这里必须判断left范围, e.g. s="a" t="b"
            // 代码里没有cnt--, 因为一旦某个字符个数够了, 那left就不会左移使这个条件被破坏
            while(left<right && mp_t.find(s[left])==mp_t.end() || mp_s[s[left]] > mp_t[s[left]]){
                mp_s[s[left++]]--;
            }
            if(cnt == mp_t.size()){
                exist = true;
                if(right-left+1 <= ans.size()){
                    ans = s.substr(left, right-left+1);
                }
            }
        }
        return exist ? ans : "";
    }
};
/* 对比两个map
class Solution {
private:
    map<char, int> t_mp;    // 如果不作为全局变量, 放在check的参数列表中会出现超时
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
*/
// @lc code=end

