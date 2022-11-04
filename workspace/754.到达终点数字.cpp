/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

// @lc code=start
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int i = 0;
        while(sum < target){
            i++;
            sum += i;
        }
        // Case 1: 恰好到达target
        if(sum==target)
            return i;
        else{
            // Case 2: 多出一个偶数
            if((sum-target) % 2 == 0)
                return i;
            // Case 3: 多出一个奇数
            else{
                // 下一个数是奇数, ans+=2; else ans+=1
                return i+1+(i%2==1);
            }
        }
        return i;
    }
};
// @lc code=end

