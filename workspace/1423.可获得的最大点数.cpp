/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    // 每次从头尾拿一张卡片 => 取一个长度为`n-k`的子数组, 子数组的点数之和最小
    // 固定尺寸滑动窗口
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int _k = n - k;
        for(int i=0; i<_k; i++){
            sum += cardPoints[i];
        }
        int ans = sum;
        int all = sum;
        for(int i=_k; i<n; i++){
            sum += cardPoints[i];
            sum -= cardPoints[i - _k];
            ans = min(ans, sum);
            all += cardPoints[i];
        }
        return all - ans;
    }
};
// @lc code=end

