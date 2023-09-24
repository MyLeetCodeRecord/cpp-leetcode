/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

// @lc code=start
class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0));
    }
    int getRandom() {
        ListNode* cur = head;
        int ans = head->val;
        int k = 1;
        while(cur != NULL){
            if(rand() % (k++) == 0)
                ans = cur->val;
            cur = cur->next;
        }
        return ans;
    }
};
// @lc code=end

