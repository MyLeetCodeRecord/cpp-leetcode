/*
 * @lc app=leetcode.cn id=1801 lang=cpp
 *
 * [1801] 积压订单中的订单总数
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII, vector<PII>, less<PII>> buy_pq;
        priority_queue<PII, vector<PII>, greater<PII>> sell_pq;
        for(vector<int> order : orders){
            if(order[2]==0){
                while(order[1]>0 && !sell_pq.empty() && sell_pq.top().first <= order[0]){
                    PII sell = sell_pq.top();
                    sell_pq.pop();
                    if(order[1] >= sell.second){
                        order[1] -= sell.second;
                    }
                    else{
                        sell_pq.push({sell.first, sell.second-order[1]});
                        order[1] = 0;
                    }
                }
                if(order[1] > 0)
                    buy_pq.push({order[0], order[1]});
            }
            else if(order[2]==1){
                while(order[1]>0 && !buy_pq.empty() && buy_pq.top().first >= order[0]){
                    PII buy = buy_pq.top();
                    buy_pq.pop();
                    if(order[1] >= buy.second){
                        order[1] -= buy.second;
                    }
                    else{
                        buy_pq.push({buy.first, buy.second-order[1]});
                        order[1] = 0;
                    }
                }
                if(order[1] > 0)
                    sell_pq.push({order[0], order[1]});
            }
        }
        long long ans = 0;
        while(!buy_pq.empty()){
            PII b = buy_pq.top();
            buy_pq.pop();
            ans += b.second;
            ans %= 1000000007;
        }
        while(!sell_pq.empty()){
            PII s = sell_pq.top();
            sell_pq.pop();
            ans += s.second;
            ans %= 1000000007;
        }
        return ans;
    }
};
// @lc code=end

