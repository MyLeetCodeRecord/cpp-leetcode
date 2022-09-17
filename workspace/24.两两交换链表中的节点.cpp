/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
class Solution {
public:
    // https://code-thinking.cdn.bcebos.com/pics/24.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B91.png
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* cur = dummyHead;
        while(cur->next!=NULL && cur->next->next!=NULL){
            ListNode* next_1 = cur->next;
            ListNode* next_2 = cur->next->next;
            cur->next = next_2;
            next_1->next = next_2->next;
            next_2->next = next_1;
            cur = next_1;
        }
        return dummyHead->next;
    }
};
// @lc code=end

