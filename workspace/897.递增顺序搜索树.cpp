/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 */

// @lc code=start
class Solution {
public:
    TreeNode* cur;
    void inorder(TreeNode* root){
        if(root==NULL)
            return ;
        inorder(root->left);
        cur->right = root;
        cur = cur->right;
        root->left = NULL;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyHead = new TreeNode();
        cur = dummyHead;
        inorder(root);
        return dummyHead->right;
    }
};
// @lc code=end

