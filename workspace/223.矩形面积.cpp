/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1) * (ay2-ay1);
        int area2 = (bx2-bx1) * (by2-by1);
        // 无重叠更好判断
        if(ay1>=by2 || by1>=ay2 || ax2<=bx1 || bx2<=ax1){
            return area1 + area2;
        }
        else{
            int unionArea = abs(min(ay2, by2)-max(ay1, by1)) * abs(min(ax2, bx2)-max(ax1, bx1));
            return area1 + area2 - unionArea;
        }
    }
};
// @lc code=end

