/*
 * @lc app=leetcode.cn id=1367 lang=cpp
 *
 * [1367] 二叉树中的链表
 */

// @lc code=start
class Solution {
public:
    bool verifyPath(ListNode* head, TreeNode* root){
        if(head==NULL)
            return true;
        if(root==NULL)
            return false;
        if(head->val != root->val)
            return false;
        else
            return verifyPath(head->next, root->left) || verifyPath(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL)
            return false;
        if(verifyPath(head, root))
            return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
// @lc code=end

