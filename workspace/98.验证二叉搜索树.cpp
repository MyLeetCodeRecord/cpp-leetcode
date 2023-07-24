/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
class Solution {
public:
    long long pre = -1e18;
    bool inorder(TreeNode* root){
        if(root==NULL)
            return true;
        if(inorder(root->left)==false)
            return false;
        if(root->val <= pre)
            return false;
        pre = root->val;
        if(inorder(root->right)==false)
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};
// @lc code=end

