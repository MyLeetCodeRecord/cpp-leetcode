/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        while(cur!=NULL){
            if(cur->val==val){
                pre->next = cur->next;
                cur = pre->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
    // 单指针 (有点慢, 可能是因为一直next->next)
    ListNode* removeElement_single(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pre = dummyHead;
        while(pre!=NULL && pre->next!=NULL){
            if(pre->next->val==val){
                pre->next = pre->next->next;  // 修改pre->next后, pre要原地踏步
            }
            else{
                pre = pre->next;
            }
        }
        return dummyHead->next;
    }
};
// @lc code=end

