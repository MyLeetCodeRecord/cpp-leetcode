/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
class Solution {
public:
    // 和「大整数加法」类似
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        int t = 0;
        while(a!=NULL || b!=NULL){
            if(a != NULL){
                t += a->val;
                a = a->next;
            }
            if(b != NULL){
                t += b->val;
                b = b->next;
            }
            cur->next = new ListNode(t%10);
            cur = cur->next;
            t /= 10;
        }
        // 注意最高位进位
        if(t != 0)
            cur->next = new ListNode(t);
        return dummyHead->next;
    }
};
// @lc code=end

