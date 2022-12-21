/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val)
            return root;
        // 分别在两边
        if((root->val>p->val && root->val<q->val) || (root->val<p->val && root->val>q->val))
            return root;
        // 借助BST的性质, 只递归一边
        if(root->val > p->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};
// @lc code=end

