/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

// @lc code=start
class Solution {
public:
    /* 交换规则: L无法穿过R, R也无法穿过L
     * 使用双指针 i 和 j 遍历 start 和 end
     * - 「start中的L落后 & L无法右移」 or 「start中的R领先 & R无法左移」 => return false
     * - 如果去掉start和end中的所有X, 剩下的字符应该相同 => i, j同时到达终点(非X字符数量相同)
     */
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while(1){
            while(i < n && start[i] == 'X')
                i++;
            while(j < n && end[j] == 'X')
                j++;
            if(i == n && j == n)
                return true;
            if(i == n || j == n || start[i]!=end[j])
                return false;
            // start中的L落后 & 无法右移
            if(start[i] == 'L' && i < j)
                return false;
            // start中的R领先 & 无法左移
            if(start[i] == 'R' && i > j)
                return false;
            i++;
            j++;
        }
    }
};
// @lc code=end

