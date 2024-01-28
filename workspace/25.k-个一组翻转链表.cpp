/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
class Solution {
public:
    pair<ListNode*, ListNode*> reverseSingle(ListNode* head, ListNode* tail){
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(pre != tail){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        while(head != NULL){
            ListNode* tail = pre;
            for(int i=0; i<k; i++){
                tail = tail->next;
                if(tail == NULL)
                    return dummy->next;
            }
            ListNode* next = tail->next;
            // 翻转后新的head & tail
            pair<ListNode*, ListNode*> rev = reverseSingle(head, tail);
            head = rev.first;
            tail = rev.second;
            // 更新翻转链表左右两边的指针
            pre->next = head;
            tail->next = next;
            // 移动pre & head(cur)
            pre = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};
// @lc code=end

