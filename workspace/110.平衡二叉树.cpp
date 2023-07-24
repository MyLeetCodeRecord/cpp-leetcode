/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
class Solution {
public:
    int getHeight(TreeNode* root){
        if(root==NULL)
            return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(abs(l-r) > 1 || l==-1 || r==-1)
            return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) >= 0;
    }
};
// @lc code=end

