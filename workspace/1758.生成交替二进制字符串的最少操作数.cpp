/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(string s) {
        for(int i=0; i<s.size()-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i+1] = (nums[i]=='0')?'1':'0';
                cnt++;
            }
        }
        return min(cnt, s.size()-cnt);
    }
};
// @lc code=end

