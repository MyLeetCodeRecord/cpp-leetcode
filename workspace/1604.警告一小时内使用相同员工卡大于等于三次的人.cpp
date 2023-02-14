/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class Solution {
public:
    int toMinute(string time){
        int ans = 0;
        ans += ((time[0]-'0')*10 + (time[1]-'0')*1) * 60;
        ans += (time[3]-'0')*10 + (time[4]-'0')*1;
        return ans;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        map<string, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[keyName[i]].push_back(toMinute(keyTime[i]));
        }
        vector<string> ans;
        for(auto &[employee, timeList]: mp){
            sort(timeList.begin(), timeList.end());
            for(int i=2; i<timeList.size(); i++){
                if(timeList[i]-timeList[i-2] <= 60){
                    ans.push_back(employee);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

