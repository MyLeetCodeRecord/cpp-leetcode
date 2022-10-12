/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

// @lc code=start
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);
        int cnt = 0;
        while(head != NULL){
            // 外层要加一个if, 防止nums中不存在但是cnt计数的情况发生
            if(st.find(head->val)!=st.end()){
                while(head!=NULL && st.find(head->val)!=st.end()){
                    head = head->next;
                }
                cnt++;
            }
            else{
                head = head->next;
            }
        }
        return cnt;
    }
};
// @lc code=end

