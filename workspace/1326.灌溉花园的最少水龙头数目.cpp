/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

// @lc code=start
class Solution {
public:
    // 抄的题解
    int minTaps(int n, vector<int>& ranges) {
        // 在所有能够覆盖这块土地 i 的所有水龙头中, 找到能够覆盖最远（右边）位置的水龙头, 记录它最右覆盖的土地
        vector<int> land(n);
        for (int i = 0; i < ranges.size(); i++) {
            int l = max(i - ranges[i], 0);
            int r = min(i + ranges[i], n);
            for (int j = l; j < r; j++) {
                land[j] = max(land[j], r);
            }
        }

        int cnt = 0;
        int cur = 0;
        // 每次传递给cover最远的位置
        while (cur < n){
            if (land[cur] == 0)
                return -1;
            // 传递
            cur = land[cur];
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

