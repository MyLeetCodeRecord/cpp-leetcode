/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[2];
        for (int student : students)
            cnt[student]++;
        for (int sandwich : sandwiches) {   // 消耗学生, 直到没有人喜欢栈顶sandwiches则看剩多少
            if (cnt[sandwich] > 0) 
                cnt[sandwich]--;
            else
                break;
        }
        return cnt[0] + cnt[1];
    }
};
// @lc code=end

