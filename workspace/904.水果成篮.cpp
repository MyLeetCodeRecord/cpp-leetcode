/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0;
        int left = 0;
        int right = 0;
        while(right < fruits.size()){
            if(mp.size() < 2 || mp.find(fruits[right])!=mp.end()){
                ans = max(ans, right-left+1);
                mp[fruits[right++]]++;
            }
            else if(left<right && mp.find(fruits[left])!=mp.end() ){
                if(mp[fruits[left]]==1){
                    mp.erase(fruits[left++]);
                }
                else{
                    mp[fruits[left++]]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

