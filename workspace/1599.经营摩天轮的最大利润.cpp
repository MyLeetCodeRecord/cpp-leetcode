/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int b, int r) {
        int n = customers.size();
        int bestTime = -1;
        int maxProfix = 0;
        int profit = 0;
        int rest = 0;
        int time = 0;       // n组用户全都到达后time仍可以增加
        while(time<n || rest>0){
            rest += (time<n) ? customers[time] : 0;
            profit += (min(rest, 4) * b - r);   // 一定是尽可能多的游客在同一个包厢里最节省运营成本
            rest = max(rest-4, 0);
            time++;
            if(profit > maxProfix){
                bestTime = time;
                maxProfix = profit;
            }
        }
        return bestTime;
    }
};
// @lc code=end

