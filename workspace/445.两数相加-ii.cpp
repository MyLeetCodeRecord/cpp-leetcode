/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

// @lc code=start
// 方法一: 栈
// 方法二: 链表反转
class Solution {
public:
    // "💪💪对于逆序处理应该首先想到栈，对吧？😎"
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> sk1;
        stack<int> sk2;
        while(l1 != NULL){
            sk1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            sk2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* cur = NULL;
        int carry = 0;
        while(!sk1.empty() || !sk2.empty()){
            if(!sk1.empty()){
                carry += sk1.top();
                sk1.pop();
            }
            if(!sk2.empty()){
                carry += sk2.top();
                sk2.pop();
            }
            ListNode* pre = new ListNode(carry % 10);
            pre->next = cur;
            cur = pre;
            carry /= 10;
        }
        if(carry != 0){
            ListNode* pre = new ListNode(carry);
            pre->next = cur;
            cur = pre;
        }
        return cur;
    }
};
// @lc code=end

