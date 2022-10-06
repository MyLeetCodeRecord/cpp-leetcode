/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mp;
        for(string line: cpdomains){
            int space = line.find(' ');
            int times = stoi(line.substr(0, space));
            line = line.substr(space+1);    // str.substr(idx): 省略len参数, 表示从idx到末尾
            mp[line] += times;
            // 为当前指令的所有子串计数
            for(int i=0; i<line.size(); i++){
                if(line[i]=='.'){
                    mp[line.substr(i+1)] += times;
                }
            }
        }
        vector<string> ans;
        for(auto it: mp){
            ans.push_back(to_string(it.second)+" "+it.first);
        }
        return ans;
    }
};
// @lc code=end

