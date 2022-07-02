/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution {
public:
    // "油我是要带走的，至于用不用，看情况咯"
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // priority_queue: 保证油量不足以到达下一站时, 先加carry的油桶中油量最多的
        priority_queue<int> pq;
        stations.push_back({target, 0});
        int ans = 0;
        int fuel = startFuel;
        int cur = 0;
        for(int i=0; i<stations.size(); i++){
            // 不足以到达stations[i][0]时, 可能加油不止一桶油
            while(fuel < stations[i][0] - cur){
                if(pq.empty())
                    return -1;
                fuel += pq.top();
                pq.pop();
                ans++;
            }
            pq.push(stations[i][1]);
            fuel -= (stations[i][0]-cur);
            cur = stations[i][0];
        }
        return ans;
    }
};
// @lc code=end

