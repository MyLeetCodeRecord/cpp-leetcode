/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int l = 1;
        int r = x;
        while(l<r){
            long long mid = (r-l+1)/2+l;
            if(mid > x/mid)
                r = mid-1;
            else
                l = mid;
        }
        return l;
    }
};
// @lc code=end

