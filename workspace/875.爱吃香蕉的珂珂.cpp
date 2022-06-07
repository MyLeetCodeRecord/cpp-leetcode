/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int getTime(vector<int>& piles, int k){
        int sum = 0;
        for(int pile: piles){
            sum += pile/k + (pile%k!=0);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;

        while(left < right){
            int mid = (right-left)/2 + left;
            if(getTime(piles, mid) <= h){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

