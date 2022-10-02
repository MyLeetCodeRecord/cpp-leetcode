/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
class Solution {
public:
    string reformatNumber(string number) {
        string tmp = "";
        string ans = "";
        int idx = 0;
        for(int i=0; i<number.size(); i++){
            if(number[i]==' ' || number[i]=='-')
                continue;
            tmp += number[i];
        }
        int i = 0;
        while(i < tmp.size()){
            if(tmp.size()-i > 4){
                ans += tmp.substr(i, 3);
                ans += "-";
                i += 3;
            }
            else if(tmp.size()-i == 4){
                ans += tmp.substr(i, 2);
                ans += "-";
                i += 2;
                ans += tmp.substr(i, 2);
                i += 2;
                break;
            }
            else{
                ans += tmp.substr(i, tmp.size()-i);
                i = tmp.size();
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

