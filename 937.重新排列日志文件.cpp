/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */

// @lc code=start
class Solution {
public:
    // 对字母日志的排序
    bool static cmp(pair<string, string> l, pair<string, string> r){
        if(l.second==r.second)
            return l.first < r.first;
        return l.second < r.second;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> numLogs;
        vector<pair<string,string> > strLogs;   // 将字母命令分为前后两部分, 方便用第二部分排序
        for(string log: logs){
            string op = log.substr(0, log.find(" "));
            string content = log.substr(log.find(" ")+1, log.size()-log.find(" ")-1);
            if(isdigit(log[log.find(" ")+1])){
                numLogs.push_back(log);
            }
            else{
                strLogs.push_back({op, content});
            }
        }
        sort(strLogs.begin(), strLogs.end(), cmp);
        vector<string> ans;
        for(int i=0; i<strLogs.size(); i++){
            ans.push_back(strLogs[i].first + " "+strLogs[i].second);    // 从pair恢复为string命令
        }
        for(int i=0; i<numLogs.size(); i++){
            ans.push_back(numLogs[i]);
        }
        return ans;
    }
};
// @lc code=end

