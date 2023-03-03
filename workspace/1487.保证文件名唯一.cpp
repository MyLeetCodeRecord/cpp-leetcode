/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
            int n = names.size();
            vector<string> ans;
            unordered_map<string,int> mp;

            for(auto &s: names){
                if(!mp.count(s)){
                    mp[s]++;
                    ans.push_back(s);
                }
                else{
                    string t = s;
                    while(mp.count(t)){
                        t = s+ '(' + to_string(mp[s]) + ')';    // 注意这里面是继续加, 而不是从s+"(1)"开始
                        mp[s]++;
                    }
                    ans.push_back(t);
                    mp[t]++;
                }
            }
            return ans;
    }
};

// @lc code=end

