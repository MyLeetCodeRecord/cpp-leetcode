/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx = 1;
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* stage1 = dummyHead;
        for(idx=1; idx<left; idx++){
            stage1 = stage1->next;
        }
        ListNode* start = stage1->next;
        ListNode* pre = NULL;
        ListNode* cur = start;
        while(idx<=right && cur!=NULL){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            idx++;
        }
        stage1->next = pre;
        start->next = cur;
        return dummyHead->next;
    }
};
// @lc code=end

