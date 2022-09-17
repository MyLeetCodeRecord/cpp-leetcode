/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        do{
            if(fast!=NULL && fast->next!=NULL)
                fast = fast->next->next;
            else
                return NULL;
            slow = slow->next;
        } while(fast!=slow);
        fast = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
// @lc code=end

