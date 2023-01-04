/*
 * @lc app=leetcode.cn id=1802 lang=cpp
 *
 * [1802] 有界数组中指定下标处的最大值
 */

// @lc code=start
class Solution {
public:
    // 贪心: 选定index下标的值后, 应该尽可能递减(减少到1后, 设为全1)
    // 二分: 用来「选定index下标的值」, 合法范围内越大越好, 因此用「右端点模板」
    int len, idx, limit;
    long long check(int h, int w){
        // e.g. h=4, w=2  =>  2 3 4
        if(h-1 >= w)
            return (long long)(2*h-w) * (w+1) / 2;
        // e.g. h=2, w=2  =>  1 1 2
        else
            return (long long)(h+1) * h / 2 + (w-h+1);
    }
    int binarysearch_right(int l, int r){
        if(l >= r)
            return l;
        while(l < r){
            long long mid = (l+r+1)/2;
            // 左侧sum + 右侧sum - 重复累加的mid
            if(check(mid, idx) + check(mid, len-idx-1) - mid > limit)
                r = mid-1;
            else
                l = mid;
        }
        return r;
    }
    int maxValue(int n, int index, int maxSum) {
        len = n;
        idx = index;
        limit = maxSum;
        return binarysearch_right(1, maxSum);
    }
};
// @lc code=end

