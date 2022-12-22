/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly;
        ugly.push_back(1);
        int i=0, j=0, k=0;
        while(ugly.size() < n){
            // 避免重复并正确移动指针的方式, 可以逆向思考
            // 先找到最小值, 后移指向这个最小值的所有指针
            int minVal = min(ugly[i]*2, min(ugly[j]*3, ugly[k]*5));
            ugly.push_back(minVal);
            // 指针是在丑数数组上移动的, 所以是++, 而不是翻倍
            if(ugly[i]*2==minVal)
                i++;
            if(ugly[j]*3==minVal)
                j++;
            if(ugly[k]*5==minVal)
                k++;
        }
        return ugly.back();
    }
};
// @lc code=end

