/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution {
public:
    // 相向双指针
    // 看最重的能否跟最轻的一起走, 如果可以则拼车, 如果不行则单独发车
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int ans = 0;
        int l = 0, r = n-1;
        while(l < r){
            if(people[l]+people[r] <= limit){
                ans++;
                l++;
                r--;
            }
            else{
                ans++;
                r--;
            }
        }
        if(l==r)        // 可能会剩下一个
            ans++;
        return ans;
    }
};
// @lc code=end

