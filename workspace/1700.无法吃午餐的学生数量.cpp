/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int q_pointer = 0;
        int s_pointer = 0;
        int dislike = 0;
        while(q_pointer != students.size()){
            if(dislike == sandwiches.size() - s_pointer)
                break;
            if(students[q_pointer]==sandwiches[s_pointer]){
                q_pointer++;
                s_pointer++;
                dislike = 0;
            }
            else{
                dislike++;
                students.push_back(students[q_pointer++]);
            }
        }
        return dislike;
    }
};
// @lc code=end

