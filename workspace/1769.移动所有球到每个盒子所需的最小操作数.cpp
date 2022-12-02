/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> left(n);
        vector<int> right(n);
        // 时刻记录i-1位置上, 会累积多少个小球, 经过前面的移动(left[i-1]), 每个小球再走一步就可以到 i
        int opCnt = 0;
        for (int i=1; i<n; i++) {
            opCnt += (boxes[i-1] == '1');
            left[i] = left[i-1] + opCnt;
        }
        opCnt = 0;
        for(int i = n - =n-2; i>=0; i--) {
            opCnt += (boxes[i+1] == '1');
            right[i] = right[i+1] + opCnt;
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = left[i] + right[i];
        }
        return ans;
    }
};
// @lc code=end

