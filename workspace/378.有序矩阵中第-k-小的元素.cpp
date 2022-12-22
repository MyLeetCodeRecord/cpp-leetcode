/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        // 第一维: 元素值
        // 第二维: 行列位置
        priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq;
        for(int j=0; j<n; j++){  // 先加入第一行
            pq.push({matrix[0][j], {0, j}});
        }
        vector<int> ans;
        while(ans.size()<k){    // 本题k有范围, 不必对pq判空
            ans.push_back(pq.top().first);
            PII pos = pq.top().second;
            int i = pos.first;
            int j = pos.second;
            pq.pop();
            if(i+1 < n)
                pq.push({matrix[i+1][j], {i+1, j}});  // 加入被弹出元素下方的元素
        }
        return ans.back();
    }
};
// @lc code=end

