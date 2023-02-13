/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
 */

// @lc code=start
class Solution {
public:
    int getSize(TreeNode* root){
        if(root==NULL)
            return 0;
        int left = getSize(root->left);
        int right = getSize(root->right);
        return left + right + 1;
    }
    TreeNode* findNode(TreeNode* root, int x){
        if(root==NULL || root->val==x)
            return root;
        TreeNode* left = findNode(root->left, x);
        TreeNode* right = findNode(root->right, x);
        return (left!=NULL) ? left : right;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* red = findNode(root, x);
        int l_size = getSize(red->left);
        int r_size = getSize(red->right);
        int rest_size = n - l_size - r_size - 1;
        int b_size = max(rest_size, max(l_size, r_size));
        return b_size > (n-b_size);
    }
};
// @lc code=end

