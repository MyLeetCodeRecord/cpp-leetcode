/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    vector<int> stock;
    int idx = 0;
    stack<int> sk;

    StockSpanner() {
    }
    
    int next(int price) {
        stock.push_back(price);
        while(!sk.empty() && price >= stock[sk.top()]){
            sk.pop();
        }
        int ans = idx- (sk.empty() ? -1 : sk.top());
        sk.push(idx++);
        return ans;
    }
};
// @lc code=end

