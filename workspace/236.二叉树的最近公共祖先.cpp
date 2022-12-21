/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root==p || root==q)
            return root;
        // 分别检查left, right是否含有p, q中的一个或者两个(几个不重要)
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l!=NULL && r!=NULL)
            return root;
        if(l!=NULL)
            return l;
        else
            return r;
    }
};
// @lc code=end

