/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    // 归纳法, 除了首位0->1, 其它项镜像
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int nextBit = 1;
        for(int i=1; i<=n; i++){
            int sz = ans.size();
            for(int j=sz-1; j>=0; j--){
                ans.push_back(nextBit + ans[j]);
            }
            nextBit *= 2;
        }
        return ans;
    }
};

// @lc code=end

