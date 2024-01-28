/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(ListNode* node: lists){
            if(node != NULL)
                pq.push({node->val, node});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while(!pq.empty()){
            ListNode* cur = pq.top().second;
            pq.pop();
            ptr->next = cur;
            ptr = ptr->next;
            if(cur->next != NULL)
                pq.push({cur->next->val, cur->next});
        }
        return dummy->next;
    }
};
// @lc code=end

