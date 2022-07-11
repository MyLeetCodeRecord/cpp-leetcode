/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution {
public:
    // 偶数->偶数位置不需要代价, 奇数到奇数位置不需要代价
    // 偶数位置evenCnt与奇数位数oddCnt比较, 更少的一个就是移动次数
    int minCostToMoveChips(vector<int>& position) {
        int oddCnt = 0;
        int evenCnt = 0;
        for(int p : position){
            if(p % 2 == 0)
                evenCnt++;
            else
                oddCnt++;
        }
        return min(evenCnt, oddCnt);
    }
};
// @lc code=end

