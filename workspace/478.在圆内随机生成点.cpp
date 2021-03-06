/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */

// @lc code=start
class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    vector<double> randPoint() {
        double xx = 1;
        double yy = 1;
        // 直到 a^2+b^2 <= r^2
        do {
            // 2.0: 作用一是double, 作用二是结合-1达到正负的效果
            xx = 2.0*rand()/RAND_MAX - 1;
            yy = 2.0*rand()/RAND_MAX - 1;
        } while(xx*xx + yy*yy > 1);
        return {x + r*xx, y + r*yy};
    }
};
// @lc code=end

