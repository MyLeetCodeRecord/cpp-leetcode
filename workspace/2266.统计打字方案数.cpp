/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 *
 * [2266] 统计打字方案数
 */

// @lc code=start
class Solution {
public:
    int countTexts(string pressedKeys) {
        // 最小设为4, 方便初始化
        int len = pressedKeys.size()>=4 ? pressedKeys.size() : 4;
        vector<long long> dp_79(len+1, 0);
        vector<long long> dp_others(len+1, 0);
        
        dp_79[1] = 1;   dp_others[1] = 1;
        dp_79[2] = 2;   dp_others[2] = 2;
        dp_79[3] = 4;   dp_others[3] = 4;
        dp_79[4] = 8;
        
        // 计算状态转移方程时注意每一步加法都可能溢出（罚时++）
        // 1e9+7: 也没什么明确含义, 应该就是一个很大的质数
        for(int i=5; i<=len; i++){
            dp_79[i] = (((((dp_79[i-1] + dp_79[i-2]) % ((int)1e9+7)) + dp_79[i-3]) %((int)1e9+7)) + dp_79[i-4]) % ((int)1e9+7);
            dp_79[i] = dp_79[i] % ((int)1e9+7);
        }
        for(int i=4; i<=len; i++){
            dp_others[i] = (((dp_others[i-1] + dp_others[i-2]) % ((int)1e9+7)) + dp_others[i-3]) % ((int)1e9+7);
        }
        
        long long ans = 1;
        // 处理*每段连续相同的按键*
        for(int i=0; i<pressedKeys.size(); ){
            char ch = pressedKeys[i];
            int sameLen = 1;
            while(ch == pressedKeys[i+sameLen]){
                sameLen++;
            }
            int cur = (ch=='7' || ch=='9') ? dp_79[sameLen] : dp_others[sameLen];
            // 乘法也要注意溢出（罚时++）
            ans *= cur % ((int)1e9+7);
            ans = ans % ((int)1e9+7);
            i = i+sameLen;
        }
        return ans % ((int)1e9+7);
    }
};
// @lc code=end

