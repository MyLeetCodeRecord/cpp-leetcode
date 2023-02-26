/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        // 大顶堆
        priority_queue<tuple<double, int, int>> pq;
        double sum = 0.0;
        for(auto &cls: classes){
            int u = cls[0];
            int d = cls[1];
            sum += (double)u/d;
            double delta = (double)(u+1)/(d+1) - (double)u/d;
            pq.push({delta, u, d});
        }
        for(int i=0; i<extra; i++){
            auto [delta, u, d] = pq.top();
            pq.pop();
            sum += delta;
            u++;
            d++;
            delta = (double)(u+1)/(d+1) - (double)u/d;
            pq.push({delta, u, d});
        }
        return sum / classes.size();
    }
};
// @lc code=end

