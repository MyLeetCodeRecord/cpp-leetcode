/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        int m = strs.size();
        int n = strs[0].size();
        // 外层是列
        for(int j=0; j<n; j++){
            // 检查一列是否为升序
            for(int i=1; i<m; i++){
                if(strs[i][j] < strs[i-1][j]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

