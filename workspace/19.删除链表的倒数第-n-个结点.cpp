/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next!=NULL)
            slow->next = slow->next->next;
        return dummyHead->next;
    }
};
// @lc code=end

