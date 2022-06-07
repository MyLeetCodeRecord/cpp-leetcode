/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    // letters有序
    char nextGreatestLetter(vector<char>& letters, char target) {
        // 提前处理target是last one的情况
        if(target >= letters[letters.size()-1])
            return letters[0];
        // 二分, 注意是对下标二分
        int left = 0;
        int right = letters.size()-1;
        while(left<=right){
            int mid = (right-left)/2+left;
            if(letters[mid] <= target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return letters[left];
    }
};
// @lc code=end

