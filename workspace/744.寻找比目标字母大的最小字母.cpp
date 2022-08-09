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
        if(target >= letters.back())
            return letters[0];
        // 二分, 注意是对下标二分
        int l = 0;
        int r = letters.size()-1;
        while(l < r){
            int mid = (l+r+1)/2;
            if(letters[mid] > target)
                r = mid-1;
            else
                l = mid;
        }
        while(l<letters.size() && letters[l]<=target)
            l++;
        return letters[l];
    }
};
// @lc code=end

